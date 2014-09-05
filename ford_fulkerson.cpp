
typedef int FLOWT;
class Edge{
  public:
  int start,end;
  FLOWT flow,capacity;
  FLOWT reserve_to(int target) {
    if(target==end) {
      return capacity-flow;
    } else {
      return flow;
    }
  }
  FLOWT reserve_from(int source) {
    if(source==start) {
      return capacity-flow;
    } else {
      return flow;
    }
  }
  int next(int current) {
    if (current==start) return end;
    return start;
  }
  void add_from(int current, FLOWT value) {
    if(current==start) {
      flow+=value;
    }else flow-=value;
  }
};
class FlowGraph{
  public:
    int n;
    vector<Edge> E;
    vector<vector<int > >edges;    
    vector<int> seen;
    FlowGraph(int n) {
      this->n = n;
      edges=vector<vector<int> > (n);
    }
    void addedge(int start, int end, FLOWT capacity) {
      Edge e;
      e.start= start;
      e.end= end;
      e.capacity = capacity;
      e.flow = 0;
      E.push_back(e);
      int a=E.size()-1;
      edges[start].push_back(a);
      edges[end].push_back(a);
    }
    FLOWT augment_flow(int node, int sink, int limit){
      if(seen[node]) return 0;
      if(node == sink) return limit;
      seen[node] = 1;
      REP(i,edges[node].size()) {
        Edge &edge(E[edges[node][i]]);
        const int &next(edge.next(node));

        FLOWT flow=min(limit, edge.reserve_to(next));
        if(flow>0) {
          flow = augment_flow(next, sink, flow);
          if (flow>0) {
            edge.add_from(node, flow);
            return flow;
          }
        }
      }
      return 0;

    }
    FLOWT get_max_flow(int start, int end) {
      FLOWT return_value=0;
      while(1) {
        seen=vector<int>(n);
        FLOWT increment=augment_flow(start,end, 1000);
        if(increment<=0) break;
        return_value += increment;

      }
      return return_value;
    }

    // Commutes maximum flow in graph using dinic algorithm, that does so by finding blocking flow all the time,
    // Blocking flow is such flow that there is no possible augmenting path of given length.
    FLOWT get_max_flow_dinic(int source,int sink) {
      FLOWT res=0;
      while(1) {
        queue<int> q;
        vector<int> distance(n,-1);
        distance[source]=0;
        q.push(source);
        // Construct layered graph
        while(!q.empty()) {
          int node=q.front();
          q.pop();
          REP(i,edges[node].size()) if(edges[node][i]->reserve_from(node)>0) {
            int next=edges[node][i]->next(node);
            if(distance[next]==-1) {  // Has not been visited
              distance[next]=distance[node]+1;
              q.push(next);
            }
          }
        }

        if(distance[sink]==-1) break;  // There is no augmentig path
        //Find blocking flow 

        vector<int> path(1,source);  // Current path, 
        vector<FLOWT> reserves(1, 10000000);
        vector<int> next(n,0); // First not tried edge in graph for given node
        while(!path.empty()) {
           
          int t=path.back();  // t: last node on path

          // If node is exhausted abbandon it (step back)
          if(next[t]==(int)edges[t].size()) {  
            path.resize(path.size()-1);
            if(path.empty()) break;
            next[path.back()]++;
            continue;
          }

          // Go forward or augment path
          FLOWT reserve = min(reserves.back(),graf[t][next[t]]->res(t))
          if(reserve > 0) {  // is there cpacity follow
            int s=graf[t][next[t]]->sused(t);  // s: candidate for path extension
            if(s==target) {  // Found target, so augment flow according given path, 
                             // and start search of path over again, also advance pointer for next node in nodes
              result += reserve;
              REP(i,path.size()) {
                edges[path[i]][next[path[i]]]->add_from(path[i],reserve); // compute maximal possible reserve
                if(graf[path[i]][next[path[i]]]->res(path[i])==0) next[path[i]]++;
              }
              path.resize(1);
              reserves.resize(1);
            } else if(distance[s]-distance[t]==1 && next[s]!=(int)graf[s].size()) {
              path.push_back(s); //next level and node has some unclosed edges
              reserves.push_back(reserve);
            } else {
              next[t]++;  // next edge
            }
          } 
          else {
            next[t]++; // next edge
          }
        }
      }
      return result;

    }

};
