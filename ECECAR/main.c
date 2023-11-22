#include <stdio.h>
#include <stdlib.h>
#include "Task.h"


void init_taches(char* file_name, taches *g)         ///Fonction de lecture de fichier .txt pour initialiser un tableau de taches contenant leurs ID et leurs temps d'execution.
{
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf
    fscanf(pf,"%d",&g->nbtaches);                           //Récupère le nombre de taches dans le fichier
    for(int i=0;i<g->nbtaches;i++)                                      //Rempli un tableau de taches avec toutes les taches
    {
        fscanf(pf,"%d",&g->taches[i].ID);                //Récupère l'ID dans le fichier
        fscanf(pf,"%f",&g->taches[i].temps);            //Récupère le temps de la tache dans le fichier
        g->taches[i].marque = 0;                                    //Initialise la tache en "non marquée"
        g->taches[i].nbpred = 0;                                   //Initialise le nombre de predecesseurs de la tache à "0"
        g->taches[i].nbexclu = 0;                                 //Initialise le nombre de taches exclues de la tache à "0"
    }
    fclose(pf);                                                 //Ferme le fichier
}
void init_pred(char* file_name, taches *g)         ///Fonction de lecture de fichier .txt pour initialiser les predecesseurs de chaque taches
{
    int nbcondi, op1, op2;
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf
    fscanf(pf,"%d",&nbcondi);                           //Récupère le nombre de conditions dans le fichier

    for(int i=0;i<nbcondi;i++)                                      //Rempli un tableau de predecesseur
    {
        fscanf(pf,"%d",&op1);               //Récupère les informations du fichier
        fscanf(pf,"%d",&op2);
        for(int j=0; j<g->nbtaches; j++)
        {
            if(g->taches[j].ID == op2)
            {
                for(int k=0; k<g->nbtaches; k++)
                {
                    if(g->taches[k].ID == op1)                      //Récupère l'index de la tache correspondant à "op1" dans le tableau de taches
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

void init_exclu(char* file_name, taches *g)         ///Fonction de lecture de fichier .txt pour initialiser les predecesseurs de chaque taches
{
    int nbcondi, op1, op2;
    FILE *pf = fopen(file_name,"r");                        //Ouvre le fichier sous le nom pf
    fscanf(pf,"%d",&nbcondi);                           //Récupère le nombre de conditions dans le fichier

    for(int i=0;i<nbcondi;i++)                                      //Rempli un tableau de predecesseur
    {
        fscanf(pf,"%d",&op1);               //Récupère les informations du fichier
        fscanf(pf,"%d",&op2);
        for(int j=0; j<g->nbtaches; j++)
        {
            if(g->taches[j].ID == op1)
            {
                for(int k=0; k<g->nbtaches; k++)
                {
                    if(g->taches[k].ID == op2)                      //Récupère l'index de la tache correspondant à "op1" dans le tableau de taches
                    {
                        g->taches[j].exclu[g->taches[j].nbexclu] = g->taches[k];      //Met la tache "op2" dans le tableau d'exclusion de "op1"
                        g->taches[k].exclu[g->taches[j].nbexclu] = g->taches[j];      //Met la tache "op1" dans le tableau d'exclusion de "op2"
                        g->taches[j].nbexclu +=1;                                    //Ajoute 1 au nombre de predecesseur de "op1"
                        g->taches[k].nbexclu +=1;                                   //Ajoute 1 au nombre de predecesseur de "op2"
                    }
                }
            }
        }
    }
    fclose(pf);                     //Ferme le fichier
}

int main() {

    taches* tabtask=(taches*)malloc(sizeof(taches));  //Initialise "tabtask", un tableau de toutes les taches
    init_taches("Operation.txt", tabtask);    // Fonction de remplissage d'un tableau de taches avec leurs temps et identifiants
    init_pred("Pred.txt", tabtask);          // Fonction de remplissage des predecesseurs de chaque tache
    init_exclu("Exclusion.txt", tabtask);

    ///CODE EXCLUSION

    ///CODE PRECEDENCE

    free(tabtask);
    return 0;
}