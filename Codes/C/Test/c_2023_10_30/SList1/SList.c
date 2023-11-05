#include "SList.h"

//��ʼ��
void SLTInit(SLTNode** pphead) {
	*pphead = NULL;
}
//����ռ䣬ֻ��Ҫxһ����������
SLTNode* SLTBuyCapacity(SLTDataType x) {
	//1. ����ռ�
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
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
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	//���÷�����ĺ���
	SLTNode* newnode = SLTBuyCapacity(x);
	
	//�ж�ͷ����Ƿ�Ϊ��
	//1. Ϊ�վͰ��½�㸳��ͷ���
	//2. ��Ϊ�վ���β��㣬Ȼ����½�����β���ĺ���
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SLTNode* tail = *pphead;
		//tail->next��tail��ָ���򣬴�tail��ָ����Ϊ�յ�ʱ�򣬾͵�β����ˣ�ָ����Ϊ����β���ı�־
		while (tail->next) {
			tail = tail->next;
		}
		//��tail->next��Ϊnewnode����Ϊnewnode�ڷ���ռ�ĺ�������SLTBuyCapacity()�У�ָ�����Ѿ�����Ϊ���ˣ��������������ٴ��ÿա�
		tail->next = newnode;
	}
}
//2. �°��ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	//������
	SLTNode* newnode = SLTBuyCapacity(x);
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
void SLTPopBack(SLTNode** pphead) {

}
//ͷɾ
void SLTPopFront(SLTNode** pphead) {

}
//��posǰ�����
void SLTInsert(SLTNode ** pphead, SLTNode * pos, SLTDataType x) {
	//pphead�Ƕ���ָ�룬ָ����������ͷָ�룬���Ϊ�գ���ô�����û�������ˡ�
	assert(pos && pphead);
	//���Ҫposλ����ͷָ����ȣ�����ֱ��ʹ��ͷ��
	//���pos��λ����βָ�룬����ǰ��������������ͷָ������ĵط�������ͬ
	if (*pphead == pos) {
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* newnode = SLTBuyCapacity(x);
		//��ָ����ָ��pos�Ľ�㣬��posǰ��һ�����
		SLTNode* pre_pos = *pphead;
		
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
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	//posָ���ͷ���β������ʱ����������������ͬ
	//1. ��Ϊ���ں�����룬����ͷ�������ԶԴ�û��һ��Ӱ��
	//2. ���pos��β������Ҳû�й�ϵ����Ϊ��Ҫ�Ȱ��½���ָ����ָ��posָ����ָ���λ�ã�
	//��β���Ϊ��ʱ����pos->nextΪ�գ�newnode->next = pos->next�ȼ���newnode->next = NULL
	//��ȫû��Ӱ�죬��Ϊ��β�ϲ���ʱnewnode�����㱾������β��㣬ָ�����Ȼָ��NULL
	SLTNode* newnode = SLTBuyCapacity(x);
	//���½��ָ��pos����һ����㣬����pos���������
	newnode->next = pos->next;
	//�ð�pos����һλ����Ϊ�½�㣬����������
	pos->next = newnode;
}
//ɾ��posλ��
void SLTErase(SLTNode* pos) {

}
//ɾ��pos�����λ��
void SLTEraseAfter(SLTNode* pos) {

}















//�ϰ��β���ͷ��
////β��
//void SLTPushBack(SLTNode** pphead, SLTDataType x) {
//	//1. ����ռ�
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
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
//		SLTNode* tail = *pphead;
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
//void SLTPushFront(SLTNode** pphead, SLTDataType x) {
//	//����ռ�
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
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