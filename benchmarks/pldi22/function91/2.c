int main() {
    int i = -10000;
    int c = 1;
    while (c != 0) {
        if (i > 100) {
            i = i - 10;
            c = c - 1;
        } else {
            i = i + 11;
            c = c + 1;
        }
    }
    __VERIFIER_assert(i == 91);
}
