#include<stdio.h>
#define SIZE 11

// calculation the hash index
int hashFunction(int x){
    return (x+10) % SIZE;
}

// function to insert elements into the hashTable
void insertIntoHashTable(int hashTable[], int val){
    int index = hashFunction(val);
    int prevIndex = index;

    // collision resolution : Linear Probing
    while(hashTable[index] != -1){
        index = (index + 1) % SIZE; // move to the next index, circularly
        if(index == prevIndex){ // condition for table full
            printf("\nHash Table is FULL!!!\n");
            return;
        }
    }

    hashTable[index] = val;
}

// display function
void displayHashTable(int hashTable[]){
    printf("\n\tCurrent Hash Table:\n");
    printf("\t Index: \t Value:\n");
    for(int i=0; i<SIZE; i++){
        printf("\t %d \t\t %d\n", i , hashTable[i]);
    }
}


int main(){

    // creating the hash table and initialising with -1
    int hashTable[SIZE];
    for(int i=0; i<SIZE; i++){
        hashTable[i] = -1;
    }

    // input values from user and store them in elements[]
    int n;
    printf("Enter the number of elements you want to enter: \n");
    scanf("%d", &n);
    int elements[n];
    printf("\nEnter the elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &elements[i]);
    }

    // inserting the elements into the hashTable
    for(int i=0; i<n; i++){
        insertIntoHashTable(hashTable, elements[i]);
    } 

    // displaying the hashTable
    displayHashTable(hashTable);

    return 0;
}