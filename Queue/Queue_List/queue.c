#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static Queue Front = NULL, Rear = NULL;

Queue CreateQueue() {
	Front = malloc(sizeof(struct QueueRecord));
	Front->next = NULL; Rear = Front; Front->x = -1;
	return Front;
}

Queue Enqueue(int x, Queue Q) {

	Q->next = malloc(sizeof(struct QueueRecord));
	Q = Q->next; Q->next = NULL;

	if(Rear==Front && Front->x < 0)
		Front = Q;

	Q->x = x;
	Rear = Q;
	return Rear;
}

Queue Dequeue(Queue Q) {

	Queue t = Front;

	if (isEmpty(Q)) {
		printf("dequeue: Queue is empty\n");
		abort();
	} else {
		Front = Front->next;
		free(t);
	} return Rear;
}

int isFull(Queue Q) {
	// printf("Queue can never be full\n");
	return 0;
}

int isEmpty(Queue Q) {
	return (!Front);
}

int Pop(Queue Q) {
	if (Front)
		return Front->x;
	else
		printf("pop: Queue is empty\n");
	abort();
}

void DisposeQueue(Queue Q) {

	while(Front) {
		Queue t = Front;
		Front = Front->next;
		free(t);
	}
}
