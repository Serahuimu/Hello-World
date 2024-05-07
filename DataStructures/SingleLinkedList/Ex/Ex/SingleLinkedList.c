#include "SingleLinkedList.h"

//��ʼ��
void SLInit(SL** pphead) {
	*pphead = NULL;
}
//����ռ䣬ֻ��Ҫxһ����������
SL* SLBuyCapacity(SLDataType x) {
	//1. ����ռ�
	SL* newnode = (SL*)malloc(sizeof(SL));
	//�ж��Ƿ����ɹ�
	if (newnode == NULL) {
		printf("Malloc Failed\n");
		exit(-1);
	}
	//��ֵ�����
	newnode->data = x;
	//�óɿգ������β���ı�־
	newnode->next = NULL;
	//���ؽ��
	return newnode;
}
//�°��β���ͷ��
//1. �°��β��
void SLPushBack(SL** pphead, SLDataType x) {
	//���÷�����ĺ���
	SL* newnode = SLBuyCapacity(x);

	//�ж�ͷ����Ƿ�Ϊ��
	//1. Ϊ�վͰ��½�㸳��ͷ���
	//2. ��Ϊ�վ���β��㣬Ȼ����½�����β���ĺ���
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SL* tail = *pphead;
		//tail->next��tail��ָ���򣬴�tail��ָ����Ϊ�յ�ʱ�򣬾͵�β����ˣ�ָ����Ϊ����β���ı�־
		while (tail->next) {
			tail = tail->next;
		}
		//��tail->next��Ϊnewnode����Ϊnewnode�ڷ���ռ�ĺ�������SLBuyCapacity()�У�ָ�����Ѿ�����Ϊ���ˣ��������������ٴ��ÿա�
		tail->next = newnode;
	}
}
//2. �°��ͷ��
void SLPushFront(SL** pphead, SLDataType x) {
	//������
	SL* newnode = SLBuyCapacity(x);
	//�ж�ͷָ���Ƿ�Ϊ��
	//1. Ϊ�գ�����½�㸳����
	//2. ��Ϊ�գ�����½���ָ����Ϊͷָ�루���½�������ǰ�棩��Ȼ���ͷָ��ָ���½�㣨��ͷָ��һֱָ���ʼ�Ľ�㣩
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		newnode->next = *pphead;
		*pphead = newnode;
		//��Ϊд�°��ͷ��ʱ�ֲ��������Է�����������������ðɡ�
		//���Ǳջ���
		//����Ĵ��󣬱�׼�����
		//(*pphead)->next = newnode;
	}
}
//βɾ
void SLPopBack(SL** pphead) {

}
//ͷɾ
void SLPopFront(SL** pphead) {

}
//��posǰ�����
void SLInsert(SL** pphead, SL* pos, SLDataType x) {
	//pphead�Ƕ���ָ�룬ָ����������ͷָ�룬���Ϊ�գ���ô�����û�������ˡ�
	assert(pos && pphead);
	//���Ҫposλ����ͷָ����ȣ�����ֱ��ʹ��ͷ��
	//���pos��λ����βָ�룬����ǰ��������������ͷָ������ĵط�������ͬ
	if (*pphead == pos) {
		SLPushFront(pphead, x);
	}
	else {
		SL* newnode = SLBuyCapacity(x);
		//��ָ����ָ��pos�Ľ�㣬��posǰ��һ�����
		SL* pre_pos = *pphead;

		//����
		while (pre_pos->next != pos) {
			pre_pos = pre_pos->next;
		}
		//���½���ָ����ָ��pos
		//��pos����ǰһ������ָ����ָ���½��
		newnode->next = pos;
		pre_pos->next = newnode;
	}
}
//��pos�������
void SLInsertAfter(SL* pos, SLDataType x) {
	assert(pos);
	//posָ���ͷ���β������ʱ����������������ͬ
	//1. ��Ϊ���ں�����룬����ͷ�������ԶԴ�û��һ��Ӱ��
	//2. ���pos��β������Ҳû�й�ϵ����Ϊ��Ҫ�Ȱ��½���ָ����ָ��posָ����ָ���λ�ã�
	//��β���Ϊ��ʱ����pos->nextΪ�գ�newnode->next = pos->next�ȼ���newnode->next = NULL
	//��ȫû��Ӱ�죬��Ϊ��β�ϲ���ʱnewnode�����㱾������β��㣬ָ�����Ȼָ��NULL
	SL* newnode = SLBuyCapacity(x);
	//���½��ָ��pos����һ����㣬����pos���������
	newnode->next = pos->next;
	//�ð�pos����һλ����Ϊ�½�㣬����������
	pos->next = newnode;
}
//ɾ��posλ��
void SLErase(SL** pphead, SL* pos) {
	assert(*pphead && pos);
	//���ͷָ���Ҫɾ����λ�õ�ָ����ȣ�ֱ�ӵ���ͷɾ����
	if (*pphead == pos) {
		SLPopFront(pphead);
	}
	//λ��ָ����ͷָ�벻������������������
	// 1. �ҵ�posǰһ��ָ��pre_pos
	// 2. ��pre_pos��ָ����ָ��pos��ָ���򣬾���pos������һ�����
	// ����pre_pos->next = pos->next;
	// 3. ��pos�ͷ�
	// ���е�posΪβָ��ʱ��pos->next == NULL��
	// ����pre_pos->next = pos->next�ȼ���pre_pos->next = NULL���ʿ��԰�posΪβָ��������һ���������
	else {
		SL* pre_pos = *pphead;
		while (pre_pos->next != pos) {
			pre_pos = pre_pos->next;
		}
		pre_pos->next = pos->next;
		free(pos);
	}
}
//ɾ��pos�����λ��
void SLEraseAfter(SL* pos) {
	//posΪβ���ʱ������û�н�㣬ɾ����û������
	//����ֻ�ܵ�β����ǰһ�����
	assert(pos && pos->next);
	//pos��λ�ò�Ӱ���ɾ������
	//ֱ�Ӱ�pos��ָ����ָ��pos->next��ָ���򼴿�
	SL* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
}


