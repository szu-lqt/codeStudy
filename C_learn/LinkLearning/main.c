#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <graphics.h>

void ShowData(Node *pnode)
{
	// outtextxy(pnode->data.x, pnode->data.y, pnode->data.ch);
	for (int i = 0; i < MaxStrNum; i++)
	{
		if(pnode->data.ch[i] != '\0')
		{
			settextcolor(pnode->color);
			outtextxy(pnode->data.x, pnode->data.y-i*18, pnode->data.ch[i]);
		}
		else
			break;
	}
}

void MoveData(Node *pnode)
{
	pnode->data.y++;
}

//数据-->节点-->链表

int main()
{
	initgraph(1200,800);
	List *plist; //定义一个链表指针
	ListInit(&plist); //初始化链表
	Node *pnode;  //定义一个节点
	while(1)
	{
		//创建节点
		pnode = (Node *)malloc(sizeof(Node));
		pnode->data.x = rand()%1200;   //x: 0-1199
		pnode->data.y = 0;
		pnode->data.color = RGB(rand()%255, rand()%255, rand()%255);
		int n = rand()%10+5;   //n: 5-14
		for (int i=0; i<n; i++)
		{
			pnode->data.ch[i] = rand()%26 + 65 ;  //随机的26个大写字母（A~Z）
		}
		pnode->data.ch[n] = '\0';
		pnode->pnext = NULL;
		//添加节点
		InserListTail(plist,pnode);
		//显示链表
		TraverList(plist,ShowData);
		//移动链表
		TraverList(plist,MoveData);

		Sleep(100);  //等待100毫秒
	}

	return 0;
}


