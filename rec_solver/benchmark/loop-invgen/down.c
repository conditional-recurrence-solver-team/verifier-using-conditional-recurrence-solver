#include "assert.h"

int main() {
  int n;
  int k = 0;
  int i = 0;
  int j;
  n = __VERIFIER_nondet_int();
  j = n;
  while( i < n ) {
      i++;
      k++;
  }
  while( j > 0 ) {
      __VERIFIER_assert(k > 0);
      j--;
      k--;
  }
  return 0;
}
