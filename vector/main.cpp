#include "vector.h"

int main() {
    Vector hey(10);
    Vector you(10);

    for(int i = 1; i <= 10; i++) {
        hey[i - 1] = i * 2;
    }

    hey.size_ = 10;

    for(int i = 0; i < 10; i++)  {
        printf("hey: [%d] = %d \t\t you: [%d] = %d\n", i, hey[i], i, you[i]);
    }

    printf("\n\n");
    you = hey;

    hey[4] = 999;

    for(int i = 0; i < 10; i++)  {
        printf("hey: [%d] = %d \t\t you: [%d] = %d\n", i, hey[i], i, you[i]);
    }
}