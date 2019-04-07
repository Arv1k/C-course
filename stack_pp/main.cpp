#include "stack_pp.h"

int __cdecl Sum(int a, int b);

int __cdecl Sum(int a,int b) {
    return a + b;
}

int main() {
    /*Stack test1(10);

    test1.Push(56);
*/
    int x = Sum(4, 6);/*test1.Pop()*/;

    printf("%d\n", x);

    //Dump(&test1);


    //unittest(&test1);

    //StackDtor(&test1);
}

