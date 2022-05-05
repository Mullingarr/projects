//
// Created by Manuela on 02/05/2022.
//

/*Scrivere in C una funzione valori che legge un array di interi
 * (di dimensione variabile)
 * e restituisce la somma dei valori più piccolo e più grande
 * contenuti nell’array.
 * Scrivere anche un programma principale d’esempio
 * per l’invocazione della funzione.
 * */

#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
    int el;
    struct nodo *next;
}Nodo;
Nodo *head = NULL;

void *inserisciL(int val);
int somma();
Nodo *allocal();
void stampa();
//int valori(int *a, int lung);  //versione originale

int main(){
    //int arr[10]= {10, 6, 8, 4, 7, 5, 3, 9, 2, 1};
    int j=0, num=0;
    printf("Inserisci il numero di nodi da creare\n");
    scanf("%d",&num);
    printf("inserisci i valori:\n");
    head = allocal();
    head->next = NULL;
    for(int i=0; i<num; i++){
        scanf("%d", &j);//non si ferma :( ...cioè se metto di seguito anche la inserisciL(...) contiua ad inserire valori.
        inserisciL(j);
    }
    stampa();




/*   //questi appartengono alla versione "originale"
    int somma= valori(arr, num);
    printf("somma = %d", somma);
    */

    return 0;
}

//ma se io devo dargli un massimo di nodi da creare cosa faccio?
void *inserisciL(int val){
    Nodo *testa = head;
    while (testa->next != NULL){
        testa = testa->next;//scorre la lista e va al nodo successivo
    }
    testa->el = val;
    testa->next = NULL;
}


void stampa(){
    Nodo *testa= head;
    while (testa->next != NULL){
        printf("elemento -> %d\n", testa->el);
        testa = testa->next;
    }
}
/*scorre la lista e trovo il minimo e il massimo, restituisce la somma dei due
 * come faccio a passagli la lista?
 * */
int somma(){
    Nodo *testa = allocal(); //devo rifarlo perchè è una variabile locale giusto?
    int min, max;
    while(testa->next != NULL){
        if(testa->el < testa->next->el){
            min = testa->el;
        }
        testa= testa->next;
    }
    while(testa->next != NULL){
        if (testa->el > testa->next->el){
            max= testa->el;
        }
        testa= testa->next;
    }
    return min + max;
}


Nodo *allocal(){
    return (Nodo *)malloc(sizeof(Nodo));
}

/* //versione originale
 * int valori(int *a, int lung){

    int min= a[0], max= a[0];
    for (int i=0; i<lung; i++){
        if(a[i]<min)
            min=a[i];

        if (a[i]>max)
            max= a[i];
    }
   return min+max;
}
 */
