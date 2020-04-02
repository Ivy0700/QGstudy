#include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L)//链表初始化
	{
		 int num;
		 int d =0;
		 int upperbound = 100;
		 int lowerbound = 0;
		printf("请输入结点的个数\n");
		inputvalue(&num,upperbound,lowerbound);
		printf("请输入数值\n");
		LinkedList Node = (LinkedList)malloc(sizeof(LNode));
		Node->next=NULL;
		*L = Node;
		LinkedList temp = *L;
		inputvalue(&d,upperbound,lowerbound);
		Node->data =d;
		for(int i=1;i<num;i++){

			Node=(LinkedList)malloc(sizeof(LNode));
			inputvalue(&d,upperbound,lowerbound);
			Node->data = d;
			Node->next=NULL;
			temp->next=Node;
			temp=Node;
		}
			return SUCCESS;
		}


/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p==NULL||q==NULL){
			return ERROR;
		}else{
			q->next=p->next;
			p->next=q;
		}
		return SUCCESS;
		}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
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
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {       //查找数值
    LinkedList p=L;
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
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
	Status ReverseList(LinkedList *L){
    LinkedList current=*L;
	if(current == NULL){
		return ERROR;
	}
		LinkedList prev=NULL;
		LinkedList nex=NULL;
		while(current!=NULL){
			nex=current->next;
			current->next=prev;
			prev=current;
			current=nex;
		}
		*L=prev;
        return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
	Status IsLoopList(LinkedList L) {
		LinkedList slow=L;
		LinkedList fast=L;
		while(slow&&fast&&fast->next){
			slow=slow->next;
			fast=fast->next->next;
			if(fast==slow){
				return SUCCESS;
			}

		}
		return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
void ReverseEvenList(LinkedList *L) {
		LinkedList current = *L;
		LinkedList prev = NULL;
		while(current!=NULL&&current->next!=NULL){
			LinkedList temp = current->next->next;
			current->next->next = current;
			if(prev == NULL){
				*L = current->next;
			}
			else{
				prev->next =current->next;
			}
			current->next=temp;
			prev=current;
			current=temp;
		}

	}



/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
		LinkedList fast=*L;
		LinkedList slow=*L;
		//若结点个数为奇数，则获得到中间结点的地址，若结点个数为偶数，指向中间两个的第一个结点
		while(fast!=NULL&&fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		return slow;
}

}
/**
 *  	@name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param	     : L(the head node)
 *	@return	     : Status
 *  	@notice      : None
 */
	Status IsLoopList(LinkedList L) {
		LinkedList slow=L;
		LinkedList fast=L;
		while(slow&&fast&&fast->next){
			slow=slow->next;
			fast=fast->next->next;
			if(fast==slow){
				return SUCCESS;
			}

		}
		return ERROR;
}
