#include "linkedList.h"
#include "linkedList.c"
#include<stdio.h>
#include<stdlib.h>
LinkedList find = NULL;//查找数值后得到的地址
	LinkedList mid;//查找中间的节点
	LinkedList L;
void Print(){
	printf("*************************************\n");
	printf("**************单链表ADT**************\n");
	printf("*************************************\n");
	printf("*           0 退出                  *\n");
	printf("*           1 初始化链表            *\n");
	printf("*           2 删除链表              *\n");
	printf("*           3 插入节点              *\n");
	printf("*           4 删除节点              *\n");
	printf("*           5 遍历链表              *\n");
	printf("*           6 查找数值              *\n");
	printf("*           7 反转链表              *\n");
	printf("*           8 判断链表是否有环      *\n");
	printf("*           9 在链表中查找中间节点  *\n");
	printf("*           10 单链表奇偶数调换     *\n");
	printf("*************************************\n");

	}
    int main()
{	L=NULL;
	Print();
	printf("请选择功能(一次一个)\n");
	int choice;
	int upperbound1 = 10;
	int lowerbound1 = 0;
	inputvalue(&choice,upperbound1,lowerbound1);
	while(choice){
		switch(choice){
			case 0:
			choice = 0;
			printf("已退出\n");
			break;
			case -1:
			printf("\n请选择功能(0表示退出):\n");
			inputvalue(&choice,upperbound1,lowerbound1);
			break;
			case 1:
			//初始化
				if(InitList(&L)){
					printf("初始化成功");
				}
				else{
					printf("初始化失败");
				}
				choice = -1;
				break;
			case 2:
			//删除链表
				DestroyList(&L);
				choice = -1;
				break;
			case 3:
			//插入节点
				printf("请使用插入节点前使用查找数值功能确定查找的位置\n");


				if(L==NULL){
					printf("头指针为空，无法插入\n");
				}else if(find==NULL){
				printf("指针为空，无法插入\n");
				}
				else{
					printf("请输入要插入的数值\n");
					int input;
					scanf("%d",&input);
					LNode *q=(LNode*)malloc(sizeof(LNode));
					q->data=input;
					q->next=NULL;
				if(InsertList(find,q)){
						printf("插入成功\n");
				}
			}
				choice = -1;
				break;
			case 4:
			//删除节点
				printf("删除的结点的位置前请使用查找数值功能确定查找的位置\n");
				ElemType e;
				if(DeleteList(find,&e)){
					printf("删除成功\n");
					printf("删除的结点对应的值为%d",e);
				}else{
					printf("删除失败\n");
				}
				choice = -1;
				break;

			case 5:
			//遍历链表
			printf("链表中的数值为：\n");
				TraverseList(L);
				choice = -1;
				break;
			case 6:
			//查找数值
				printf("请输入要查找的数值\n");
				ElemType el;
				scanf("%d",&el);
				if(SearchList(L,el)){
					printf("查找成功，查找的数值对应节点的地址已储存成功\n");
				}else{
					printf("查找失败\n");
				}
				choice = -1;
				break;
			case 7:
			//反转链表
				if(ReverseList(&L)){
					printf("反转成功");
				}
				else{
					printf("反转失败");
				}
				choice = -1;
				break;
			case 8:
			//判断是否有环
				if(IsLoopList(L)){
					printf("有环\n");
				}
				else{
					printf("无环\n");
				}
				choice = -1;
				break;
			case 9:
			//在链表中查找中间节点
				mid=FindMidNode(&L);
				printf("查找到中间节点\n");
				choice = -1;
				break;
			case 10:
			//奇偶数调换
				if(L!=NULL){
				ReverseEvenList(&L);
				printf("奇偶数调换\n");
				}
				else{
				printf("头结点为空，请先初始化链表\n");
				}
				choice = -1;
			default:
				fflush(stdin);
			printf("请输入正确的数字\n");
			scanf("%d",&choice);
		}
		}
			printf("已退出\n");
			system("pause");
}