#include <stdio.h>
#include "stack.h"

int main() {
    stack s = new_stack(INT_TYPE);
    int i = 3;
    int *x = &i;
    stack_push(s, (void *)x);
    printf("pushed: %d\n", ((int *)(s->data))[0]);
    int *res = stack_pop(s);
    printf("popped: %d\n", *res);

    stack ss = new_stack(CHAR_TYPE);
    char ii = 'a';
    char *xx = &ii;
    stack_push(ss, (void *)xx);
    printf("pushed: %c\n", ((char *)(ss->data))[0]);
    char *ress = stack_pop(ss);
    printf("popped: %c\n", *ress);

    free_stack(s);
    free_stack(ss);
}
