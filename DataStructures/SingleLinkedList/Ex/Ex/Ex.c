#include "SingleLinkedList.h"

// ������ 02.03. ɾ���м�ڵ�
// �������е�ĳ���ڵ㣬�Ȳ�������ͷ�ڵ㣬Ҳ��������β�ڵ㣬�����Ϊ������ġ��м�ڵ㡹��
// �ٶ���֪�����ĳһ���м�ڵ㣬��ʵ��һ���㷨�����ýڵ��������ɾ����
void deleteMidNode(SL* pos)
{
	//�ж�λ���Ƿ�Ϊ��
	if (pos == NULL)
		exit(-1);

	//��pos->next�����ݺ�ָ���򸳸�pos��Ȼ��ɵ�pos->next
	SL* tmp = pos->next;
	pos->data = tmp->data;
	pos->next = tmp->next;
	free(tmp);
}

//��ת����
SL* SLReverse(SL* phead)
{
	SL* p = NULL;
	SL* q = phead;
	SL* tmp = NULL;

	//Linked List is NULL
	if (phead == NULL)
	{
		printf("Linked List is NULL\n");
		return NULL;
	}
	//Linked List has only one Node
	else if (phead->next == NULL)
	{
		return q;
	}
	//Normal Condition
	else
	{
		//in the end q and tmp will be NULL (at least has 2 nodes)
		while (q)
		{
			tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}



		return p;

		// In this code segment q->next = p, but p is null pointer, so q->next is null
		// Then tmp = q->next means tmp = null
		// Then p = q means p = null
		// and the end q = tmp means q = null
		// all pointers are NULL!!!!!!!!!!!
		//while (q)
		//{
		//	q->next = p;
		//	tmp = q->next;
		//	p = q;
		//	q = tmp;
		//}

	}




	//// error: tmp will pointer to a q(NULL)->next
	//q->next = p;
	//q = tmp;
	//tmp = q->next;
	//p = q;
}


//������k����
SL* SLKth(SL* phead, int k)
{
	//p is the pre pointer
	//q is the kth
	SL* p = phead;
	SL* q = phead;

	if (phead == NULL)
	{
		printf("List is NULL\n");
		return NULL;
	}
	
	//make the p move k step
	while (k)
	{
		
		k--;
		p = p->next;
	}

	//then make the q and p move together.
	//loop is broken when p is null pointer.
	while (p)
	{
		p = p->next;
		q = q->next;
	}

	return q;
}