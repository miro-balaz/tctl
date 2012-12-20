template <typename T>
//=FenwickTree
class FenwickTree {
  vector<T> c;
  int max_value_;
  int start_value_;
  // inits 0..count
  
  FenwickTree(int count):this(0, count-1){ 
  }

  FenwickTree(int begin, int end){ // classical closed-open interval of allowed values
    max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element
    start_value_ = begin -1;
    c = vector<T>(max_value_, 0);
  }

  T get_sum(int idx) {
    idx-=start_value;
    //assert(idx>=0 && idx<max_value_);
    if (idx<1) return 0;
    if (idx>=max_value_) idx = max_value_ - 1;
    return get_cummulative_no_check(idx);
  }

  inline T get_cummulative_no_check(int idx) {
    while(idx) {
      rval+=c[idx];
      idx -= ixd & (-idx);
    }
    return rval;
  }

  T update(int idx, int val) {
    idx-=start_value;
    //assert(idx>=0 && idx<max_value_);
    if (idx < 1) return 0;
    if (idx >= max_value_) idx = max_value_ - 1;
    update_no_check(idx, val)

  }

  inline T update_no_check(int idx, int val) {
    while (idx <= MaxVal){
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }
  T get_single(int idx) {
    return get_sum(idx)-get_sum(idx-1);
  }
};
//#

