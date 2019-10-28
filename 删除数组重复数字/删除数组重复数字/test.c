#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//示例 1 :
//
//给定数组 nums = [1, 1, 2],
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//
//你不需要考虑数组中超出新长度后面的元素。

int removeDuplicates(int* nums, int numsSize)//数组必须有序
{
	if (numsSize == 0)
	{
		return 0;
	}
	int i = 0;
	int j = 1;
	while (i<numsSize - 1)
	{
		if (nums[i] != nums[i + 1])
		{
			nums[j] = nums[i + 1];//修改
			j++;
		}
		i++;
	}
	return j;
}
int main()
{
	int arr[10] = {0,0,1,2,2,3,5,6};
	int ret = removeDuplicates(arr, 8);
	printf("%d\n", ret);
	system("pause");
	return 0;
}