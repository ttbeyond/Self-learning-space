#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<string.h>

// ˳���Ķ�̬�洢 
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _array; // ָ��̬���ٵ����� 
	size_t _size; // ��Ч���ݸ��� 
	size_t _capacity; // �����ռ�Ĵ�С 
}SeqList;

// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void CheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);
int SeqListSize(SeqList* ps); //��Ч����
SLDataType SeqListAt(SeqList* ps,size_t x);//����˳���


void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//posλ�ò���ֵΪx�Ľڵ�
void SeqListErase(SeqList* ps, size_t pos);

void SeqListRemove(SeqList* ps, SLDataType x);  //�Ƴ�ֵΪx�Ľڵ�
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);


// ��չ������ʵ�� 
void SeqListBubbleSort(SeqList* ps);//��˳������ð������
int SeqListBinaryFind(SeqList* ps, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x);

