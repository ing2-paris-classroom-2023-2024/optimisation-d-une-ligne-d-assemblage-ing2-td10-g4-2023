#include <stdio.h>
#include <stdlib.h>
#include "Task.h"
#include "Station.h"

int compteLignes(char* nom)         ///Fonction de récupération du nombre de lignes dans un fichier
{
    int carac;                              //Les 2 caractères qui récupèreront les données du fichier
    int carac2 = '\0';
    int nbL = 0;                           //Nombre de lignes à incrémenter

    FILE *pf = fopen(nom,"r");              //Ouverture du fichier
    if(pf != NULL)                                        //Si le fichier est bien ouvert
    {
        while((carac=fgetc(pf)) != EOF)              //Boucle qui compte les \n à chaque fin de ligne jusqu'à ce que le fichier ne soit pas fini
        {
            if(carac == 10 && carac2 == 10)              //Si les 2 derniers caractères sont des sauts de lignes, alors on arrête de compter
            {
                break;
            }
            if(carac=='\n')                             //Si le caractère est un \n on incrémente le nombre de lignes
            {
                nbL++;
            }
            carac2 = carac;
        }

        if(carac2 != '\n')                            // Ici, c2 est égal au caractère juste avant le EOF (end of file). Si le dernier caractère n'est pas un \n on rajoute 1 au nombre de ligne
        {
            nbL++;                                   // Dernière ligne non finie
        }
        fclose(pf);                             //Ferme le fichier
        return nbL;                                 //Renvoi le nombre de lignes du fichier
    }
    else{                                          //Erreur si le fichier ne s'ouvre pas correctement
        printf("Erreur en ouverture du fichier.\n");
        fclose(pf);
        return 0;
    }
}

void init_taches(char* file_name, taches* g)         ///Fonction de lecture de fichier .txt pour initialiser un tableau de taches contenant leurs ID et leurs temps d'execution.
{

    int nblignes = compteLignes(file_name);                            //Compte le nombre de lignes dans le fichier
    g->nbtaches = nblignes;
    g->taches = (task*) malloc(sizeof(task)*g->nbtaches);
    FILE *pf = fopen(file_name,"r");                         //Ouvre le fichier sous le nom pf

    if(pf != NULL) {

        for(int i=0;i<g->nbtaches;i++)                                    //Rempli un tableau de taches avec toutes les taches
        {
            fscanf(pf,"%d",&g->taches[i].ID);
            fscanf(pf,"%f",&g->taches[i].temps);
            g->taches[i].marque = 0;                                    //Initialise la tache en "non marquée"
            g->taches[i].nbpred = 0;                                   //Initialise le nombre de predecesseurs de la tache à "0"
            g->taches[i].nbexclu = 0;                                 //Initialise le nombre de taches exclues de la tache à "0"
        }
        fclose(pf);                                             //Ferme le fichier
    }
    else{                                                         //Erreur si le fichier ne s'ouvre pas correctement
        printf("Erreur d'ouverture\n");
        fclose(pf);
    }

}

void init_pred(char* file_name, taches *g)         ///Fonction de lecture de fichier .txt pour initialiser les predecesseurs de chaque taches
{

    int op1, op2;
    int nblignes = compteLignes(file_name);                           //Compte le nombre de lignes dans le fichier
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf

    if(pf != NULL) {
        for(int i = 0 ; i<g->nbtaches;i++)
        {
            g->taches[i].pred =(task*) malloc(sizeof(task)*g->nbtaches);
        }
        for(int i=0;i<nblignes;i++)                                      //Rempli un tableau de predecesseur
        {
            fscanf(pf,"%d",&op1);                         //Récupère les informations du fichier
            fscanf(pf,"%d",&op2);
            for(int j=0; j<g->nbtaches; j++)                          //Boucle sur tous les sommets pour trouver l'index de "op2"
            {

                if(g->taches[j].ID == op2)                          //Index de "op2"
                {

                    for(int k=0; k<g->nbtaches; k++)               //Boucle sur tous les sommets pour trouver l'index de "op1"
                    {
                        if(g->taches[k].ID == op1)                //Récupère l'index de la tache correspondant à "op1" dans le tableau de taches
                        {
                            g->taches[j].pred[g->taches[j].nbpred] = g->taches[k];      //Met la tache "op1" dans le tableau de predecesseur de "op2"
                            g->taches[j].nbpred +=1;                                    //Ajoute 1 au nombre de predecesseur
                        }
                    }
                }
            }
        }
        fclose(pf);                         //Ferme le fichier
    }
    else{                                       //Erreur si le fichier ne s'ouvre pas correctement
        printf("Erreur d'ouverture\n");
        fclose(pf);
    }

}

