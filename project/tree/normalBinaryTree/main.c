#include "head.h"

int main(int argc, char const *argv[])
{
    Node *tree = BinaryTreeCreat();
    FirstTraverseShow(tree);
    putchar(10);
    MiddleTraverseShow(tree);
    putchar(10);
    AfterTraverseShow(tree);
    putchar(10);
    return 0;
}
