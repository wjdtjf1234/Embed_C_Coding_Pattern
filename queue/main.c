#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void){
	int j, k, h, t;
	
	Queue *myQ;
	myQ = Queue_create();
	k = 1000;

	for (j = 0; j < QUEUE_SIZE; j++){
		h = myQ->head;
		myQ->insert(myQ, k);
		printf("inserting %d at position %d, size = %d\n", k--, h, myQ->getSize(myQ));
	};
	printf("inserted %d elements\n", myQ->getSize(myQ));
	for(j = 0; j < QUEUE_SIZE; j++){
		t = myQ->tail;
		k = myQ->remove(myQ);	
		printf("Removing %d at position %d, size = %d\n", k, h, myQ->getSize(myQ));
	};
	printf("Last Item Removed = %d\n", k);
	printf("Current Queue Size %d\n", myQ->getSize(myQ));
	puts("Queue Test Program");
	return EXIT_SUCCESS;
}






