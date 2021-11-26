// Source: Credited to Anubhav Gupta
// appears in Ranjit Jhala, Ken McMillan: "A Practical and Complete Approach
// to Predicate Refinement", TACAS 2006

#include "assert.h"

int main() {
    int i = __VERIFIER_nondet_int();
    int j = __VERIFIER_nondet_int();
    int x = i;
    int y = j;
    if (!(i >= 0 && j >= 0)) return 0;
    while(x != 0) {
        x--;
        y--;
    }

    if (i == j) {
        __VERIFIER_assert(y == 0);
    }
    return 0;
}
