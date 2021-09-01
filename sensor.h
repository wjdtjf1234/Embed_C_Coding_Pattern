#ifndef Sensor_H
#define Sensor_H

/*class Sensor*/
typedef struct Sensor Sensor;
struct Sensor {
    int filterFrequency;
    int updateFrequency;
    int value;
};

int Sensor_getFilterFrequency(Sensor* const me);
void Sensor_setFilterFrequency(Sensor* const me, int p_filterFrequency);
int Sensor_getUpdateFrequency(Sensor* const me);
void Sensor_setUpdateFrequency(Sensor* const me, int p_updateFequency);
int Sensor_getValue(Sensor* const me);
Sensor* Sensor_Create(void);
void Sensor_Destroy(Sensor* const me);

#endif