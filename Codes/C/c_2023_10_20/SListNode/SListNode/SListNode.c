#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct SListNode {
    DataType data;
    struct SListNode* next;
}SListNode;

void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

void SListPushFront(SListNode** pphead, DataType x)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode*));
    if (newNode == NULL) {
        printf("Malloc Failed\n");
        exit(-1);
    }
    else {
        newNode->data = x;
        newNode->next = NULL;
    }

    newNode->next = *pphead;
    *pphead = newNode;
}

void SListPopBack(SListNode** pphead)
{
    //û�нڵ�
    if (*pphead == NULL) {
        return;
    }
    //��һ���ڵ�
    else if ((*pphead)->next == NULL) {
        free(*pphead);
        *pphead = NULL;
    }
    //�����ڶ���ڵ�
    else {
        SListNode* tail = *pphead;
        while (tail->next->next) {
            tail = tail->next;
        }
        free(tail->next->next);
        tail->next = NULL;
    }
}

void SListPopFront(SListNode** pphead)
{
    if (*pphead == NULL) {
        return;
    }
    SListNode* next = (*pphead)->next;
    free(*pphead);
    *pphead = next;
    // SListNode * head = *pphead;
    // head = head->next;
    // free(*pphead);
}

void Test1(void)
{
    SListNode* plist = NULL;
    SListPushFront(&plist, 114514);
    SListPushFront(&plist, 114);
    SListPushFront(&plist, 514);
    SListPushFront(&plist, 1919810);
    // SListPopBack(&plist);
    SListPopFront(&plist);
    SListPrint(plist);
}

int main(void)
{
    Test1();

    return 0;
}