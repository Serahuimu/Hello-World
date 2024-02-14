#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//��ʼ��
void SLTInit(SLTNode** pphead);
//����ռ�
SLTNode* SLTBuyCapacity(SLTDataType x);
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//��posǰ�����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��pos�������
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);