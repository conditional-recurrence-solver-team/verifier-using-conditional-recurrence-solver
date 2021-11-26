extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "vnew2.c", 3, "reach_error"); }
extern void abort(void);
unsigned int __VERIFIER_nondet_uint();
int main() {
  unsigned int n,i,k,j;
  int SIZE = 20000001;
  n = __VERIFIER_nondet_uint();
  if (!(n <= SIZE)) return 0;
  i = 0;
  j = 0;
  k = 0;
  while( i < n ) {
    i = i + 3;
    j = j+3;
    k = k+3;
  }
  if(n>0)
	  __VERIFIER_assert( i==j && j==k && (i%(SIZE+2) > 0) );
  return 0;
}

