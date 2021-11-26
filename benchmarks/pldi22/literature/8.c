void main() {
  int k;
  int b;
  int i;
  int j;
  int m;
  i = j;
  for( m = 0 ; m < 2*k ; m++ ) {
    if(b) {
      i++;
      b = 0;
    } else {
      j++;
      b = 1;
    }
    // b = !b;
  }
  if (k > 0)
  __VERIFIER_assert(i == j);
}
