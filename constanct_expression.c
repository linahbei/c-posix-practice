#include <stdio.h>

#define __is_constexpr(x) \
    (sizeof(int) == sizeof(*(8 ? ((void *) ((long) (x) *0l)) : (int *) 8)))

#define __constexpr(x) \
    (long)(x) * 0l

#define __constexpr_void_pointer(x) \
   ((void *)((long)(x) * 0l))

#define __test_constexpr(constexpr) \
    printf("--- %s ---\n", #constexpr); \
    printf("(1) Is constexpr: %s\n", __is_constexpr(constexpr) == 0 ? "false" : "true"); \
    printf("(2) Its constexpr expression: %ld\n", __constexpr(constexpr)); \
    printf("(3) Addr of its void pointer: %p\n", __constexpr_void_pointer(constexpr));

#define radix 10

int main() {
    const int radix_i = 10;
    __test_constexpr(radix);
    __test_constexpr(radix_i);
#ifdef WRITE_CONSTANT_VARIABLE
    radix_i++;
#endif
    return 0;
}

