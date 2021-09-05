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

void Queue_Cleanup(Queue* const me){

}


void Queue_isFull




