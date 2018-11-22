#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct process
{
int PID;
int DA;
int TE;
int tempsej;
int temfin;
int priority;
}process;

void fifo(process *proc,int nb){
/*FIFO*/
/*trier le tableau par ordre croissant de date darrivee*/
process permut;
for(int i=0;i<nb+1;i++)
for(int j=i+1;j<nb;j++)
{
if ((proc[i].DA)>(proc[j].DA))
{
permut=proc[i];
proc[i]=proc[j];
proc[j]=permut;
}

}

}


void sauvegarder(process *proc,int nb){
FILE* fichier = NULL;
fichier = fopen("test.txt", "w");
if (fichier != NULL){
for(int i=0;i<nb;i++){

  proc[i].PID=i+1;
   printf("entrer la date d'arrivee du processus (%d)\n",i+1);
   scanf("%d",&proc[i].DA);
   printf("entrer la duree d'execution du processus (%d)\n",i+1);
   scanf("%d",&proc[i].TE);
    printf("entrer la priorite (%d)\n",i+1);
   scanf("%d",&proc[i].priority);
fprintf(fichier,"%d ",proc[i].DA);
fprintf(fichier,"%d ",proc[i].TE);
fprintf(fichier,"%d ",proc[i].priority);
}

        fclose(fichier);
          }
return 0;


}


int lirePolitique(){
/*lire la politiique choisie par l'utilisateur*/
int politique;
printf("entrer le numéro de l'ordonnancement: \n");
printf("1.\tFIFO\n");
printf("2.\tTOURNIQUET\n");
printf("0.\tQUITTER\n");
scanf("%d",&politique );

while((politique!=1)&& (politique!=0)&&(politique!=2)){
printf("Erreur! veuillez réessayer!\n");
printf("1. FIFO\n");
printf("2.\tTOURNIQUET\n");
printf("0. QUITTER\n");
scanf("%d",&politique );
}

return politique;

}
bool recommencer(){
//redemander de répéter
int rep;
printf("Voulez vous réessayer ?: \n");
printf("1. OUI \n 2. NON");
scanf("%d",&rep );

while((rep!=1) && (rep!=2)){
printf("Erreur! veuillez réessayer!\n");
printf("1. OUI \n 2. NON");
scanf("%d",&rep);
}
if (rep==1) return true;
else return false;
}

void remplir( process *proc,int nb){
/*lire la date d'arrivée, la durée et la priorité du processus*/

   for(int i=0;i<nb;i++)
   {
   proc[i].PID=i+1;
   printf("entrer la date d'arrivee du processus (%d)\n",i+1);
   scanf("%d",&proc[i].DA);
   printf("entrer la duree d'execution du processus (%d)\n",i+1);
   scanf("%d",&proc[i].TE);
    printf("entrer la priorite (%d)\n",i+1);
   scanf("%d",&proc[i].priority);

//sauvegarder(proc,nb);
   /* ajouter les processus saisie dans un fichier*/
   }

}
int main(){
int i,j,nb,tfin,ss,tsej,q,ttime,c;
process* proc;
int politique;
char ch[10];
float temsej;
int pid,* pri;


/*lire le nombre de processus*/
printf ("entrer le nombre de processus\n");
scanf("%d",&nb);

/*allouer le tableau de processus d'une maniere dynamique*/
proc=( process *)malloc(sizeof( process )*nb);

//sauv(nb);
//remplir(proc,nb);
sauvegarder(proc,nb);

do{
politique=lirePolitique();
if (politique==1)
{
fifo(proc,nb);
printf("\n");

/*Afficher l'ordonnancement choisi*/
printf("Ordonnancement FIFO\n'");


/*Afficher la date d'arrivee, le temps d'execution et la priorité de chaque processus*/
printf("PID\t DA\t TE\t priority\n");
for (i=0;i<nb;i++)
{



printf("%d\t %dms \t %dms \t %d\n",proc[i].PID,proc[i].DA,proc[i].TE,proc[i].priority);
}
printf("\n");


/*afficher la date de fin d'execution de chaque processuss*/


/*Calcul de la date de fin*/
tfin=0;
tsej=0;

for(i=0;i<nb;i++)
{
 tfin=tfin+proc[i].TE; /* calcul du temps de fin d'exécution de chaque processus */
 proc[i].temfin=tfin;
 tsej=tfin-proc[i].DA;/* calcul du temps de séjour de chaque processus */
 proc[i].tempsej=tsej;
printf("temps de fin d'exécution du prosessus %d = %dms\n",i+1,proc[i].temfin);

}
printf("\n");
/*afficher le temps de sejour de chaque processuss*/

ss=0;
for(i=0;i<nb;i++)
{ss=ss+proc[i].tempsej;/* calculer le temps de séjour total */
 printf(" temps de séjour du processus %d = %dms\n",i+1,proc[i].tempsej);
}

printf("\n");
/*afficher le temps moyen de sejour */
temsej=(float)ss/nb;/* calculer le temps moyen de séjour */
printf("le temps moyen de sejour = %fms\n",temsej);
}
else if (politique==0){
printf("Merci");
return 0;
}

}
while(recommencer());
printf("MERCI !");

return 0;

}
