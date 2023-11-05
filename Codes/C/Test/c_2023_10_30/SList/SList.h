#pragma once
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
//��ӡ����
void SLTPrint(SLTNode* phead);
//��pos֮ǰ����x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��pos֮�����
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//����ռ�
SLTNode* BuySListNode(SLTDataType x);
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
// ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos);
// ɾ��pos�ĺ�һ��λ��
void SLTEraseAfter(SLTNode* pos);