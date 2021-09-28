#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"
static void CopyToNode(Item item, Node* pn);
static void CopyToItem(Node* pn, Item* pi);
void InitializeQueue(Queue* pq)
{
	pq->front = pq->rear = NULL;
	pq->item = 0;
}
bool QueueIsFull(const Queue* pq)
{
	if (pq->item == MAXQUEUE)
		return true;
	else 
		return false;

}
bool QueueIsEmmpty(const Queue* pq)
{
	if (pq->item == 0)
		return true;
	else
		return false;
}
int QueueItemCount(const Queue* pq)
{
	return pq->item;
}
bool EnQueue(Item item, Queue* pq)
{
	Node* pnew;
	if (QueueIsFull(pq))
		return false;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		exit(1);
	CopyToNode(item,pnew);
	pnew->next = NULL;
	if (QueueIsEmmpty)
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->item++;
	return true;
}
bool DeQueue(Item *pitem, Queue* pq)
{
	Node* pt;
	if (QueueIsEmmpty)
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->item--;
	if (pq->item == 0)
		pq->rear = NULL;
	return true;
}
void EmptyTheQueue(Queue* pq)
{
	Item dummy;
	while (!QueueIsEmmpty(pq))
		DeQueue(&dummy, pq);
}
static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}
static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}