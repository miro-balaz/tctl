ll modexp(ll a, ll ex) {
  ll res=1;
  ll y=a;
  while(ex) {
    if(ex&1)  {
      res=(res*y)%M;
    }
    ex/=2;
    if(ex)y=(y*y)%M;
  }
  return res;
}

