#include "SeqList.h"

//��ʼ��
void SLInit(SL* pl) {
	pl->a = NULL;
	pl->size = 0;
	pl->capacity = 0;
}
//����ռ�
void SLCheckCapacity(SL* pl) {
	if (pl->size == pl->capacity) {
		int newcapacity = pl->capacity == 0 ? 4 : pl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(pl->a, sizeof(SLDataType) * newcapacity);
		
		assert(tmp);
		pl->a = tmp;
		pl->capacity = newcapacity;
	}
}
//���룺��posλ�ò���x
void SLInsert(SL* pl, int pos, SLDataType x) {
	assert(pl && pos >= 0 && pos <= pl->size);
	SLCheckCapacity(pl);

	//����Ҫ��pos֮�������Ԫ�غ���һλ
	int i = pl->size;
	while (i > pos) {
		pl->a[i] = pl->a[i - 1];
		i--;
	}
	pl->a[pos] = x;
	pl->size++;
}

//ɾ����ɾ��λ��posλ�õ�Ԫ��
void SLErase(SL* pl, int pos) {
	assert(pl && pos >= 0 && pos < pl->size);
	//���ݰ�pos���Ԫ��ȫ����ǰ�ƶ�
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

//ͷɾ
void SLPopFront(SL* pl) {
	assert(pl);
	SLErase(pl, 0);
}
//βɾ
void SLPopBack(SL* pl) {
	assert(pl);
	SLErase(pl, pl->size - 1);
}
//��ӡ
void SLPrint(const SL* pl) {
	assert(pl);
	int i = 0;
	while (i < pl->size) {
		printf("%d ", pl->a[i++]);
	}
	printf("\n");
}
//����
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
//�޸�
void SLModify(SL* pl, int pos, SLDataType x) {
	assert(pl);
	pl->a[pos] = x;
}