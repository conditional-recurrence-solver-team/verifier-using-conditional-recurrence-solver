int main() { 
  int i, n=__VERIFIER_nondet_uint(), sn=0;
  for(i=0; i<=n; i++) {
    sn = sn + 2;
    if (i==4) sn=-10;
  }
  __VERIFIER_assert(sn==n*2 || sn == 0);
}
