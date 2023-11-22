#ifndef ECECAR_TASK_H
#define ECECAR_TASK_H


typedef struct Task{
    int ID;
    int marque;
    int nbpred;
    int nbexclu;
    float temps;
    struct Task* pred;
    struct  Task* exclu;
}task;

typedef struct Taches{
    int nbtaches;
    struct Task* taches;
}taches;

#endif //ECECAR_TASK_H
