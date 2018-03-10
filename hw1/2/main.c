#include <stdio.h>

struct expression{
    int* num;
    char op;
    struct expression* parent;
    struct expression* left;
    struct expression* right;
};

struct expression create()

int main() {
    printf("Hello, World!\n");
    return 0;
}