//��ӡ
void SLPrint(SL* phead) {
	assert(phead);
	SL* tail = phead;
	while (tail) {
		printf("%d ", tail->data);
		tail = tail->next;
	}
}











//�ϰ��β���ͷ��
////β��
//void SLPushBack(SL** pphead, SLDataType x) {
//	//1. ����ռ�
//	SL* newnode = (SL*)malloc(sizeof(SL));
//	//�ж��Ƿ����ɹ�
//	if (newnode == NULL) {
//		printf("Malloc Failed\n");
//		exit(-1);
//	}
//	//��ֵ�����
//	newnode->data = x;
//	//�óɿգ������β���ı�־
//	newnode->next = NULL;
//
//	//2. ������
//	//���ͷָ���ǿյľͰ�����ڵ��ͷָ��
//	if (*pphead == NULL) {
//		*pphead = newnode;
//	}
//	//���������Ԫ�أ�����β��㣬Ȼ���newnode����ȥ
//	else {
//		//��ͷ��ʼ���±�����ֱ��tail->next == NULL����ʱtail����β���
//		SL* tail = *pphead;
//		while (tail->next) {
//			tail = tail->next;
//		}
//		//�ҵ�β���֮�󣬿�ʼ�����ݣ���tail->next��Ϊnewnode��Ȼ���newnode->next�ÿ�
//		tail->next = newnode;
//		//newnode->next = NULL;
//	}
//}
//
//
////ͷ��
//void SLPushFront(SL** pphead, SLDataType x) {
//	//����ռ�
//	SL* newnode = (SL*)malloc(sizeof(SL));
//	if (newnode == NULL) {
//		printf("Malloc Failed\n");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//
//	//ͷ�ڵ�Ϊ�գ����½�㸳����
//	if (*pphead == NULL) {
//		*pphead = newnode;
//	}
//	//����Ϊ�գ���ֱ�Ӱ��½��ӵ���һ������ϣ�Ȼ����ͷָ��ָ���½��
//	else {
//		newnode->next = *pphead;
//		*pphead = newnode;
//		//���Ǳջ���
//		//����Ĵ��󣬱�׼�����
//		//(*pphead)->next = newnode;
//	}
//}