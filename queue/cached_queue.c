#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cached_queue.h"

void CachedQueue_init(CachedQueue* const me, char* fName,
		int (*isFull)(CachedQueue* const me),
		int (*isEmpty)(CachedQueue* const me),
		int (*getSize)(CachedQueue* const me),
		void (*insert)(CachedQueue* const me, int k),	
		int (*remove)(CachedQueue* const me),
		void (*flush)(CachedQueue* const me),
		void (*load)(CachedQueue* const me)){

	
	/*initial base class*/
	me->queue = Queue_create();
	
	/*initialize subclass attributes*/
	me->numberElementsOnDisk = 0;
	strcpy(me->Filename, fName);

	/*initialize aggregates*/
	me->isFull = isFull;
	me->isEmpty = isEmpty;
	me->getSize = getSize;
	me->remove = remove;
	me->flush = flush;
	me->load = load;
}	

void CachedQueue_cleanup(CachedQueue* const me){
	Queue_cleanup(me->queue);
}

int CachedQueue_isFull(CachedQueue* const me){
	return me->queue->isFull(me->queue) &&
		me->outputQueue->isFull(me->outputQueue);
}

int CachedQueue_isEmpty(CachedQueue* const me){
	return me->queue->getSize(me->queue) &&
		me->outputQueue->isEmpty(me->outputQueue) &&
		(me->numberElementsOnDisk == 0);
}

int CachedQueue_getSize(CachedQueue* const me){
	return me->queue->getSize(me->queue) + 
		me->outputQueue->getSize(me->outputQueue) + 
		me->numberElementsOnDisk;
}

void CachedQueue_insert(CachedQueue* const me, int k){
	if(me->queue->isFull(me->queue))
	       	me->flush(me);
	me->queue->insert(me->queue,k);
}

int CachedQueue_remove(CachedQueue* const me){
	if(!me->outputQueue->isEmpty(me->outputQueue))
		return me->outputQueue->remove(me->outputQueue);
	else if(me->numberElementsOnDisk > 0){
		me->load(me);
		return me->outputQueue->remove(me->outputQueue);
	}
	else
		return me->queue->remove(me->queue);
}

void CachedQueue_flush(CachedQueue* const me){
	/**************************
	 * Queue가 비어있지 않은 경우
	 * 계속해서 queue내용을 
	 * disk의 file로 가져다 쓰기*/
}

void CachedQueue_load(CachedQueue* const me){
	/**************************
	 * file에서 queue element를
	 * 가져와서 output queue에 
	 * 집어넣기		  */	

}


CachedQueue* CachedQueue_create(void){
	CachedQueue* me = (CachedQueue*)malloc(sizeof(CachedQueue));
	if(me != NULL){
		CachedQueue_init(me, "C:\\queuebuffer.dat", CachedQueue_isFull,
				CachedQueue_isEmpty, CachedQueue_getSize,
				CachedQueue_insert, CachedQueue_remove,
				CachedQueue_flush, CachedQueue_load); 
	}
	return me;
}

void CachedQueue_destroy(CachedQueue* me){
	if(me != NULL)
		CachedQueue_cleanup(me);
		free(me);
}


























