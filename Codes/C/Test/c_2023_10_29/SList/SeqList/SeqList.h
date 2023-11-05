#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList {
    SLDataType* a;
    int size;               //����Ԫ��
    int capacity;           //ʵ�ʳ���
}SL;

//��ʼ��
void SeqListInit(SL* pl);
//����
void SeqListDestory(SL* pl);
//��ӡ
void SeqListPrint(SL sl);
//�����б������
void SeqListCheckCapacity(SL* pl);
//β��
void SeqListPushBack(SL* pl, SLDataType x);
//ͷ��
void SeqListPushFront(SL* pl, SLDataType x);
//βɾ
void SeqListPopBack(SL * pl);
//ͷɾ
void SeqListPopFront(SL * pl);
//����
int SeqListFind(SL pl, SLDataType x);
//��posλ�ú������һ������
void SeqListInsert(SL *pl, int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListErase(SL * pl, int pos);
//�޸�posλ�õ�����Ϊx
void SeqListModify(SL * pl, int pos, SLDataType x);