void init_exclu(char* file_name, taches *g)         ///Fonction de lecture de fichier .txt pour initialiser les predecesseurs de chaque taches
{

    int op1, op2;
    int nblignes = compteLignes(file_name);                             //Compte le nombre de lignes dans le fichier
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf

    if(pf != NULL) {
        for (int i = 0; i < g->nbtaches; i++) {
            g->taches[i].exclu = (task *) malloc(sizeof(task) * g->nbtaches);
        }
        for (int i = 0; i < nblignes; i++)                                      //Rempli un tableau de predecesseur
        {
            fscanf(pf, "%d", &op1);               //Récupère les informations du fichier
            fscanf(pf, "%d", &op2);
            for (int j = 0; j < g->nbtaches; j++) {
                if (g->taches[j].ID ==
                    op1)                          //Récupère l'index de la tache correspondant à "op1" dans le tableau de taches
                {
                    for (int k = 0; k < g->nbtaches; k++) {
                        if (g->taches[k].ID ==
                            op2)                      //Récupère l'index de la tache correspondant à "op2" dans le tableau de taches
                        {
                            g->taches[j].exclu[g->taches[j].nbexclu] = g->taches[k];      //Met la tache "op2" dans le tableau d'exclusion de "op1"
                            g->taches[k].exclu[g->taches[j].nbexclu] = g->taches[j];      //Met la tache "op1" dans le tableau d'exclusion de "op2"
                            g->taches[j].nbexclu += 1;                                    //Ajoute 1 au nombre de predecesseur de "op1"
                            g->taches[k].nbexclu += 1;                                   //Ajoute 1 au nombre de predecesseur de "op2"
                        }
                    }
                }
            }
        }
        fclose(pf);                     //Ferme le fichier
    }
    else{                                   //Erreur si le fichier ne s'ouvre pas correctement
        printf("Erreur d'ouverture\n");
        fclose(pf);
    }
}

stat* init_station(char* file_name)                             ///Fonction de lecture de fichier pour le temps d'un cycle pour les stations
{

    stat* ws = (stat*) malloc(sizeof(stat));
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf
    fscanf(pf,"%d",&ws->tempsmax);
    fclose(pf);

    return ws;
}

void tri_precedence (stat* wagon, taches* listetaches) {
    taches *listetemp = (taches *) malloc(sizeof(taches) * listetaches->nbtaches);
    int compteurtaches = 0;
    int compteurstations = 0;
    float tempsrestant;
    while (compteurtaches < listetaches->nbtaches) {            ///TANT QUE PAS TOUTES TACHE COLOREES
        for (int i = 0; i < listetaches->nbtaches; i++) {
            if (listetaches->taches->nbpred == 0) {                         /// SI PAS DE PRED
                listetemp->taches[compteurtaches] = listetaches->taches[i];
                compteurtaches++;
            } else {                                                                     /// SI PRED
                for (int j = 0; j < listetaches->taches[i].nbpred; j++) {                       /// POUR CHAQUE PRED
                    for (int l = 0; l < listetaches->nbtaches; l++) {
                        if (listetaches->taches[i].pred[j].ID == listetaches->taches[l].ID) {
                            if (listetaches->taches[l].marque != 2) {
                                break;
                            }
                            if(listetaches->taches[i].nbpred-1 == j)
                            {
                                listetaches->taches[i].marque = 1;
                                listetemp->taches[compteurtaches] = listetaches->taches[i];
                                compteurtaches++;
                            }
                        }
                    }
                }
            }

        }
        while (compteurstations < compteurtaches) {
            tempsrestant = wagon->tempsmax - wagon->tempsactuel;
            for (int i = 0; i < compteurtaches; i++) {
                if (listetemp->taches[i].temps <= tempsrestant) {
                    for (int j = 0; j < listetemp->taches[i].nbpred; j++) {
                        if (listetemp->taches[i].pred[j].marque != 1) {
                            break;
                        }
                        else {

                        }
                    }
                }
            }
        }
    }
}

int main() {
    stat* ws;
    taches* tabtask=(taches*)malloc(sizeof(taches));       //Initialise "tabtask", un tableau de toutes les taches
    init_taches("operations.txt", tabtask);         // Fonction de remplissage d'un tableau de taches avec leurs temps et identifiants
    init_pred("precedences.txt", tabtask);          // Fonction de remplissage des predecesseurs de chaque tache
    init_exclu("exclusions.txt", tabtask);          // Fonction de remplissage des exclusions pour chaque tache
    ws = init_station("temps_cycle.txt");                   // Fonction de définition du temps par station

    ///CODE EXCLUSION

    /*
     * Cherchez à répondre à la contrainte d'exclusion,
     * sans prendre en compte les autres contraintes
     * et proposez une répartition des opérations par station en fonction de cette contrainte seule.
     * */

    ///CODE PRECEDENCE / TEMPS

    /*
     * Cherchez à prendre en compte les contraintes de précédence et de temps de cycle.
     * En effet, prendre en compte uniquement les contraintes de précédence est trop simpliste :
     * si le temps de cycle est infini il suffit d'affecter toutes les opérations sur une seule station, et le tour est joué !
     * */

    tri_precedence (ws, tabtask);

    free(tabtask);
    return 0;
}