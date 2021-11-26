// The Reachability-Bound Problem
int main() {
    int n;
    int m;
    int j;
    int j0 = j;
    int a = 0;
    if (!(n > 0 && n < m)) return 0;
    while (j < n || j > n) {
        if (j > m) {
            j = 0;
            a = 1;
        } else {
            j = j + 1;
        }
    }
    if (a == 1) {
      __VERIFIER_assert(j0 > n);
    }
}