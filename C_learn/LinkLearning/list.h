/*
 * list.h
 *
 *  Created on: 2021��10��7��
 *      Author: wn
 */

#ifndef C_LEARN_LINKLEARNING_LIST_H_
#define C_LEARN_LINKLEARNING_LIST_H_

#include <stdlib.h>
#define MaxStrNum 20

//����
typedef struct Data
{
	int x;
	int y;
	char ch[MaxStrNum];  //�ַ���
	int color;    //��ɫ
};

//�ڵ�
typedef struct Node
{
	Data data;  //����
	Node *pnext;
};

//����
typedef struct List
{
	Node *pfront; //��һ���ڵ��ָ��
	Node *prear; //���һ���ڵ��ָ��
	int count; //�����ܵĽڵ���
};


int ListInit(List **ppList);
int IsEmpty(List *plist);
void InserListTail(List *plist, Node *pnode);
void TraverList(List *plist, void(*Traver)(Node *pnode));

#endif /* C_LEARN_LINKLEARNING_LIST_H_ */
