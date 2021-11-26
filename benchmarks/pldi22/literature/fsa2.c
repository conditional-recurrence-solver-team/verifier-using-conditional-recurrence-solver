extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "multivar_1-1.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}
int main() {
    int s = 1;
    int x = 0;
    int y = 0;
    int size;
    int i = 0;
    int s0 = s;
    while (i < size) {
        if (s == 2) {
            s = s + 1;
            x = x + 1;
        } else if (s == 3) {
            s = s + 1;
            y = y + 1;
        } else if (s >= 4) {
            s = 1;
        } else {
            s = s + 1;
        }
        i = i + 1;
    }
    __VERIFIER_assert((s != 1) || (x == y));
}
