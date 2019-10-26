#include"seqlist.h"

void SeqListInit(SeqList* ps)//��ʼ��
{
	assert(ps);
	ps->_array = NULL;
	ps->_size = ps->_capacity = 0;
	
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->_array != NULL)
	{
		free(ps->_array);    //�ͷſռ�
		ps->_array = NULL;   //�ÿ�psָ��
		ps->_size = 0;
		ps->_capacity = 0;
	}
}


void CheckCapacity(SeqList* ps)  //�������
{
	assert(ps);

	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (SLDataType*)realloc(ps->_array, sizeof(SLDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);

	ps->_array[ps->_size] = x;
	ps->_size++;
}
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	//����һ��
	//SeqListInsert(ps,0,x);//ͷ�� ͷɾ β�� βɾ �����Ե�������������
	assert(ps);
	//�������������Ų��һλ
	CheckCapacity(ps);
	size_t end = ps->_size;  //Ҫע��size_t���޷������Σ�������±߿���ʱҪע��
	while (end > 0)
	{
		ps->_array[end] = ps->_array[end-1];
		--end;
	}

	//��������
	ps->_array[0] = x;
	ps->_size++;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps&&ps->_size > 0); //Ҫ��֤������һ����ЧԪ��

	ps->_size--;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	size_t start = 0;
	while (start < ps->_size - 1)
	{
		ps->_array[start] = ps->_array[start + 1];
			++start;
	}
	ps->_size--;
}


int SeqListFind(SeqList* ps, SLDataType x)//��ֵ �ҵ������±�
{
	assert(ps);

	for (int i = 0; i < SeqListSize(ps); ++i)
	{
		if (ps->_array[i] == x)
			return i;
	}

	printf("�Ҳ���\n");
}



int SeqListSize(SeqList* ps)  //��Ч����
{
	assert(ps);
	return ps->_size;
}

SLDataType SeqListAt(SeqList* ps, size_t pos)// ����˳���ʱ��ʹ��
{
	assert(ps);
	return ps->_array[pos];
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//posλ�ò���ֵΪx�Ľڵ�
{
	assert(ps && pos <= ps->_size );

	CheckCapacity(ps);//�������
	//Ų������
	size_t end = ps->_size;
	while (end > pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	/*int end = ps->_size - 1;
	while (end >= (int)pos)//ע��Ƚϴ�Сʱ������������Ҫƥ��
	{
		ps->_array[end + 1] = ps->_array[end];
		--end;
	}*/

	//����
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->_size );

	size_t start = pos + 1;
	while (start < ps->_size)
	{
		ps->_array[start - 1] = ps->_array[start];
		++start;
	}

	ps->_size--;
}

void SeqListRemove(SeqList* ps, SLDataType x)  //�Ƴ���һ��ֵΪx�Ľڵ�
{
	assert(ps);

	for (int i = 0; i < SeqListSize(ps); ++i)
	{
		if (ps->_array[i] == x)
		{
			SeqListErase(ps, i);//ֱ��ɾ��
			break;
		}
	}

	printf("˳�����û�д�����\n");
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)//��posλ�ô���ֵ��Ϊx
{
	assert(ps && pos < ps->_size);
	ps->_array[pos] = x;
}



void SeqListBubbleSort(SeqList* ps)//��˳������ð������
{
	assert(ps);

	size_t end = ps->_size;
	while (end > 1)
	{
		int exchange = 0;//����������Ż�
		//����
		for (size_t i = 1; i < end; ++i)
		{
			if (ps->_array[i - 1]>ps->_array[i])
			{
				SLDataType ret = ps->_array[i - 1];
				ps->_array[i - 1] = ps->_array[i];
				ps->_array[i] =ret;
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
		--end;
	}
}
int SeqListBinaryFind(SeqList* ps, SLDataType x)  //���ֲ���
{
	assert(ps);

	size_t begin = 0;
	size_t end = ps->_size;

	while (begin < end)
	{
		size_t mid = begin + (end - begin) / 2;
		if (ps->_array[mid] < x)
			begin = mid + 1;
		else if (ps->_array[mid]>x)
			end = mid ;
		else
			return mid;
	}

	//�Ҳ��������
	printf("�Ҳ���\n");
}
//// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)//ɾ��˳��������е�x
{
	assert(ps);

	size_t index = 0;
	for (int i = 0; i < SeqListSize(ps); ++i)
	{
		if (ps->_array[i] != x)//���ֵ������x�͸���дһ�£���ȵĻ�index�Ͳ���ı�
		{
			ps->_array[index] = ps->_array[i];//�൱�ڸ���д
			++index;
		}
	}
	ps->_size = index;//����index��ֵ����ɾ����˳���ʣ�����Ч����
	return ps->_array[index];
}