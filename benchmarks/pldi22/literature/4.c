void main()
{
   int i;
   int j;
   int k;
   int s1;
   int s2;
   int is1 = 0;
   int is2 = 0;
   int flag;
   j = 1;
   if(flag) {i=0;}
   else {i=1;}
   

   while(is1 < s1) {
      i+=2;
      if(i%2 == 0) {
	      j+=2;
         is1++;
      } else {
         j++;
         is1++;
      }
   } 
   
   int a = 0;
   int b=0;
   
   while(is2 < s2) {
      a++;      
      b+=(j-i); 
      is2++;
   }
   if(flag)
     __VERIFIER_assert(a==b);
}

