#include<stdio.h>
#include<stdbool.h>
#define SIZE 5
int stack[SIZE];
int rear = -1;
int front = -1;

bool isFull(){
    if(rear +1 == SIZE){
        return true;
    }else{
        return false;
    }
}
bool isEmpty(){
    if(rear == -1 && front == -1){
        return true;
    }else{
        return false;
    }
}

void display() {
    if (isEmpty()) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push(int value){
    if(isFull()){
        printf("\nThe queue is full");
    }else{
        if(isEmpty()){
            front++;
            stack[front] = value;
            rear++;
        }else{
            front++;
            stack[front] = value;
        }
    }
}

void pop(){
    if(isEmpty()){
        printf("\nThe queue is empty");
    }else if(rear == 0 && front == 0){
        //printf("%d",stack[front]);
        front--;
        rear--;
    }else{
        //printf("%d",stack[front]);
        front--;
    }
}

void enqueue(int value){
    push(value);
    display();
}

void dequeue(){
    pop();
    display();
}

int main()
{

    int val, ch;

start:
    printf("\n-------------MENU--------------");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Exit");

    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    if(ch == 1){
        printf("\nEnter the value: ");
        scanf("%d", &val);
        enqueue(val);
        goto start;
    }else if(ch == 2){
        printf("deleting the first value...\n");
        dequeue();
        goto start;
    }else if(ch = 3){
        goto end;
    }else{
        printf("\n\aError: Enter a value from 1 and 4");
        goto start;
    }

end:
    return 0;
}
