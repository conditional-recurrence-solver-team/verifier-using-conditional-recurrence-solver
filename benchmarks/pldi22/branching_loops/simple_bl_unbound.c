// WARNING: The files in this directory have not been extensively tested
//   and may be incorrect. --JTB

void main() {
    int d = 1;
    int N = __VERIFIER_nondet_int();
    for(int t = 0; t < N; t++) {
        if (d*d == 1) {
            d = - d;
        } else {
            d = 5;
        }
    }
    __VERIFIER_assert(d == 1 || d == -1);
}
