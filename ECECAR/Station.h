#ifndef ECECAR_STATION_H
#define ECECAR_STATION_H
#include "Task.h"

typedef struct Station{
    int rang;
    struct Task* tabstat;
}stat;

typedef struct Chaine{
    int nbstat;
    int tempsmax;
    struct stat* chaine;
}chain;

#endif //ECECAR_STATION_H