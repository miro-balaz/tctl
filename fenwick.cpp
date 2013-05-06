template <typename T>
//=FenwickTree
class FenwickTree {
  vector<T> c;
  int max_value_;
  int start_value_;
  // inits 0..count
  
  public:
  FenwickTree(int begin, int end){ // classical closed-open interval of allowed values
    max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element ==n+2
    start_value_ = begin -1; //==-1
    c = vector<T>(max_value_, 0);
  }
  // allowed values will be 0 to count-1
//  FenwickTree(int count):FenwickTree(0, count){ 
 // }
  // Returns sum from begin to idx inclusively, if idx isoutside the bounds it will return 0 or sum for max value depending of the idx.
  T get_sum(int idx) {
    idx -= start_value_;
    //assert(idx>=0 && idx<max_value_);
    if (idx<1) return 0;
    if (idx>=max_value_) idx = max_value_ - 1;
    return get_sum_no_check(idx);
  }

  // The actual implementation of get_sum
  inline T get_sum_no_check(int idx) {
    int rval=0;
    while(idx) {
      rval += c[idx];
      idx -= idx & (-idx);
    }
    return rval;
  }
  // The actual implementation of add
  inline void add_no_check(int idx, T val) {
    while (idx < max_value_){
      c[idx] += val;
      idx += (idx & -idx);
    }
  }

  // increases the frequency for idx
  void add(int idx, T val) {
    idx-=start_value_;
    //assert(idx>=0 && idx<max_value_);
    if (idx < 1) return ;
    if (idx >= max_value_) idx = max_value_ - 1;
    add_no_check(idx, val);

  }

  // The slower version of getting value for single element
  T get_single(int idx) {
    return get_sum(idx)-get_sum(idx-1);
  }
};
//#

