#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} L_Loop;

/*initialize function*/
L_Loop* InitLoopList(int num);

/*show list*/
int Show(L_Loop* head);

int Star(L_Loop* head, int k, int m);

int Delete(L_Loop* head);

int main(int argc, char const* argv[])
{
    int n, k, m;
    printf("please enter n k m:");
    scanf("%d%d%d", &n, &k, &m);
    L_Loop* headLoop = InitLoopList(n);
    Show(headLoop);
    Star(headLoop, k, m);
    return 0;
}

L_Loop* InitLoopList(int num)
{
    L_Loop* head = (L_Loop*)malloc(sizeof(L_Loop));
    L_Loop* headLoop = head;
    L_Loop* tem = NULL;
    head->next = head;
    for (size_t i = 1; i <= num; i++) {
        tem = (L_Loop*)malloc(sizeof(L_Loop));
        tem->data = i;
        tem->next = head->next;
        head->next = tem;
        head = head->next;
    }
    head->next = headLoop->next;
    free(headLoop);
    headLoop = NULL;
    return head;
}

int Show(L_Loop* head)
{
    L_Loop* tem = head;
    printf("thick data: ");
    do {
        tem = tem->next;
        printf("%d ", tem->data);
    } while (tem != head);
    putchar(10);
}

int Star(L_Loop* head, int k, int m)
{
    int count = 0;
    for (int i = 1; i < k; i++) {
        head = head->next;
    }
#if 0
    while (head != head->next)
    {
        count++;
        if ((count % m) == 0)
        {
            Delete(head);
            count = 0;
            continue;
        }
        head = head->next;
    }
#else
    while (head != head->next) {
        for (int i = 1; i < m; i++) {
            head = head->next;
        }
        Delete(head);
        count--;
    }
#endif
    printf("\tkick out: %d\n", head->data);
    free(head);
}

int Delete(L_Loop* head)
{
    L_Loop* tem = NULL;
    tem = head->next;
    head->next = head->next->next;
    printf("\tkick out: %d\n", tem->data);
    free(tem);
    tem = NULL;
}