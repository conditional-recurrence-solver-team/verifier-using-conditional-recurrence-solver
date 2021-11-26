// Source: Denis Gopan, Thomas Reps: "Lookahead Widening", CAV 2006.

#include "assert.h"

int main() {
    int x = 0;
    int y = 0;
    while (y >= 0) {
        if (x < 50) {
            y++;
        } else {
            y--;
        }
        x++;
    }
    __VERIFIER_assert(x == 101);
    return 0;
}
