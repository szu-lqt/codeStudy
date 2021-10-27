/*
 * list.c
 *
 *  Created on: 2021��10��7��
 *      Author: wn
 */

#include "list.h"

//��ʼ������  �ɹ�����1��ʧ�ܷ���0
int ListInit(List **ppList)
{
	*ppList = (List *)malloc(sizeof(List));
	if (NULL==*ppList)
		return 0;
	else
	{
		(*ppList)->pfront = NULL;
		(*ppList)->prear = NULL;
		(*ppList)->count = 0;
	}
	return 1;
}

//�ж������Ƿ�Ϊ��

int IsEmpty(List *plist)
{
	if (0==plist->count)
		return 1;
	else
		return 0;
}

//��plist�������ڵ�    β�巨
void InserListTail(List *plist, Node *pnode)
{
	if (IsEmpty(plist))
	{
		plist->pfront = pnode;
	}
	else
	{
		plist->prear->pnext = pnode;
	}
	plist->prear = pnode;
	plist->count++;
}

//��������   ���ӿ�(�����������\ɾ\��\��)
//����plist�������  ����ָ��
void TraverList(List *plist, void(*Traver)(Node *pnode))
{
	Node *ptemp = plist->pfront;  //ptempָ���һ���ڵ�
	int listSize = plist -> count; //��ǰ������еĽڵ���
	while (listSize)
	{
		Traver(ptemp);
		ptemp = ptemp->pnext;
		listSize--;
	}
}
