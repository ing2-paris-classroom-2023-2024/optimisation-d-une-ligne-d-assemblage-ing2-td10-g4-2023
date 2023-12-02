#ifndef ECECAR_STATION_H
#define ECECAR_STATION_H
#include "Task.h"

typedef struct Station{
    int rang;
    int nbtask;
    float tempsactuel;
    struct Task* tabstat;
}stat;

typedef struct Chaine{
    int nbstat;
    float tempsmax;
    struct Station* chaine;
}chain;

#endif //ECECAR_STATION_H