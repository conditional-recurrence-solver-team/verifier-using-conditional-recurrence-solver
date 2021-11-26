extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}
#define a (2)
extern unsigned int __VERIFIER_nondet_uint();
int main() { 
  int i, n=__VERIFIER_nondet_uint(), sn=0;
  for(i=0; i<=n; i++) {
    sn = sn + 2;
    if (i==4) sn=-10;
  }
  __VERIFIER_assert(sn==n*2 || sn == 0);
}
