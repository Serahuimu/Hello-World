#include "SeqList.h"

//��ʼ������a��Ϊ�գ���size��capacity��Ϊ0
void SeqListInit(SL* pl)
{
    assert(pl);
    pl->a = NULL;
    pl->size = 0;
    pl->capacity = 0;
}

//���ٱ�
void SeqListDestory(SL* pl)
{
    assert(pl);
    free(pl->a);
    pl->a = NULL;
}

//��ӡ
void SeqListPrint(SL sl)
{
    assert(&sl);
    int i;
    for (i = 0; i < sl.size; i++) {
        printf("%d ", sl.a[i]);
    }
    printf("\n");
}

//����Ƿ���Ҫ����
void SeqListCheckCapacity(SL* pl)
{
    assert(pl);
    //Ԫ��Ϊ0���������˵��������Ҫ����
    if (pl->size == pl->capacity) {
        int newcapacity = pl->capacity == 0 ? 4 : pl->capacity * 2;
        SLDataType* tmp = (SLDataType*)realloc(pl->a, sizeof(SLDataType) * newcapacity);
        if (tmp == NULL) {
            printf("Realloc failed\n");
            exit(-1);
        }
        pl->a = tmp;
        pl->capacity = newcapacity;
    }
}


void SeqListPushBack(SL* pl, SLDataType x)
{
    assert(pl);
    SeqListCheckCapacity(pl);
    pl->a[pl->size++] = x;
    //������ôд
    // pl->a[pl->size] = x;
    // pl->size++;
}

void SeqListPushFront(SL* pl, SLDataType x)
{
    assert(pl);
    SeqListCheckCapacity(pl);
    //���ݸ���+1
    pl->size++;

    int i;
    for (int i = pl->size - 1; i >= 1; i--) {
        pl->a[i] = pl->a[i - 1];
    }
    pl->a[0] = x;

    ////Ҳ������ôд
    // int end = pl->size;
    // while (end != 0) {
    //     pl->a[end] = pl->a[end - 1];
    //     end--;
    // }
    // pl->a[0] = x;
    // pl->size++;

    //�����������͵��ڰѺ����Ԫ�ض�����˵�һ��Ԫ�ص�ֵ�ˡ����Ŷ����á�
    // //����
    // int i;
    // for (i = 0; i < pl->size; i++) {
    //     pl->a[i + 1] = pl->a[i];
    // }
}

//βɾ
void SeqListPopBack(SL* pl)
{
    assert(pl && pl->size > 0);
    pl->size--;
}

//ͷɾ
void SeqListPopFront(SL* pl)
{
    assert(pl && pl->size > 0);
    int i;
    for (i = 1; i < pl->size; i++) {
        pl->a[i - 1] = pl->a[i];
    }
    pl->size--;
}

//���ң��ҵ��˷����±꣬�Ҳ�������-1
int SeqListFind(SL pl, SLDataType x)
{
    assert(&pl);
    int i;
    for (i = 0; i < pl.size; i++) {
        if (pl.a[i] == x)
            return i;
    }
    if (i == pl.size) {
        return -1;
    }
}
//��pos������һ������
void SeqListInsert(SL* pl, int pos, SLDataType x)
{
    assert(pl && pos <= pl->size && pl->size >= 0);
    int end = pl->size;

    //������Ԫ�غ���һλ
    while (end > pos) {
        pl->a[end] = pl->a[end - 1];
        end--;
    }
    pl->a[pos] = x;
    pl->size++;
}
//ɾ��posλ�õ�����
void SeqListErase(SL* pl, int pos)
{
    assert(pl && pos >= 0 && pos < pl->size);
    int i = pos;
    //2 = 2 + 1, 3 = 3 + 1, 4 = 4 + 1
    while (i < pl->size - 1) {
        pl->a[i] = pl->a[i + 1];
        i++;
    }
    pl->size--;
}
//�޸�posλ�õ�����Ϊx
void SeqListModify(SL* pl, int pos, SLDataType x)
{
    assert(pl && pos >= 0 && pos < pl->size);
    pl->a[pos] = x;
}