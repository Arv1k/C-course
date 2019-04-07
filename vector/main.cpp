#include "vector.h"

int main() {
    Vector<char> hey;
    Vector<char> you;

    for(int i = 1; i <= 10; i++)
        hey.pushBack(i*2);

    for(int i = 1; i <= 5; i++)
        you.pushBack(i*3);


    for(int i = 0; i < 10; i++)
        printf("hey: [%d] = %d\n", i, hey[i]);

    printf("\n\n");

    //Vector man(you + hey);

    Vector<char> man = hey + you;

    for(int i = 0; i < 10; i++)
        printf("man: [%d] = %d\n", i, man[i]);
}