extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "sumt7.c", 3, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}
int __VERIFIER_nondet_int();
int main() {
  int SIZE = 20000001;
  unsigned int n=0;
  unsigned int i=0;
  unsigned int k=0;
  unsigned int j=0;
  unsigned int l=0;
  unsigned int v1=0;
  unsigned int v2=0;
  unsigned int v3=0;
  unsigned int v4=0;
  n = __VERIFIER_nondet_int();
  if (!(n <= SIZE)) return 0;
  while( l < n ) {
	
	  if(l%7 == 0)
	    v1 = v1 + 1;
	  else if(l%6 == 0)
	    v2 = v2 + 1;
	  else if(l%5 == 0)
	    v3 = v3 + 1;
	  else if(l%4 == 0)
	    v4 = v4 + 1;
	  else if(l%3 == 0)
	    i = i + 1;
	  else if(l%2 == 0) 
		  j = j+1;
	  else 
	    k = k+1;
    l = l+1;
    __VERIFIER_assert((i+j+k+v1+v2+v3+v4) == l);
  }
  return 0;
}

