#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_SIZE 64

// CREATE THE QUEUE
Queue CreateQueue() {
	Queue Q = malloc(sizeof(struct QueueRecord));
	Q->Array = malloc(sizeof(int*) * MAX_SIZE);
	InitQueue(Q);
	return Q;
}

// INIT THE QUEUE
void InitQueue(Queue Q) {
	Q->Front = -1;
	Q->Rear = -1;
}

// ENQUEUE AND CHECK IS IT IS FULL
void Enqueue(int x, Queue Q) {

	if (!isFull(Q)) {

		Q->Array[Q->Rear % MAX_SIZE] = x;
		++Q->Rear;

	} else {
		printf("Queue is full\n");
		abort();
	}
}

// DEQUEUE AND CHECK
void Dequeue(Queue Q) {

	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		abort();
	} else {
		++Q->Front;
	}
}

// READ FROM THE QUEUE
int Front(Queue Q) {

	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		abort();
	} else
		return Q->Array[(Q->Front) % MAX_SIZE];
}

int isFull(Queue Q) {

	int Rear = Q->Rear;
	int Front = Q->Front;

	return (Rear - MAX_SIZE == Front);
}

int isEmpty(Queue Q) {

	int Rear = Q->Rear;
	int Front = Q->Front;

	return (Rear == Front);
}

// DELETE THE QUEUE
void DisposeQueue(Queue Q) {

	if (Q) {
		free(Q->Array);
		free(Q);
	}
}
