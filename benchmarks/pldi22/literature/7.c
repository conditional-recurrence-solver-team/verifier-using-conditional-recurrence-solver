void main()
{
  int n;
  int x=0;
  int y=0;
  int i=0;
  while(i<n) {
    i++;
    x++;
    if(i%2 == 0) y++;
  }
  
  __VERIFIER_assert(x==2*y || x == 2*y + 1);
}

