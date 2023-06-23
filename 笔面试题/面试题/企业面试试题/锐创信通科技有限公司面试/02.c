#include <stdio.h>
#define OVER_FLOW -2
#define OK         1

typedef int ElemType; /*������������*/

typedef struct node_data /*�����������ݽڵ�Ľṹ��*/
{
	ElemType data;
	struct node_head *prior;
	struct node_data *next;
} DNode;

typedef struct node_head /*��������ͷβ�ڵ�Ľṹ�壬D��ʾdouble��˫������*/
{
	DNode *Head;
	DNode *Tail;
} DLinkNode, *DLinkList;

/*����һ���յ�˫������û�нڵ㣬ֻ��ͷ��βָ��*/
void Init_DLinkList(DLinkList HT_pointer)
{
	HT_pointer->Head = NULL;
	HT_pointer->Tail = NULL;
}

/*�ڱ�ͷ����һ��Ԫ��*/
int Insert_First(DLinkList HT_pointer, ElemType x)
{
	DNode *p, *q;
	p = (DNode *) malloc(sizeof(DNode));
	if (p == NULL)
		return OVER_FLOW;
		
	p->data = x;
	
	if (HT_pointer->Head == NULL)
	{ /*����Ϊ��*/
		p->prior = NULL; //�½ڵ��ǰ��ָ��ָ��NULL
		p->next  = NULL; //�½ڵ�ĺ��ָ��ָ��NULL
		HT_pointer->Head = p; //ͷָ��ָ���½ڵ�
		HT_pointer->Tail = p; //βָ��ָ���½ڵ�
	}
	else
	{ /*������*/
		p->prior = NULL;
		p->next = HT_pointer->head; //�½ڵ���ָ��ָ��ԭ���Ǹ�ͷ���
		HT_pointer->Head->prior = p; //ԭ���ڵ��ǰ��ָ��ָ���½ڵ�
		HT_pointer->Head = p; //ԭ����ͷָ��ָ���½ڵ�
	}
	return OK;
}

/*ɾ��һ��Ԫ��*/
int Delete_DLinkList(DLinkList HT_pointer, ElemType x)
{
	DNode *p, *q;
	p = HT_pointer->head; /*pȡͷָ��*/
	while(p != NULL)
	{
		printf("* %d", p->data);
		if (p->data == x)
		{	/*���˫��������ֻʣ��1���ڵ�*/
			if (HT_pointer->Head == p && HT_pointer->Tail == p)
			{
				HT_pointer->Head = NULL; //ͷָ��ָ��NULL
				HT_pointer->Tail = NULL; //βָ��ָ��NULL
				//free(p); /*���ܸо����p��������free����Ϊ��85�л�free��һ��*/
			}
			else if (HT_pointer->head == p)
			{	/*ɾ������˫�������е�ͷ���*/
				HT_pointer->Head = p->next;
				p->next->prior = NULL;
			}
			else if (HT_pointer->Tail == p)
			{	/*ɾ������˫�������е�β�ڵ�*/
				HT_pointer->Tail = p->prior;
				p->prior->next = NULL;
			}
			else
			{	/*�м�Ľڵ�*/
				p->next->prior = p->prior;
				p->prior->next = p->next;
			}
			free(p); //�ͷŽڵ�ռ�
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

int main(int argc, char *argv[])
{
	DLinkNode HeadTail;
	ElemType x;
	Init_DLinkList (&HeadTail);
	
	x = 30;
	Insert_first(&HeadTail, x);
	Delete_DLinkList(&HeadTail, x);
	
	return 0;
}