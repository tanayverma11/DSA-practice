#include<stdio.h>
#define SIZE 100

int pq[SIZE];
int front = -1;
int rear = -1;

int isFull(){
    return rear == SIZE-1;
}

int isEmpty(){
    return front == -1;
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    printf("\n");
    printf("The current queue is: \n");
    for(int i = front; i<=rear; i++){
        printf("%d ", pq[i]);
    }
    printf("\n");
}

void enqueue(int val){
   if(isFull()){
    printf("Queue is full\n");
    return;
   }
   if(isEmpty()){
    front = 0;
    rear = 0;
    pq[rear] = val;
   } else {
    // find correct position to insert
    int i=0;
    for(i=rear; i>front && pq[i] > val; i--){
        pq[i+1] = pq[i]; // shift elements to the right
    }
    pq[i+1] = val;
    rear++;
   }
   display();
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("The dequeued element is: %d",pq[front]);
    //shift elements to left after deletion
    for(int i = front; i<rear; i++){
        pq[i] = pq[i+1];
    }
    rear--;
    if(rear < front){
        front = rear = -1;
    }
    display();
}

int main(){
    int choice, ele;
    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter the option: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d",&ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Exiting....");
            return 0;
        default:
            printf("Invalid option!");
        }
    }
    return 0;
}