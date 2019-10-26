#include"seqlist.h"

void SeqListInit(SeqList* ps)//初始化
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
		free(ps->_array);    //释放空间
		ps->_array = NULL;   //置空ps指针
		ps->_size = 0;
		ps->_capacity = 0;
	}
}


void CheckCapacity(SeqList* ps)  //检查容量
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
	//方法一：
	//SeqListInsert(ps,0,x);//头插 头删 尾插 尾删 都可以调用这俩个函数
	assert(ps);
	//将数据整体向后挪动一位
	CheckCapacity(ps);
	size_t end = ps->_size;  //要注意size_t是无符号整形，因此在下边控制时要注意
	while (end > 0)
	{
		ps->_array[end] = ps->_array[end-1];
		--end;
	}

	//插入数据
	ps->_array[0] = x;
	ps->_size++;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps&&ps->_size > 0); //要保证至少有一个有效元素

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


int SeqListFind(SeqList* ps, SLDataType x)//找值 找到返回下标
{
	assert(ps);

	for (int i = 0; i < SeqListSize(ps); ++i)
	{
		if (ps->_array[i] == x)
			return i;
	}

	printf("找不到\n");
}



int SeqListSize(SeqList* ps)  //有效个数
{
	assert(ps);
	return ps->_size;
}

SLDataType SeqListAt(SeqList* ps, size_t pos)// 遍历顺序表时可使用
{
	assert(ps);
	return ps->_array[pos];
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//pos位置插入值为x的节点
{
	assert(ps && pos <= ps->_size );

	CheckCapacity(ps);//检查容量
	//挪动数据
	size_t end = ps->_size;
	while (end > pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	/*int end = ps->_size - 1;
	while (end >= (int)pos)//注意比较大小时俩个数的类型要匹配
	{
		ps->_array[end + 1] = ps->_array[end];
		--end;
	}*/

	//插入
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

void SeqListRemove(SeqList* ps, SLDataType x)  //移除第一个值为x的节点
{
	assert(ps);

	for (int i = 0; i < SeqListSize(ps); ++i)
	{
		if (ps->_array[i] == x)
		{
			SeqListErase(ps, i);//直接删除
			break;
		}
	}

	printf("顺序表中没有此数字\n");
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)//将pos位置处的值改为x
{
	assert(ps && pos < ps->_size);
	ps->_array[pos] = x;
}



void SeqListBubbleSort(SeqList* ps)//对顺序表进行冒泡排序
{
	assert(ps);

	size_t end = ps->_size;
	while (end > 1)
	{
		int exchange = 0;//加这个进行优化
		//单趟
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
int SeqListBinaryFind(SeqList* ps, SLDataType x)  //二分查找
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

	//找不到的情况
	printf("找不到\n");
}
//// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)//删除顺序表中所有的x
{
	assert(ps);

	size_t index = 0;
	for (int i = 0; i < SeqListSize(ps); ++i)
	{
		if (ps->_array[i] != x)//如果值不等于x就覆盖写一下，相等的话index就不会改变
		{
			ps->_array[index] = ps->_array[i];//相当于覆盖写
			++index;
		}
	}
	ps->_size = index;//最终index的值就是删除后顺序表还剩余的有效个数
	return ps->_array[index];
}