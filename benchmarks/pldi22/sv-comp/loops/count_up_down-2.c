extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "count_up_down-2.c", 3, "reach_error"); }


int main()
{
  unsigned int n = __VERIFIER_nondet_uint();
  unsigned int x=n;
  unsigned int y = 0;
  while(x>0)
  {
    x--;
    y++;
  }
  __VERIFIER_assert(y!=n);
}
