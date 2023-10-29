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
void SLInit(SL* ps);

//���ռ��Ƿ���
void SLCheckCapacity(SL* ps);

//����
void SLInsert(SL* ps, int pos, SLDataType x);

//ɾ��
void SLErase(SL* ps, int pos);

//β��
void SLPushBack(SL* ps, SLDataType x);

//ͷ��
void SLPushFront(SL* ps, SLDataType* x);

//��ӡ
void SLPrint(SL* ps);

//ͷɾ
void SLPopFront(SL* ps);

//βɾ
void SLPopBack(SL* ps);

//����
int SLFind(SL* ps, SLDataType x);

//�޸�
void SLModify(SL* ps, int pos, SLDataType x);