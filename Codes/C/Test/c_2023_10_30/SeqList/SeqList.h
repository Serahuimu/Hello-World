#pragma once
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
//���룬 ��posλ����
void SLInsert(SL* pl, int pos, SLDataType x);
//ɾ��
void SLErase(SL* pl, int pos);
//ͷ��
void SLPushFront(SL* pl, SLDataType x);
//β��
void SLPushBack(SL* pl, SLDataType x);
//��ӡ
void SLPrint(const SL* pl);
//ͷɾ
void SLPopFront(SL* pl);
//βɾ
void SLPopBack(SL* pl);
//�ı�
void SLModify(SL* pl, int pos, SLDataType x);
//���ң��ҵ��˷����±꣬�Ҳ�������-1
int SLFind(const SL* pl, SLDataType x);