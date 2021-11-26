void main()
{
    int p;
    int q;
    if (!(p >= 0 && q >= 0 && q < p)) return 0;
  int x=0; 
  int y=q;
  while(x<p) {
    x++;
    if(x>q) y++;
  }
  __VERIFIER_assert(y==p);
}
