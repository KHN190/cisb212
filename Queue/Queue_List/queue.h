#ifndef _queue_h

typedef struct QueueRecord * Queue;
struct QueueRecord {
	int x;
	Queue next;
};

Queue CreateQueue();

Queue Enqueue(int x, Queue Q);
Queue Dequeue(Queue Q);
int Pop(Queue Q);

int isFull(Queue Q);
int isEmpty(Queue Q);

void DisposeQueue(Queue Q);

#endif _queue_h