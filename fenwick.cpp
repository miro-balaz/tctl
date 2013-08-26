//=FenwickTree
template<typename T>
class FenwickTree {
    public:
  vector<T> c;
  int max_value_;
  int start_value_;
  // inits 0..count
  
  FenwickTree(int count):FenwickTree(0, count-1){ 
  }

  FenwickTree(int begin, int end){ // closed-open interval of allowed values
    max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element
    start_value_ = begin -1; // valid entries as 1 .. max_value
    c = vector<T>(max_value_+1, 0);
  }

  T get_sum(int idx) {
    idx-=start_value_;
    if (idx<1) return 0;
    if (idx>max_value_) idx = max_value_;
    //assert(idx>=0 && idx<=max_value_);
    return get_cummulative_no_check(idx);
  }

  inline T get_cummulative_no_check(int idx) {
    T rval = 0;
    while(idx > 0) {
      //assert(idx<=max_value_);
      rval+=c[idx];
      idx -= idx & (-idx);
    }
    return rval;
  }

  void update(int idx, int val) {
    idx-=start_value_;
    if (idx < 1) return;
    if (idx > max_value_) idx = max_value_ ;
    //assert(idx>=0 && idx<=max_value_);
    update_no_check(idx, val);

  }

  inline void update_no_check(int idx, int val) {
    while (idx <= max_value_){
      //assert(idx>=0);
      c[idx] += val;
      idx += (idx & -idx);
    }
  }
  T get_single(int idx) {
    return get_sum(idx)-get_sum(idx-1);
  }
};
//#

