#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct SListNode {
	DataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pphead) {
	*pphead = NULL;
}


//���������������
void BubbleSort(SListNode** pphead) {
	if (*pphead == NULL) {
		return;
	}
	DataType tmp;
	//����ѭ���ı���
	SListNode* current = *pphead;
	SListNode* next = NULL;

	while (current != NULL) {
		next = current->next;
		while (next != NULL) {
			if (current->data > next->data) {
				tmp = current->data;
				current->data = next->data;
				next->data = tmp;
			}
			next = next->next;
		}
		current = current->next;
	}
}

//��ӡ����
void SListPrint(SListNode* phead) {
	SListNode* cur = phead;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

//����ռ�
SListNode* SListNodeBuy(DataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//������Ƿ���������
	if (newNode == NULL) {
		printf("Malloc Failed\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

//β�壺
void SListPushBack(SListNode** pphead, DataType x) {
	//�ȷ���ռ䣬���û�н��Ͱ�ͷָ��ָ����������оͽ��ڵ�ǰ����֮��
	SListNode* newnode = SListNodeBuy(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}

	else {
		//��β���
		SListNode* tail = *pphead;
		//while (tail->next != NULL)
		while (tail->next) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//ͷ�壺
void SListPushFront(SListNode** pphead, DataType x) {
	SListNode* newnode = SListNodeBuy(x);
	newnode->next = *pphead;		//���½�����һλָ��ԭ����ͷ���
	*pphead = newnode;				//��ͷ�����ָ���½��
}

//�ϲ�����
SListNode* SListCombine(SListNode** pplist1, SListNode** pplist2) {
	SListNode* p1 = *pplist1;
	SListNode* p2 = *pplist2;
	SListNode* p3 = NULL;

	//����
	while (p1 != NULL) {
		SListPushBack(&p3, p1->data);
		p1 = p1->next;
	}

	while (p2 != NULL) {
		SListPushBack(&p3, p2->data);
		p2 = p2->next;
	}

	return p3;
}

SListNode* SListRemove(SListNode ** pphead) {
	SListNode* current = *pphead;
	while (current != NULL) {
		SListNode* temp = current;
		while (temp->next != NULL) {
			if (temp->next->data == current->data) {
				SListNode* nodeDel = temp->next;
				temp->next = temp->next->next;
				free(nodeDel);
			}
			else {
				temp = temp->next;
			}
		}
		current = current->next;
	}
}

//���Ժϲ�
void Test4(void) {
	//���ϲ�������
	SListNode* plist1 = NULL;
	SListNode* plist2 = NULL;
	//�ϲ�����Ŀ������
	SListNode* plist3 = NULL;

	//��ʼ��
	SListInit(&plist1);
	SListInit(&plist2);
	SListInit(&plist3);

	//�������ݵ�plist1
	SListPushBack(&plist1, 1);
	SListPushBack(&plist1, 1);
	SListPushBack(&plist1, 4);
	SListPushBack(&plist1, 5);
	SListPushBack(&plist1, 1);
	SListPushBack(&plist1, 4);

	//�������ݵ�plist2
	SListPushBack(&plist2, 1);
	SListPushBack(&plist2, 9);
	SListPushBack(&plist2, 1);
	SListPushBack(&plist2, 9);
	SListPushBack(&plist2, 8);
	SListPushBack(&plist2, 1);
	SListPushBack(&plist2, 0);



	plist3 = SListCombine(&plist1, &plist2);
	SListRemove(&plist3);

	//SListPrint(plist1);
	//SListPrint(plist2);
	SListPrint(plist3);
}


int main(void) {
	Test4();

	return 0;
}




















//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int DataType;
//typedef struct SListNode {
//    DataType data;
//    struct SListNode* next;
//}SListNode;
//
//void SListPrint(SListNode* phead)
//{
//    SListNode* cur = phead;
//
//    while (cur != NULL) {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//}
//
//void SListPushFront(SListNode** pphead, DataType x)
//{
//    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode*));
//    if (newNode == NULL) {
//        printf("Malloc Failed\n");
//        exit(-1);
//    }
//    else {
//        newNode->data = x;
//        newNode->next = NULL;
//    }
//
//    newNode->next = *pphead;
//    *pphead = newNode;
//}
//
//void SListPopBack(SListNode** pphead)
//{
//    //û�нڵ�
//    if (*pphead == NULL) {
//        return;
//    }
//    //��һ���ڵ�
//    else if ((*pphead)->next == NULL) {
//        free(*pphead);
//        *pphead = NULL;
//    }
//    //�����ڶ���ڵ�
//    else {
//        SListNode* tail = *pphead;
//        while (tail->next->next) {
//            tail = tail->next;
//        }
//        free(tail->next->next);
//        tail->next = NULL;
//    }
//}
//
//void SListPopFront(SListNode** pphead)
//{
//    if (*pphead == NULL) {
//        return;
//    }
//    SListNode* next = (*pphead)->next;
//    free(*pphead);
//    *pphead = next;
//    // SListNode * head = *pphead;
//    // head = head->next;
//    // free(*pphead);
//}
//
//void Test1(void)
//{
//    SListNode* plist = NULL;
//    SListPushFront(&plist, 114514);
//    SListPushFront(&plist, 114);
//    SListPushFront(&plist, 514);
//    SListPushFront(&plist, 1919810);
//    // SListPopBack(&plist);
//    SListPopFront(&plist);
//    SListPrint(plist);
//}
//
//int main(void)
//{
//    Test1();
//
//    return 0;
//}