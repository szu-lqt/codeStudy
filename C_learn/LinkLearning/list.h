/*
 * list.h
 *
 *  Created on: 2021年10月7日
 *      Author: wn
 */

#ifndef C_LEARN_LINKLEARNING_LIST_H_
#define C_LEARN_LINKLEARNING_LIST_H_

#include <stdlib.h>
#define MaxStrNum 20

//数据
typedef struct Data
{
	int x;
	int y;
	char ch[MaxStrNum];  //字符串
	int color;    //颜色
};

//节点
typedef struct Node
{
	Data data;  //数据
	Node *pnext;
};

//链表
typedef struct List
{
	Node *pfront; //第一个节点的指针
	Node *prear; //最后一个节点的指针
	int count; //链表总的节点数
};


int ListInit(List **ppList);
int IsEmpty(List *plist);
void InserListTail(List *plist, Node *pnode);
void TraverList(List *plist, void(*Traver)(Node *pnode));

#endif /* C_LEARN_LINKLEARNING_LIST_H_ */
