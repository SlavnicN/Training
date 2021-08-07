#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 24

typedef struct HashTable{
  int value;
  char key;
}HashTable;

HashTable* alphabetArray[SIZE];
HashTable* DummyItem;
HashTable* item;

int getIndex(int key){
  return key % SIZE;
}

HashTable *search(int key){
  //get index
  int hashIndex = getIndex(key);
  //search in array until NULL
  while(alphabetArray[hashIndex] != NULL){
    if(alphabetArray[hashIndex]->key == key)
      return alphabetArray[hashIndex];
    
    //go to the next call
    ++hashIndex;
    
    //wrap around the table
    hashIndex %= SIZE;
  }
  return NULL;
}

void insert(int key,int value) {

   HashTable *item = (HashTable*) malloc(sizeof(HashTable));
   item->value = value;  
   item->key = key;

   //get the hash 
   int hashIndex = getIndex(key);

   //move in array until an empty or deleted cell
   while(alphabetArray[hashIndex] != NULL && alphabetArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   alphabetArray[hashIndex] = item;
}

HashTable *delete(HashTable* item){
  int keyItem = item->key;

  //get the hash
  int hashIndex = getIndex(keyItem);

  while(alphabetArray[hashIndex] != NULL){
    if(alphabetArray[hashIndex]->key == keyItem){
      HashTable* temp = alphabetArray[hashIndex];

      //assign a dummy item at deleted position
      alphabetArray[hashIndex] = DummyItem;
      return temp;
    }
    ++hashIndex;

    hashIndex %= SIZE;
  }
  return NULL;
}

void display(){
  int i =0;

  for(i = 0; i<SIZE;i++){
    if(alphabetArray[i] != NULL)
         printf(" (%c,%d)",alphabetArray[i]->key,alphabetArray[i]->value);
      else
         printf(" ~~ ");
  }
  printf("\n");
}
bool is_pangram(const char *str_in) {
  
  return true;
}

void main(){
  int i = 0;
  DummyItem = (HashTable*) malloc(sizeof(HashTable));
  DummyItem.value = -1;  
  DummyItem->key = -1; 

  for(i = 0;i<SIZE;i++){
    printf("%d\n",i);
    insert('A', i);
  }

  display();
}