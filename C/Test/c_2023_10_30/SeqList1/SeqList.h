#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList {
	SLDataType* a;
	int size;
	int capacity;
}SL;

//��ʼ��
void SLInit(SL* pl);
//����ռ�
void SLCheckCapacity(SL* pl);
//���룺��posλ�ò���x
void SLInsert(SL* pl, int pos, SLDataType x);
//ɾ����ɾ����posλ�õ�Ԫ��
void SLErase(SL* pl, int pos);
//ͷ��
void SLPushFront(SL* pl, SLDataType x);
//β��
void SLPushBack(SL* pl, SLDataType x);
//ͷɾ
void SLPopFront(SL* pl);
//βɾ
void SLPopBack(SL* pl);
//��ӡ
void SLPrint(const SL* pl);
//����
int SLFind(const SL* pl, SLDataType x);
//�޸�
void SLModify(SL* pl, int pos, SLDataType x);