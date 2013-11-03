
typedef int FLOWT;
class Edge{
  int start,end;
  FLOWT flow,capacity;
};
class FlowGraph{
  public:
    int n;
    vector<Edge> E;
    vector<vector<int > >edges;    
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
    

};
