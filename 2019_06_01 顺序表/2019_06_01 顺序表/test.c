#include"seqlist.h"

void Test()
{
	SeqList ps;
	SeqListInit( &ps );
	SeqListPushBack(&ps,1);
	SeqListPushBack(&ps,2);
	SeqListPushBack(&ps,3);
	SeqListPushBack(&ps,4);
	SeqListPushFront(&ps, 0);
	SeqListPopBack(&ps);
	SeqListPopFront(&ps);

	SeqListInsert(&ps, 0, 20);
	SeqListErase(&ps, 3);

	SeqListBubbleSort(&ps);//����
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");


	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 2);
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");

	SeqListRemove(&ps, 2);//ɾ����һ����
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");

	SeqListRemoveAll(&ps, 2);//ɾ�����е�2
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");

	printf("%d \n",SeqListBinaryFind(&ps, 20));//���ֲ��� �ҵ�����λ�� �Ҳ�����ӡ���Ҳ���
	SeqListDestory(&ps);


}

int main()
{
	Test();
	system("pause");
	return 0;
}