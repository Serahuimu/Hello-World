#include "SL.h"

//��ʼ��
void SLInit(SL** pphead)
{
	//����ͷ�ĵ�ַ�ĵ�ַ������Ȼ������ö����ַ�����޸�
	*pphead = NULL;
}
//����ռ�
SL* SLBuyCapacity(SLDataType x)
{
	SL* newNode = (SL*)malloc(sizeof(SL));

	if (newNode == NULL)
	{
		exit(-1);
		printf("Malloc Failed!\n");
	}

	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

//β��
void SLPushBack(SL** pphead, SLDataType x)
{
	//����ǿձ�ʹ���һ���ڵ���ͷָ��ָ����
	if (*pphead == NULL)
	{
		*pphead = SLBuyCapacity(x);
	}
	else
	{
		SL* tail = *pphead;
		//�ҵ����һ���ڵ�
		while (tail->next)
		{
			tail = tail->next;
		}
		//ָ���½ڵ�
		tail->next = SLBuyCapacity(x);
	}
}
//ͷ��
void SLPushFront(SL** pphead, SLDataType x)
{
	//Create a new node to insert at the head of list.
	SL* newNode = SLBuyCapacity(x);
	//newNode pointer field to *pphaed (head of the list)
	newNode->next = *pphead;
	//head pointer to newNode
	*pphead = newNode;
}
//��posǰ�����
void SLInsert(SL** pphead, SL* pos, SLDataType x)
{
	//pos == NULL, then can insert before the tail node.
	//if (pos == NULL)
	//{
	//	exit(-1);
	//}
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		SL* cur = *pphead;
		SL* newNode = SLBuyCapacity(x);
		//cur is not a null pointer and cur->next not equal pos, cur = cur->next
		//while loop will be break when the cur is null or the pos == cur->next
		while (cur && cur->next != pos)
		{
			cur = cur->next;
		}
		//insert newNode when the cur->next == pos, and cur not equal null
		if (cur != NULL && cur->next == pos)
		{
			newNode->next = pos;
			cur->next = newNode;
		}
	}
}
//��pos�������
void SLInsertAfter(SL* pos, SLDataType x)
{
	if (pos == NULL)
	{
		exit(-1);
	}
	SL* newNode = SLBuyCapacity(x);
	pos->next = newNode;
}

//βɾ
void SLPopBack(SL** pphead)
{
	if (*pphead == NULL)
	{
		printf("linked list is null\n");
		exit(-1);
	}
	SL* tail = *pphead;

	//previous of the tail node is tail->next->next
	//tail->next is tail node
	//tail->next->next is null
	while (tail->next->next)
	{
		tail = tail->next;
	}

	SL* tmp = tail->next;
	tail->next = tmp->next;
	free(tmp);
}
//ͷɾ
void SLPopFront(SL** pphead)
{
	if (*pphead == NULL)
	{
		exit(-1);
	}

	SL* tmp = *pphead;
	*pphead = tmp->next;
	free(tmp);
}
//ɾ��posλ��
void SLErase(SL** pphead, SL* pos);
//ɾ��pos�����λ��
void SLEraseAfter(SL* pos);

//��ӡ
void SLPrint(SL* phead)
{
	SL* cur = phead;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}