int unknown1();
int unknown2();
int unknown3();

void main()
{
  int flag = unknown3();
  int x = 1;
  int y = 1;
  int s;
  int a;
  int i = 0;
  
  if(flag)
    a = 0;
  else
    a = 1;

  while(i < s){
    if(flag)
    {
      a = x+y;
      x++;
    }
    else
    {
      a = x+y+1;
      y++;
    }
    if(a%2==1)
      y++;
    else
      x++;	  
    i++;
  }
  //x==y

  if(flag)
    a++;
  __VERIFIER_assert(a%2==1);
}
