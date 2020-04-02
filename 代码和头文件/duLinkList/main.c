#include "duLinkedList.h"
#include "duLinkedList.c"
#include<stdio.h>
#include<stdlib.h>
LinkedList find = NULL;//查找数值后得到的地址
	LinkedList mid;//查找中间的节点
	LinkedList L;
void Print(){
	printf("*************************************\n");
	printf("**************双链表ADT**************\n");
	printf("*************************************\n");
	printf("*           0 退出                  *\n");
	printf("*           1 初始化链表            *\n");
	printf("*           2 删除链表              *\n");
	printf("*           3 在查找的结点后插入节点*\n");
	printf("*           4 在查找的结点前插入节点*\n");
	printf("*           5 删除节点              *\n");
	printf("*           6 遍历链表              *\n");
	printf("*           7 查找数值              *\n");
	printf("*           8 反转链表              *\n");
	printf("*************************************\n");
	}
   
int main()
{	L=NULL;
	Print();
	printf("请选择功能(一次一个)\n");
	int choice;
	int upperbound1 = 8;
	int lowerbound1 = 0;
	inputvalue(&choice,upperbound1,lowerbound1);
	while(choice){
		switch(choice){
			case 0:
			choice = 0;
			printf("已退出\n");
			break;
			case -1:
			printf("\n请选择功能:\n");
			inputvalue(&choice,upperbound1,lowerbound1);
			break;
			case 1:
			//初始化
				InitList();
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
					q->prev=NULL;
					q->next=NULL;
				if(InsertBeforeList_DuL(find,q)){
						printf("插入成功\n");
				}
			}
				choice=-1;
				break;
			case 5:
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

			case 6:
			//遍历链表
			printf("链表中的数值为：\n");
				TraverseList(L);
				choice = -1;
				break;
			case 7:
			//查找数值
				printf("请输入要查找的数值\n");
				ElemType el;
				scanf("%d",&el);
				if(SearchList(&L,el)){
					printf("查找成功，查找的数值对应节点的地址已储存成功\n");
				}else{
					printf("查找失败\n");
				}
				choice = -1;
				break;
			case 8:
			//反转链表
				ReverseList(&L);
				printf("反转链表\n");
				choice = -1;
				break;
			default:
				fflush(stdin);
			printf("请输入正确的数字\n");
			scanf("%d",&choice);
		}
		}
			printf("已退出\n");
			system("pause");
}
