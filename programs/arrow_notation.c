#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct obj {
    long *ptr;
    long id;
};

void tata(struct obj *optr)
{
    optr->id = 20; //optr->id is the same as (*optr).id
    optr->ptr = &optr->id;
}

int main(void)
{
    struct obj o;
    long x = 10;
    
    o.ptr = &x;
    o.id = 0;

    tata(&o);

    printf("%ld %ld\n", *o.ptr, o.id);
}