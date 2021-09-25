#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Queue_init(Queue* const me, int(*isFullFunction)(Queue* const me),
			int (*isEmptyFunction)(Queue* const me),
			int (*getSizeFunction)(Queue* const me),
			void (*insertFunction)(Queue* const me, int k),
			int (*removeFunction)(Queue* const me)){
	/*initialize attributes*/
	me->head = 0;
	me->size = 0;
	me->tail = 0;
	/*initialize member function pointers*/
	me->isFull = isFullFunction;
	me->isEmpty = isEmptyFunction;
	me->getSize = getSizeFunction;
	me->insert = insertFunction;
	me->remove = removeFunction;

}

void Queue_cleanup(Queue* const me){

}


int Queue_isFull(Queue* const me){
	return (me->head+1) % QUEUE_SIZE == me->tail;
}

int Queue_isEmpty(Queue* const me){
	return (me->head == me->tail);
}

int Queue_getSize(Queue* const me){
	return me->size;
}

void Queue_insert(Queue* const me, int k){
	if(!me->isFull(me)){
		me->buffer[me->head] = k;
		me->head = (me->head+1) % QUEUE_SIZE;
		++me->size;
	}
}

int Queue_remove(Queue*const me){
	int value = -9999;
	if(!me->isEmpty(me)){
		value = me->buffer[me->tail];
		me->tail = (me->tail+1) % QUEUE_SIZE;
		--me->size;
	}
	return value;
}

Queue* Queue_create(void){
	Queue* me = (Queue*)malloc(sizeof(Queue));
	if(me != NULL){
		Queue_init(me, Queue_isFull, Queue_isEmpty,
				Queue_getSize, Queue_insert, Queue_remove);
	}
	return me;
}

void Queue_destroy(Queue* const me){
	if(me != NULL){
		Queue_cleanup(me);
	}
	free(me);
}







