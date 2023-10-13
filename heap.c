#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0) return NULL;

  return (void*) pq->heapArray[0].data; 
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size >= pq->capac){
    pq = realloc(pq, sizeof(2 * pq->capac + 1));
  }

  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;
  
 int posicion = pq->size - 1;
  int padre = (posicion - 1) / 2;
  void* temporalData;
  int temporalPriority;

  while(posicion > 0 && pq->heapArray[posicion].priority > pq->heapArray[padre].priority){
    temporalData = pq->heapArray[posicion].data;
    pq->heapArray[posicion].data = pq->heapArray[padre].data;
    pq->heapArray[padre].data = temporalData;

    temporalPriority = pq->heapArray[posicion].priority;
    pq->heapArray[posicion].priority = pq->heapArray[padre].priority;
    pq->heapArray[padre].priority = temporalPriority;

    posicion = padre;
    padre = (posicion - 1) / 2;
    
  }

  

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * nuevo = (Heap *) malloc(sizeof(Heap));
  nuevo->size = 0;
  nuevo->capac = 3;
  nuevo->heapArray = (heapElem*) calloc(nuevo->capac,sizeof(heapElem));
  
  return nuevo;
}
