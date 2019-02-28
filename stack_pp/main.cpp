#include "stack_pp.h"


int main() {
    Stack test1(10);

    test1.Push(56);

    int x = test1.Pop();

    printf("%d\n", x);

    //Dump(&test1);


    //unittest(&test1);

    //StackDtor(&test1);
}

