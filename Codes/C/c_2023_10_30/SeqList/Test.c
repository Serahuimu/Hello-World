#include "SeqList.h"

void Test(void) {
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 4);

	//SLPushFront(&sl, 1);
	//SLPushFront(&sl, 9);
	//SLPushFront(&sl, 1);
	//SLPushFront(&sl, 9);
	//SLPushFront(&sl, 8);
	//SLPushFront(&sl, 1);
	//SLPushFront(&sl, 0);

	//SLPopBack(&sl);
	//SLPopFront(&sl);

	SLModify(&sl, 4, 114514);
	int a = SLFind(&sl, 114514);		//��ֹһ�ΰ�SLFind����д��void�ķ��������ˣ��´�Ҫע����
	printf("%d\n", a);
	SLPrint(&sl);
}

int main(void) {
	Test();

	return 0;
}