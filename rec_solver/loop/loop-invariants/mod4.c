extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "mod4.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}
int main(void) {
  unsigned int x = 0;
  while (__VERIFIER_nondet_int()) {
    x += 4;
  }
  __VERIFIER_assert(!(x % 4));
  return 0;
}
