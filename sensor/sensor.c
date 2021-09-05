#include "sensor.h"
#include <stdint.h>
#include <stdlib.h>

void Sensor_Init(Sensor* const me){

}

void Sensor_Cleanup(Sensor* const me){
    
}

int Sensor_getFilterFrequency(Sensor* const me)
{
    return me->filterFrequency;
}

void Sensor_setFilterFrequency(Sensor* const me, int p_filterFrequency){
    me->filterFrequency = p_filterFrequency;
}

int Sensor_getUpdateFrequency(Sensor* const me){
    return me->updateFrequency;
}

void Sensor_setUpdateFrequency(Sensor* const me, int p_updateFrequency){
    me->updateFrequency = p_updateFrequency;
}

int Sensor_getValue(Sensor* const me){
    return me->value;
}

int Sensor_acquireValue(Sensor* const me){
	int *r, *w;
	int j;
	switch(me->whatKindOfInterface){
	case MEMORYMAPPED:
	{
		//w = (int*)WRITEADDR;
		//*w = WRITEMASK; // sensor command to force read
		for(j = 0; j < 100 ; j++){
			/*wait loop*/		
		}
		//r = (int*)READADDR;
		//me->value = *r;
		break;
	}
	case PORTMAPPED:
	{
		/*inp() is a compiler-specific port function*/
		//me->value = inp(SENSORPORT);
		break;	
	}
	}
	return me->value;
}



Sensor* Sensor_Create(void){
    Sensor* me = (Sensor*)malloc(sizeof(Sensor));
    if(me != NULL) Sensor_Init(me);
    
    return me;
}

void Sensor_Destroy(Sensor* const me){
    if(me != NULL) 
        Sensor_Cleanup(me);
    free(me);
}
