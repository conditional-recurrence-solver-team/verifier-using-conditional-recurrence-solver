// WARNING: The files in this directory have not been extensively tested
//   and may be incorrect. --JTB

void main(int N) {
    int x;
    int y;
    // int z = 1;
    if ((x - y) * (x - y) != 1) return 0;
    for(int t = 0; t < N; t++) {
        if (x > y) {
            y = y + 2; 
            // z = (x - y) * (x - y);
        } else { 
            x = x + 2; 
            // z = (x - y) * (x - y);
        }
    }
    __VERIFIER_assert((x - y) * (x - y) == 1);
}
