/*
 * list.c
 *
 *  Created on: 2021年10月7日
 *      Author: wn
 */

#include "list.h"

//初始化链表  成功返回1，失败返回0
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

//判断链表是否为空

int IsEmpty(List *plist)
{
	if (0==plist->count)
		return 1;
	else
		return 0;
}

//往plist链表插入节点    尾插法
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

//遍历链表   留接口(方便链表的增\删\查\改)
//遍历plist这个链表  函数指针
void TraverList(List *plist, void(*Traver)(Node *pnode))
{
	Node *ptemp = plist->pfront;  //ptemp指向第一个节点
	int listSize = plist -> count; //当前链表具有的节点数
	while (listSize)
	{
		Traver(ptemp);
		ptemp = ptemp->pnext;
		listSize--;
	}
}
