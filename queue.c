#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int num;
	struct Node* next;	
}Node;

typedef struct QNode
{
	Node *front,*rear;
}QNode;

int init (QNode*s)
{
	Node *node = (Node*)malloc(sizeof(Node));
	if(!node)
	{
		printf("erro\n");
		return -1;
	}
	s->front = s->rear = node;
	return 1;
 }
 
int insert(QNode* s,int i)
{
	Node *node = (Node*)malloc(sizeof(Node));
	if(!node)
	{
		printf("erro\n");
		return -1;
	}
	node->num = i;
	node->next = NULL;
	s->rear->next = node;
	s->rear = node;
	return 1;
 } 
 
 int put(QNode* s)
 {
 	int n;
 	Node* node;
 	if(s->front->next == NULL)
 	{
 		s->rear = s->front;
 		return -1;
	}
 	node = s->front->next;
 	s->front->next = node->next;
 	n = node->num;
 	free(node);
 	return n;
 }
 
int main()
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	init(s);
	return 0;
}
