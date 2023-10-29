#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList {
	SLDataType* a;
	int size;			//˳���Ĵ�С
	int capacity;		//ʵ�ʷ���Ĵ�С
}SL;

//��ʼ��
void SLInit(SL* ps);
//����
void SLDestory(SL* ps);
//��ӡ
void SLPrint(SL* ps);
//�����ڴ�
void SLCheckCapacity(SL* ps);

//ͷ��β�壬ͷɾβɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

// �����±꣬û���Ҵ򷵻�-1
int SLFind(SL* ps, SLDataType x);

// ��posλ�ò���x
void SLInsert(SL* ps, int pos, SLDataType x);

// ɾ��posλ�õ�ֵ
void SLErase(SL* ps, int pos);

//�ı�pos����ֵ
void SLModify(SL* ps, int pos, SLDataType x);