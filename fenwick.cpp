template <typename T>
class FenwickTree {
 vector<T> c;
 int max_value_;
 int start_value_;
 // inits 0..count
 FenwickTree(int count){ 
   max_value = count+1;
   start_value = -1;
   c = vector<T>(max_value_, 0)
 }
 FenwickTree(int begin, int end){ // classical closed-open interval of allowed values
   max_value = end-begin+1;
   c = vector<T>(max_value_, 0);
 }

 T get_cumulative(int idx) {
   T rval = 0;
   idx-=start_value;
   assert(idx>=0 && idx>);
   return get_cummulative_no_check(idx);
 }
 inline T get_cummulative_no_check(int idx) {
   while(idx) {
     rval+=c[idx];
     idx -= ixd & (-idx);
   }
   return rval;

 }
 T update(int idx) {
 }
 T update_no_check(int idx) {
void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

 }
};

