#ifndef ECECAR_STATION_H
#define ECECAR_STATION_H
#include "Task.h"

typedef struct Station{
    int rang;
    int tempsmax;
    float tempsactuel;
    struct Task* tabstat;
}stat;

#endif //ECECAR_STATION_H
