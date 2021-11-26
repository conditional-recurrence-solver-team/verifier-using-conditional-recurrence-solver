// WARNING: The files in this directory have not been extensively tested
//   and may be incorrect. --JTB

void main() {
    int a;
    int b;
    int c;
    int N;
    if (!(c - b == 2)) return 0;
    for(int t = 0; t < N; t++) {
        if (a > 0) {
            b += a;
            c += 1;
            a = -1;
        } else {
            b += a;
            c -= 1;
            a = 1;
        } 
    }
    __VERIFIER_assert(c - b == 2);
}
