#ifndef CACHEDQUEUE_H_
#define CACHEDQUEUE_H_
#include "queue.h"

typedef struct CachedQueue CachedQueue;
struct CachedQueue{
	Queue* queue;
	
	/*New Attributes*/
	char Filename[80];
	int numberElementsOnDisk;

	/*aggregation in subclass*/
	Queue* outputQueue;

	/*Inherited Virtual Functions*/
	int (*isFull)(CachedQueue* const me);
	int (*isEmpty)(CachedQueue* const me);
	int (*getSize)(CachedQueue* const me);
	void (*insert)(CachedQueue* const me, int k);
	int (*remove)(CachedQueue* const me);
	
	/*New Virtual Functions*/
	void (*flush)(CachedQueue* const me);
	void (*load)(CachedQueue* const me);
};

/*Constructors & Destructors*/
void CachedQueue_init(CachedQueue* const me, char* fName,
		int (*isFull)(CachedQueue* const me),
		int (*isEmpty)(CachedQueue* const me),
		int (*getSize)(CachedQueue* const me),
		void (*insert)(CachedQueue* const me, int k),	
		int (*remove)(CachedQueue* const me),
		void (*flush)(CachedQueue* const me),
		void (*load)(CachedQueue* const me));

void CachedQueue_cleanup(CachedQueue* const me);

/*Operations*/
int CachedQueue_isFull(CachedQueue* const me);
int CachedQueue_isEmpty(CachedQueue* const me);
int CachedQueue_getSize(CachedQueue* const me);
void CachedQueue_insert(CachedQueue* const me, int k);
int CachedQueue_remove(CachedQueue* const me);
void CachedQueue_flush(CachedQueue* const me);
void CachedQueue_load(CachedQueue* const me);

CachedQueue* CachedQueue_create(void);
void CachedQueue_destroy(CachedQueue* const me);
#endif
