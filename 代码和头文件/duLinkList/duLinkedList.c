#include "../head/duLinkedList.h"
extern LinkedList L;
extern LinkedList find;
extern LinkedList mid;
/*如果输入的数值超过界限*/
void inputvalue(ElemType *element,ElemType upperbound,ElemType lowerbound){
		int number;
		scanf("%d",&number);
		while(number < lowerbound||number > upperbound){
			fflush(stdin);	//避免输入char型导致无限循环
			printf("ERROR,请输入正确的数字\n");
			scanf("%d",&number);
		}
		*element = number;
		printf("输入成功\n");
	}
  /**
 *  	@name        : void InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param	     : L(the head node)
 *	@return	     : 
 *  	@notice      : None
 */
 void InitList()//链表初始化
	{
		int num;
		 int d =0;
		 int lowerbound = -100;
		 int upperbound = 100;
		 printf("请输入结点的个数\n");

		inputvalue(&num,upperbound,lowerbound);
	LinkedList Node=(LinkedList)malloc(sizeof(LNode));
		L = Node;
	LinkedList temp = (LinkedList)malloc(sizeof(LNode));
		Node->prev=NULL;
		Node->next=NULL;
		printf("请输入数值\n");
		inputvalue(&d,100,-100);
		Node->data=d;
		temp = Node;

	for(int i = 1;i < num;i++){
		LinkedList Node=(LinkedList)malloc(sizeof(LNode));
		Node->next = NULL;
		Node->prev = temp;
		temp->next = Node;
		inputvalue(&d,100,-100);
		Node->data = d;
		temp=Node;
	}

	}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
		LinkedList temp=*L;
		if((*L)==NULL){
				printf("The list is empty.There is no need to destroy the list.\n");
				return;
			}
		LinkedList temp1;
		while(temp!=NULL){
			temp1=temp->next;//储存下一个结点的地址
			free(temp);
			temp=temp1;//获得下一个结点的地址
		}
		*L=NULL;
		printf("\nThe list has been destroyed.\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(LNode *p, LNode *q) {
	if(p==NULL||q==NULL){
			return ERROR;
		}
		else if(p==L){
			L=q;
			q->next =p;
			p->prev=q;
		}
		else{
			q->prev = p->prev;
			p->prev->next =q;
			q->next = p;
			p->prev = q;
		}
		return SUCCESS;
}

/**
 *  	@name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param	     : p, q
 *	@return	     : Status
 * 	 @notice     : None
 */
	Status InsertList(LNode *p, LNode *q) {
	if(p==NULL||q==NULL){
			return ERROR;
		}
		else{
			p->next->prev = q;
			q->prev = p;
			q->next=p->next;
			p->next=q;
		}
		return SUCCESS;
		}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
	Status DeleteList(LNode *p, ElemType *e) {
		LinkedList temp;
		if(p==NULL){
			return ERROR;//指针为空，删除失败
		}
		else{
		temp = p->next;
		p->next=p->next->next;//p的next储存p下一个结点的next的地址
		*e=p->next->data;
		free(temp);//删除p的下一个结点
		return SUCCESS;
		}
}

/**
 *  	@name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param	     : L(the head node), visit
 *	@return	     : None
 *  	@notice      : None
 */
 void TraverseList(LinkedList temp){
		//递归结束条件
		if(temp==NULL){
			printf("\n");
			return;
		}
			printf("%d ",temp->data);
			TraverseList(temp->next);//递归
}

/**
 * 	@name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param	     : L(the head node), e
 *	@return	     : Status
 *  	@notice      : None
 */
 Status SearchList(LinkedList *L, ElemType e) {       //查找数值
		LinkedList p=*L;
		while(p!=NULL){
		if(p->data==e){
		find=p;
		p=NULL;
		return SUCCESS;
		}
		p=p->next;
	}
		return ERROR;       //没找到
	}

/**
 *  	@name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param	     : L(the address of head node)
 *	@return	     : Status
 *  	@notice      : None
 */

 Status ReverseList(LinkedList *L) {
		LNode* temp=*L;
		LNode* temp1;
		LNode* nex;

		if(*L==NULL){
			return ERROR;
		}
		while(temp->next!=NULL){
			nex=temp->next;//获得下一个node的地址
			temp1=temp->prev;
			temp->prev=temp->next;
			temp->next=temp1;//进行next和prev的交换
			temp=nex;
		}
		temp->next=temp->prev;
		temp->prev=NULL;
		*L=temp;
}
