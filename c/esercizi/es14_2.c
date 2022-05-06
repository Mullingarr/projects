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

#include "stdio.h"
#include "stdlib.h"

typedef struct nodo {
    int el;
    struct nodo *next;
}Nodo;
Nodo *head = NULL;

void inserisciL(Nodo *);
int somma();
Nodo *allocal();
void stampa();
//int valori(int *a, int lung);  //versione originale

int main(){
    //int arr[10]= {10, 6, 8, 4, 7, 5, 3, 9, 2, 1};
    int j=0, num=0;
    printf("Inserisci il numero di nodi da creare\n");
    scanf("%d",&num);
    printf("===== creazione della lista ====\n");
    head = allocal();
    head->next = NULL;
    head->el = -1;
    for(int i=0; i<num; i++){
        Nodo *tmp = allocal();
        printf("Inserisci valore\n");
        scanf("%d", &tmp->el);
        tmp->next = NULL;
        inserisciL(tmp);
    }
    stampa();

    return 0;
}

void inserisciL(Nodo *da_inserire){
    if(head->next == NULL){
        head->next = da_inserire;
    }else{
        Nodo *ptr = head;
        while(ptr->next != NULL){
           ptr = ptr->next; 
        }
        if(ptr->next == NULL) //ho trovato il nodo dove inserire
            ptr->next = da_inserire;
    }

}


void stampa(){
    printf("======= printing list ======\n");
    if(head == NULL)
        return;
    else{
        if(head->next != NULL){
            Nodo *ptr = head->next;
            size_t pos = 0;
            while(ptr != NULL){
                printf("(%zu, %d)\n", pos, ptr->el);
                pos++;
                ptr = ptr->next;
            }    
        }else{
            size_t pos = 0;
            printf("(%zu, %d)", pos, head->el);
        }
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
    return (struct nodo *)malloc(sizeof(struct nodo));
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
