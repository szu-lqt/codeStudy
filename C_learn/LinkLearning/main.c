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

//����-->�ڵ�-->����

int main()
{
	initgraph(1200,800);
	List *plist; //����һ������ָ��
	ListInit(&plist); //��ʼ������
	Node *pnode;  //����һ���ڵ�
	while(1)
	{
		//�����ڵ�
		pnode = (Node *)malloc(sizeof(Node));
		pnode->data.x = rand()%1200;   //x: 0-1199
		pnode->data.y = 0;
		pnode->data.color = RGB(rand()%255, rand()%255, rand()%255);
		int n = rand()%10+5;   //n: 5-14
		for (int i=0; i<n; i++)
		{
			pnode->data.ch[i] = rand()%26 + 65 ;  //�����26����д��ĸ��A~Z��
		}
		pnode->data.ch[n] = '\0';
		pnode->pnext = NULL;
		//��ӽڵ�
		InserListTail(plist,pnode);
		//��ʾ����
		TraverList(plist,ShowData);
		//�ƶ�����
		TraverList(plist,MoveData);

		Sleep(100);  //�ȴ�100����
	}

	return 0;
}


