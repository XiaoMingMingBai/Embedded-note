#include "head.h"
#include "queues.h"

int main(int argc, char const *argv[])
{
    Node *tree=BinaryTreeCreat(7,1);
    puts("queues");
    BinaryTreeQueuesTraverseShow(tree);
    puts("first");
    BinaryTreeFirstTraverseShow(tree);
    putchar(10);
    puts("middle");
    BinaryTreeMiddleTraverseShow(tree);
    putchar(10);
    puts("after");
    BinaryTreeAfterTraverseShow(tree);
    putchar(10);
}
