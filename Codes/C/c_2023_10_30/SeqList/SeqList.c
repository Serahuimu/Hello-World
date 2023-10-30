#include "SeqList.h"
//��ʼ��
void SLInit(SL* pl) {
	pl->a = NULL;
	pl->size = 0;
	pl->capacity = 0;
}
void SLCheckCapacity(SL* pl) {
	assert(pl);
	//�ռ������ˣ�����û�з�����ڴ�
	if (pl->size == pl->capacity) {
		int newcapacity = pl->capacity == 0 ? 4 : pl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(pl->a, sizeof(SLDataType) * newcapacity);
		
		if (tmp == NULL) {
			printf("Realloc Failed\n");
			exit(-1);
		}
		pl->capacity = newcapacity;
		pl->a = tmp;
	}
	//�пռ�
	else {
		return;
	}
}
//����
void SLInsert(SL* pl, int pos, SLDataType x) {
	//���ԣ������±겻�Ϸ�������ָ��plΪ��ָ��ʱ����
	assert(pl && pos >= 0 && pos <= pl->size);
	SLCheckCapacity(pl);
	//���룬Ҫ��Ԫ�ش�posλ��ʼ����ƶ�һλ
	int i = pl->size;
	while (i > pos) {
		pl->a[i] = pl->a[i - 1];
		i--;
	}
	pl->a[pos] = x;
	pl->size++;
}
//ɾ��
void SLErase(SL* pl, int pos) {
	//���ԣ������±겻�Ϸ�������ָ��plΪ��ָ��ʱ����
	assert(pl && pos >= 0 && pos < pl->size);
	int i = pos;
	while (i < pl->size - 1) {
		pl->a[i] = pl->a[i + 1];
		i++;
	}
	pl->size--;
}
//ͷ��
void SLPushFront(SL* pl, SLDataType x) {
	assert(pl);
	SLInsert(pl, 0, x);
}
//β��
void SLPushBack(SL* pl, SLDataType x) {
	assert(pl);
	SLInsert(pl, pl->size, x);
}
//��ӡ
void SLPrint(const SL* pl) {
	assert(pl);
	int i = 0;
	while (i < pl->size) {
		printf("%d ", pl->a[i]);
		i++;
	}
	printf("\n");
}

void SLPopFront(SL* pl) {
	assert(pl);
	SLErase(pl, 0);
}

void SLPopBack(SL* pl) {
	assert(pl);
	SLErase(pl, pl->size - 1);
}

void SLModify(SL* pl, int pos, SLDataType x) {
	assert(pl && pos >= 0 && pos < pl->size);
	pl->a[pos] = x;
}

//���ң��ҵõ��н������Ҳ����гͷ�
int SLFind(const SL* pl, SLDataType x) {
	assert(pl);
	int i = 0;
	while (i < pl->size) {
		if (pl->a[i] == x) {
			return i;
		}
		i++;
	}
	if (i == pl->size) {
		return -1;
	}
}