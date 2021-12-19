#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "human.h"
#include "str.h"

struct Node
{
	int data;
	struct Node* nextNode;
};

struct Node* CreateNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->nextNode = NULL;

	return node;
}

struct Node* InsertNode(struct Node* currentNode, int data)
{
	struct Node* temp = currentNode->nextNode;

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->nextNode = temp;
	currentNode->nextNode = node;

	return node;
}

void DestroyNode(struct Node* target, struct Node* head)
{
	
	struct Node* cur = head;

	if (cur == target)
	{
		free(target);
		return;
	}

	while (cur)
	{
		if (cur->nextNode == target)
		{
			cur->nextNode = target->nextNode;
		}
		cur = cur->nextNode;
	}
	free(target);

	return;
}

void PrintNodeFrom(struct Node* from) {
	/* from 이 NULL 일 때 까지,
	   즉 끝 부분에 도달할 때 까지 출력 */
	while (from) {
		printf("노드의 데이터 : %d \n", from->data);
		from = from->nextNode;
	}
}

int main()
{
	struct Node* Node1 = CreateNode(100);
	struct Node* Node2 = InsertNode(Node1, 200);
	struct Node* Node3 = InsertNode(Node2, 300);
	/* Node 2 뒤에 Node4 넣기 */
	struct Node* Node4 = InsertNode(Node2, 400);

	PrintNodeFrom(Node1);
	return 0;
	
}