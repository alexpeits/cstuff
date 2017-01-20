/*
 * Simple stack implementation, able to hold any type of data (eventually)
 */

#include <stdlib.h>

#define INT_TYPE 1
#define FLOAT_TYPE 2
#define CHAR_TYPE 3

#define MAXSIZE 1024

typedef struct _stack {
    short type;
    void *data;
    int nxt;
} *stack;


stack new_stack(short tp) {
    stack s = (stack)malloc(sizeof(stack));
    void *data;
    if (tp == INT_TYPE) {
        data = (int *)malloc(MAXSIZE * sizeof(int));
    } else if (tp == CHAR_TYPE) {
        data = (int *)malloc(MAXSIZE * sizeof(char));
    } else {
        exit(1);
    }
    s->type = tp;
    s->data = data;
    s->nxt = 0;
    return s;
}


void stack_push(stack s, void *item) {
    if (s->type == INT_TYPE) {
        int *data = (int *)s->data;
        data[s->nxt] = *((int *)(item));
    } else if (s->type == CHAR_TYPE) {
        char *data = (char *)s->data;
        data[s->nxt] = *((char *)(item));
    }
    s->nxt += 1;
}

void *stack_pop(stack s) {
    s->nxt -= 1;
    if (s->type == INT_TYPE) {
        return (void *)(((int *)s->data) + s->nxt);
    } else if (s->type == CHAR_TYPE) {
        return (void *)(((char *)s->data) + s->nxt);
    } else {
        exit(1);
    }
}

void free_stack(stack s) {
    free(s->data);
    free(s);
}
