#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SListNode {
	SLDataType data;
	struct SListNode* next;
}SL;

//��ʼ��
void SLInit(SL** pphead);
//����ռ�
SL* SLBuyCapacity(SLDataType x);

//β��
void SLPushBack(SL** pphead, SLDataType x);
//ͷ��
void SLPushFront(SL** pphead, SLDataType x);
//��posǰ�����
void SLInsert(SL** pphead, SL* pos, SLDataType x);
//��pos�������
void SLInsertAfter(SL* pos, SLDataType x);

//βɾ
void SLPopBack(SL** pphead);
//ͷɾ
void SLPopFront(SL** pphead);
//ɾ��posλ��
void SLErase(SL** pphead, SL* pos);
//ɾ��pos�����λ��
void SLEraseAfter(SL* pos);

//��ӡ
void SLPrint(SL* phead);