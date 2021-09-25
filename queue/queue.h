#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUE_SIZE 10

/*class Queue*/
typedef struct Queue Queue;
struct Queue{
	int buffer[QUEUE_SIZE];
	int head;
	int size;
	int tail;
	int (*isFull)(Queue* const me);
	int (*isEmpty)(Queue* const me);
	int (*getSize)(Queue* const me);
	void (*insert)(Queue* const me, int k);
	int (*remove)(Queue* const me);
};

/*Constructors and Destructors*/
void Queue_init(Queue* const me, int(*isFullFunction)(Queue* const me),
			int (*isEmptyFunction)(Queue* const me),
			int (*getSizeFunction)(Queue* const me),
			void (*insertFunction)(Queue* const me, int k),
			int (*removeFunction)(Queue* const me));

void Queue_cleanup(Queue* const me);

/*Operations*/
int Queue_isFull(Queue* const me);
int Queue_isEmpty(Queue* const me);
int Queue_getSize(Queue* const me);
void Queue_insert(Queue* const me, int k);
int Queue_remove(Queue* const me);

Queue* Queue_create(void);
void Queue_destroy(Queue* const me);

#endif
