// The Reachability-Bound Problem
int main() {
  int n;
  int x;
  int z;
  int x0 = x;
  int z0 = z;
  if (n <= 0 || x >= n) return 0;
  while (x < n) {
    if (z > x) {
      x = x + 1;
    } else {
      z = z + 1;
    }
  }
    __VERIFIER_assert(z >= x);
}