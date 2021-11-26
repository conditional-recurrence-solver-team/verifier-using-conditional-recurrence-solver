extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "sumt3.c", 3, "reach_error"); }
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
unsigned int __VERIFIER_nondet_uint();
int main() {
  int SIZE = 20000001;
  unsigned int n = __VERIFIER_nondet_uint();
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  unsigned int l=0;
  if (!(n <= SIZE)) return 0;
  while( l < n ) {
	
	  if(l%3 == 0)
	    i = i + 1;
	  else if(l%2 == 0) 
		  j = j+1;
	  else 
	    k = k+1;
    l = l+1;
  }
  __VERIFIER_assert(k <= i);
  return 0;
}