// WARNING: The files in this directory have not been extensively tested
//   and may be incorrect. --JTB

void main() {
    int a;
    int b;
    int N;
    if (a + b != 4) return 0;
    for(int t = 0; t < N; t++) {
        a = 1 - a;
        if (a == 1) {
            b = b - 1;
        } else if (a == 0) {
            b = b + 1;
        } else {
            a = 1 - a;
        }
    }
    __VERIFIER_assert(a + b == 4);
}
