#ifndef _queue_h

struct QueueRecord {
	int Front, Rear;
	int * Array;
};
typedef struct QueueRecord * Queue;

Queue CreateQueue();
void InitQueue(Queue Q);

void Enqueue(int x, Queue Q);
void Dequeue(Queue Q);
int Front(Queue Q);

int isFull(Queue Q);
int isEmpty(Queue Q);

void DisposeQueue(Queue Q);

#endif _queue_h