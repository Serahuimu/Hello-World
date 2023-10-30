#include "SList.h"

//��ʼ��
void SLTInit(SLTNode** pphead) {
	*pphead = NULL;
}
//��ӡ����
//��ͷָ��(phead)������βָ��
void SLTPrint(SLTNode* phead) {
	assert(phead);
	SLTNode* tmp = phead;
	while (tmp) {
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
//����ռ�
SLTNode* BuySListNode(SLTDataType x) {
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	if (tmp == NULL) {
		printf("Malloc Failed\n");
		exit(-1);
	}
	tmp->data = x;
	tmp->next = NULL;

	return tmp;
}
//��pos֮ǰ����x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(*pphead && pos);
	if (pos == *pphead) {
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* tmp = *pphead;

		while (tmp->next != pos) {
			tmp = tmp->next;
		}
		SLTNode* newnode = BuySListNode(x);
		newnode->next = pos;
		tmp->next = newnode;
	}
}

//��pos֮�����
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	if (pos->next == NULL) {
		SLTPushBack(&pos, x);
	}
	else {
		//��һ����֮ǰд����tmp = pos->next��Ҫע��
		SLTNode* tmp = BuySListNode(x);
		tmp->next = pos->next;
		pos->next = tmp;
	}
}

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SLTNode* tail = *pphead;
		while (tail->next) {
			tail = tail->next;
		}
		tail->next = newnode;
		newnode->next = NULL;
	}
}

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//βɾ
void SLTPopBack(SLTNode** pphead) {
	assert(*pphead);
	SLTNode* tail = *pphead;
	while (tail->next->next) {
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}

//ͷɾ
void SLTPopFront(SLTNode** pphead) {
	assert(*pphead);
	SLTNode* tmp = *pphead;
	(*pphead) = (*pphead)->next;
	free(tmp);
}

//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x) {
	assert(phead);
	SLTNode* tmp = phead;

	while (tmp) {
		if (tmp->data == x) {
			return tmp;
		}
		tmp = tmp->next;
	}

	return NULL;
}

// ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(*pphead && pos);
	if (*pphead == pos) {
		SLTPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

// ɾ��pos�ĺ�һ��λ��
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next);
	SLTNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
	tmp = NULL;
}