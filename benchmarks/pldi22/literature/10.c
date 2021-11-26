int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {


	int w = 1;
	int z = 0;
	int x= 0;
	int y=0;
	int s;
	int i =0;

 
         while(i < s){
	    if(w) {
		x++; 
		w=!w;
	    };
	    if(!z) {
		y++; 
		z=!z;
	    };
		i++;
	}

  
	__VERIFIER_assert(x==y);
  
}
