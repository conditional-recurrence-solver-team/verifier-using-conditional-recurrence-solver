int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main()
{


	int w = 1;
	int z = 0;
	int x= 0;
	int y=0;
	int i = 0;
	int s;

	  
         while(x < LARGE_INT && y < LARGE_INT && i < s){
	    if(w%2 == 1) {x++; w++;}
	    if(z%2==0) {y++; z++;}
		i++;
	}

  
	__VERIFIER_assert(x<=1);
}

