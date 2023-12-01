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
            g->taches[i].couleur = 0;
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
            for(int j=0; j<g->nbtaches; j++)                          //Boucle sur tous les sommets pour trouver l'index de "op1"
            {
                if(g->taches[j].ID == op1)                          //Index de "op1"
                {
                    for(int k=0; k<g->nbtaches; k++)               //Boucle sur tous les sommets pour trouver l'index de "op2"
                    {
                        if(g->taches[k].ID == op2)                //Récupère l'index de la tache correspondant à "op2" dans le tableau de taches
                        {
                            g->taches[k].pred[g->taches[k].nbpred] = g->taches[j];      //Met la tache "op1" dans le tableau de predecesseur de "op2"
                            g->taches[k].nbpred +=1;                                    //Ajoute 1 au nombre de predecesseur
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
                if (g->taches[j].ID == op1)                          //Récupère l'index de la tache correspondant à "op1" dans le tableau de taches
                {
                    for (int k = 0; k < g->nbtaches; k++) {
                        if (g->taches[k].ID == op2)                      //Récupère l'index de la tache correspondant à "op2" dans le tableau de taches
                        {
                            g->taches[j].exclu[g->taches[j].nbexclu] = g->taches[k];      //Met la tache "op2" dans le tableau d'exclusion de "op1"
                            g->taches[k].exclu[g->taches[k].nbexclu] = g->taches[j];      //Met la tache "op1" dans le tableau d'exclusion de "op2"
                            g->taches[j].nbexclu++;                                    //Ajoute 1 au nombre d'exclus de "op1"
                            g->taches[k].nbexclu++;                                   //Ajoute 1 au nombre d'exclus de "op2"
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

chain* init_chaine(char* file_name, taches* g,chain* ws)                             ///Fonction de lecture de fichier pour le temps d'un cycle pour les stations
{
    ws->chaine = (stat*) (chain *) malloc(sizeof(stat) * g->nbtaches);
    for (int i = 0; i < g->nbtaches; i++) {
        ws->chaine[i].tabstat =(task*) malloc(sizeof(stat) * g->nbtaches);
        ws->chaine[i].rang =0;
        ws->chaine[i].nbtask = 0;
        for (int j = 0; j < g->nbtaches; ++j) {
            ws->chaine[i].tabstat =(task*) malloc(sizeof(stat));
        }
    }
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf
    fscanf(pf,"%d",&ws->tempsmax);
    fclose(pf);

    return ws;
}

void tri_a_bulle(taches* tabtask)             /// Fonction de tri des arêtes par ordre croissant de poids
{
    int trie=0;                                                 //Variable d'arrêt de boucle
    while(trie==0)                                              //Boucle tant que la liste n'est pas triée
    {
        trie=1;
        for(int i=0;i<tabtask->nbtaches-1;i++)                          //Boucle sur le nombre d'arêtes
        {
            if(tabtask->taches[i].nbexclu>tabtask->taches[i+1].nbexclu)     //Si la tache actuelle à plus d'exclusion que la suivante, on échange :
            {
                trie=0;                                         //On signale que la liste n'est pas triée
                task inter=tabtask->taches[i];                     //Tache temporaire
                tabtask->taches[i]=tabtask->taches[i+1];                //échange des positions des taches
                tabtask->taches[i+1]=inter;
            }
        }
    }
}

void exclusion(taches* tabtask,chain* ws)
{
    int X, exclMax, nbtemp =0, nbColorees = 0, couleur = 1;
    taches* listetemp = (taches*) malloc(sizeof(taches));
    listetemp->taches = (task*) malloc(sizeof(task)*tabtask->nbtaches);

    while(nbColorees != tabtask->nbtaches)          ///Tant que toutes les taches pas colorées
    {
        X = 0;
        exclMax = INT_MIN;
        for(int i = 0; i < tabtask->nbtaches; i++) {         ///Boucle sur toutes les taches pour chercher le maximum d'exclu
            if (tabtask->taches[i].nbexclu > exclMax && tabtask->taches[i].couleur == 0) {        //Cherche le maximum d'exclusion
                exclMax = tabtask->taches[i].nbexclu;
                X = i;
            }
        }
        tabtask->taches[X].couleur = couleur;
        nbColorees++;
        listetemp->taches[nbtemp] = tabtask->taches[X];
        nbtemp++;
        for(int i = 0; i < tabtask->nbtaches; i++) {             ///Boucles sur toutes les tâches
            if (tabtask->taches[i].couleur == 0) {           //Si la tache n'est pas colorée
                exclMax = 0;
                for(int j=0;j<nbtemp; j++)      ///Boucle sur la liste temp
                {
                    for (int k = 0; k < listetemp->taches[j].nbexclu; k++) {        //Boucle sur les exclus
                        if (listetemp->taches[j].exclu[k].ID == tabtask->taches[i].ID)         // Si on trouve un seul exclu dans listetemp on arrête la boucle sur les exclus
                        {
                            if (listetemp->taches[j].couleur == couleur)         // Si on trouve un seul exclu dans listetemp on arrête la boucle sur les exclus
                            {
                                exclMax = -1;
                            }
                        }
                    }

                    if (j == nbtemp - 1 && exclMax != -1)          //Si on est arrivé jusqu'ici, alors la tache n'est pas exclue
                    {
                        tabtask->taches[i].couleur = couleur;
                        nbColorees++;
                        listetemp->taches[nbtemp] = tabtask->taches[i];
                        nbtemp++;
                        break;
                    }
                }
            }
        }
        couleur++;
    }
    for (int i = 0; i < couleur-1; i++) {
        taches* listetempbis = (taches*) malloc(sizeof(taches));
        listetempbis->taches = (task*) malloc(sizeof(task)*tabtask->nbtaches);
        nbtemp=0;
        for (int j = 0; j < tabtask->nbtaches; j++) {
            if(tabtask->taches[j].couleur == i+1)
            {
                listetempbis->taches[nbtemp] = tabtask->taches[j];
                nbtemp++;
            }
        }
        ws->chaine[i].tabstat = listetempbis->taches;
        ws->chaine[i].nbtask = nbtemp;
        ws->chaine[i].rang=i+1;
        free(listetempbis);
    }
    ws->nbstat = couleur-1;
    free(listetemp);
}

int main() {

    int couleur;
    chain* ws = (chain*) malloc(sizeof(chain));
    taches* tabtask=(taches*)malloc(sizeof(taches));       //Initialise "tabtask", un tableau de toutes les taches
    init_taches("operations.txt", tabtask);         // Fonction de remplissage d'un tableau de taches avec leurs temps et identifiants
    init_pred("precedences.txt", tabtask);          // Fonction de remplissage des predecesseurs de chaque tache
    init_exclu("exclusions.txt", tabtask);          // Fonction de remplissage des exclusions pour chaque tache
    ws = init_chaine("temps_cycle.txt",tabtask,ws); // Fonction de définition du temps par station

    ///CODE EXCLUSION

    /*
     * Cherchez à répondre à la contrainte d'exclusion,
     * sans prendre en compte les autres contraintes
     * et proposez une répartition des opérations par station en fonction de cette contrainte seule.
     * */

    exclusion(tabtask,ws);

    ///AFFICHAGE EXCLUSION
    for (int i = 0; i < ws->nbstat; i++) {
        printf("%d ) Je suis la station %d :\n",i,ws->chaine[i].rang);
        for (int j = 0; j < ws->chaine[i].nbtask; ++j) {
            printf("    Tache : %d\n",ws->chaine[i].tabstat[j].ID);
        }
    }

    ///CODE PRECEDENCE / TEMPS

    /*
     * Cherchez à prendre en compte les contraintes de précédence et de temps de cycle.
     * En effet, prendre en compte uniquement les contraintes de précédence est trop simpliste :
     * si le temps de cycle est infini il suffit d'affecter toutes les opérations sur une seule station, et le tour est joué !
     * */

    ///AFFICHAGE PRECEDENCE / TEMPS

    free(tabtask);
    return 0;
}