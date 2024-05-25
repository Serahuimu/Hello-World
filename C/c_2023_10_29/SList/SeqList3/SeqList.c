#include "SeqList.h"

void SLInit(SL* ps) {
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SLCheckCapacity(SL* ps) {
	//����������û��ֵ��ʱ�򣬷���ռ�
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType * tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);

		if (tmp == NULL) {
			printf("Realloc Failed\n");
			exit(-1);
		}
		ps->capacity = newcapacity;
		ps->a = tmp;
	}
}

void SLInsert(SL* ps, int pos, SLDataType x) {
	//psΪ��ָ�룬Ҫ�����Ԫ���±겻����Ҫ����ǿ���˳�
	assert(ps && pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	
	//����ע��һ��
	int end = ps->size;
	while (end >= pos) {
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos) {
	assert(ps && pos >= 0 && pos < ps->size);
	int i = pos;
	//�����е�Ԫ����ǰ��
	while (i < ps->size - 1) {
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}

void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	SLInsert(ps, ps->size, x);
}

void SLPushFront(SL* ps, SLDataType* x) {
	assert(ps);
	SLInsert(ps, 0, x);
}

void SLPrint(SL* ps) {
	assert(ps);
	int i;
	for (i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
}

//ͷɾ
void SLPopFront(SL* ps) {
	assert(ps);
	SLErase(ps, 0);
}

//βɾ
void SLPopBack(SL* ps) {
	assert(ps);
	SLErase(ps, ps->size - 1);
}

//����
int SLFind(SL* ps, SLDataType x) {
	assert(ps);
	int i = 0;
	while (i < ps->size) {
		if (ps->a[i] == x) {
			return i;
		}
		i++;
	}
	if (i == ps->size) {
		return -1;
	}
}

//�޸�
void SLModify(SL* ps, int pos, SLDataType x) {
	assert(ps);
	ps->a[pos] = x;
}