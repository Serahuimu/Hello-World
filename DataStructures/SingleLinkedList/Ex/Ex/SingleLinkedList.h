#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SListNode {
	SLDataType data;
	struct SListNode* next;
}SL;


//Basic Operate

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

//Exercise

// ������ 02.03. ɾ���м�ڵ�
// �������е�ĳ���ڵ㣬�Ȳ�������ͷ�ڵ㣬Ҳ��������β�ڵ㣬�����Ϊ������ġ��м�ڵ㡹��
// �ٶ���֪�����ĳһ���м�ڵ㣬��ʵ��һ���㷨�����ýڵ��������ɾ����
void deleteMidNode(SL* pos);


//��ת����
SL * SLReverse(SL * phead);

//������k����
SL* SLKth(SL * phead, int k);