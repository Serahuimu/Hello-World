#include "SeqList.h"

//��ʼ��
void SLInit(SL* ps) {
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
//����
void SLDestory(SL* ps) {
	assert(ps);
	SLInit(ps);
}
//��ӡ
void SLPrint(const SL * sl) {
	int i;
	for (i = 0; i < sl->size; i++) {
		printf("%d ", sl->a[i]);
	}
	printf("\n");
}
//�����ڴ�
void SLCheckCapacity(SL* ps) {
	//�����Ϊ�ջ���û�пռ�
	if (ps->capacity == ps->size) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);

		if (tmp == NULL) {
			printf("Realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

//β��
void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	//�����ظ�����SLInsert()����������
	//SLCheckCapacity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SLInsert(ps, ps->size, x);
}
//βɾ
void SLPopBack(SL* ps) {
	assert(ps && ps->size > 0);
	//ps->size--;
	SLErase(ps, ps->size - 1);
}
//ͷ��
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	//����SLInsert()����
	SLInsert(ps, 0, x);
	//SLCheckCapacity(ps);
	//
	////������Ԫ�����Ų��һλ
	//int end = ps->size;
	//while (end) {
	//	ps->a[end] = ps->a[end - 1];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
}
//ͷɾ
void SLPopFront(SL* ps) {
	assert(ps);
	SLErase(ps, 0);
	//����SLErase()����
	//int i = 0;

	////�����е�Ԫ����ǰŲһλ
	//while (i < ps->size - 1) {
	//	ps->a[i] = ps->a[i + 1];
	//	i++;
	//}
	//ps->size--;
}

// �����±꣬û���Ҵ򷵻�-1
int SLFind(SL* ps, SLDataType x) {
	assert(ps);
	int i;
	//�ҵ���
	for (i = 0; i < ps->size; i++) {
		if (x == ps->a[i]) {
			return i;
		}
	}
	//û�ҵ�
	if (i == ps->size) {
		return -1;
	}
}

// ��posλ�ò���x
void SLInsert(SL* ps, int pos, SLDataType x) {
	//��Ϊ�գ������±겻����Ҫ��ǿ���˳�
	assert(ps && pos <= ps->size && pos >= 0);
	//�üһ���˺ü��Σ���֪����ô��ã�ԭ���Ƿ����ڴ������
	SLCheckCapacity(ps);
	//������Ԫ�����Ų��
	int end = ps->size;
	while (end > pos) {
		ps->a[end] = ps->a[end - 1];
		end--;		//����ط�ѭ�����Ʋ�Ҫ���ˣ���Ϊforѭ���õĶ࣬����дwhileѭ�����������������
	}
	//��ֵ���룬����+1
	ps->a[pos] = x;
	ps->size++;
}

// ɾ��posλ�õ�ֵ
void SLErase(SL* ps, int pos) {
	assert(ps && pos >= 0 && pos < ps->size);

	//�����е�Ԫ����ǰŲһλ
	//int i = 0; ERR��Ӧ���Ǵ�pos��ʼ
	int i = pos;
	while (i < ps->size - 1) {
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}

//�ı�pos����ֵ
void SLModify(SL* ps, int pos, SLDataType x) {
	assert(ps && pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}