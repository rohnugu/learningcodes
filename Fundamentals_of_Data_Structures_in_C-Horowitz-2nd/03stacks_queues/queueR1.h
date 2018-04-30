#include <stdlib.h>
#include <stdio.h>

typedef struct _element {
	int key;
	char value; /* other fields */
} element;

void errQueueFull(char* queuename) {
	printf("Queue Full Error! (%s)\n", queuename);
	exit(-1);
}

element errQueueEmpty(char* queuename) {
	printf("Queue Empty Error! (%s)\n", queuename);
	exit(-1);
	element empty;
	empty.key = 0;
	empty.value = '\0';
	return empty;
}

#define rear(queue)	 (rear_queue)
#define front(queue) (front_queue)
#define sz(queue)	 (sz_queue)

#define createQueue(queue,maxQueueSize)	element queue[maxQueueSize]; \
										int sz_queue = maxQueueSize;
										int rear_queue = -1; \
										int front_queue = -1;

#define isQueueEmpty(queue)	( front_queue == rear_queue )

#define isQueueFull(queue)  ( rear_queue == (sz_queue - 1) )

/* add an item to the queue */
#define addQueue(queue,item) if (isQueueFull(queue)) \
									errQueueFull("queue"); \
							 queue[++(rear_queue)] = item;

/* remove the front element of the queue */
#define delQueue(queue,item) ( (isQueueEmpty(queue)) ? (errQueueEmpty("queue")) : (queue[++(front__queue)]) )
