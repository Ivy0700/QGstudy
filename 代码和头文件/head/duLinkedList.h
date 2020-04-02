/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct Node{
		ElemType data;
		struct Node* prev;
		struct Node* next;
	}LNode,*LinkedList;



// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

void inputvalue(ElemType *element,ElemType upperbound,ElemType lowerbound);
/**
 *  	@name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param	     : L(the head node)
 *	@return	     : Status
 *  	@notice      : None
 */
void InitList();

/**
 *  	@name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param	     : L(the head node)
 *	@return	     : None
 *  	@notice      : None
 */
void DestroyList(LinkedList *L);


/**
 * 	@name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param	     : L(the address of head node), e
 *	@return	     : Status
 *  	@notice      : None
 */
Status SearchList(LinkedList *L, ElemType e);
/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**
 *  	@name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param	     : p, q
 *	@return	     : Status
 * 	 @notice     : None
 */
Status InsertList(LNode *p, LNode *q);


/**
 *  	@name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param	     : p, e
 *	@return	     : Status
 *  	@notice      : None
 */
Status DeleteList(LNode *p);

/**
 *  	@name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param	     : L(the head node), visit
 *	@return	     : None
 *  	@notice      : None
 */
void TraverseList(LinkedList L);

/**
 *  	@name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param	     : L(the address of head node)
 *	@return	     : Status
 *  	@notice      : None
 */
Status ReverseList(LinkedList *L);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
