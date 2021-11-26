// WARNING: The files in this directory have not been extensively tested
//   and may be incorrect. --JTB

void main() {
    int d;
    int s;
    int N = __VERIFIER_nondet_int();
    if (s != 1) return 0;
    for(int t = 0; t < N; t++) {
        if (s == 1) {
            d = - d;
            s = d * d;
        } else {
            d = 5;
            s = d * d;
        }
    }
    __VERIFIER_assert(s == 1);
}
