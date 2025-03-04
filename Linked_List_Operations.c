#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void traverse(){
    struct Node * current = head;

    if(current == NULL){
        printf("\nThe linked list is empty");
    }else{
        printf("Elements:");
        while(current != NULL){
            printf(" %d",current -> data);
            current = current -> next;
        }
    }
}

void insert_at_front(int value){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> next = NULL;

    if(head == NULL){
        head = ptr;
    }else{
        struct Node *current = head;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = ptr;
    }
    traverse();

}

void delete_value(int value) {
    struct Node *current = head;
    struct Node *prev = NULL; // Keep track of the previous node
    bool status = false;

    if (current == NULL) {
        printf("\nThe linked list is empty");
    } else {
        while (current != NULL) {
            if (current->data == value) {
                if (current == head) { // If the value to be deleted is the first in the linked list
                    head = current -> next;
                    free(current);
                    status = true;
                    break;
                } else {
                    prev -> next = current->next; // Link the previous node to the next node
                    free(current);
                    status = true;
                    break;
                }
            }
            prev = current; // Move the 'prev' pointer one step forward
            current = current -> next;
        }
        if (status) {
            traverse();
        } else {
            printf("\nThe value has not been found");
        }
    }
}

void search(int value){
    struct Node *current = head;
    bool status = false;

    if(current == NULL){
        printf("\nThe list is empty");
    }else{
        while(current != NULL){
            if(current -> data == value){
                status = true;
                break;
            }
            current = current -> next;
        }
    }

    if(status){
        printf("\nThe value has been found");
    }else{
        printf("\nThe value has not been found");
    }

}


int main()
{
    int value, ch;

start:
    printf("\n\n-----Operations Menu-------");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Search");
    printf("\n4. Traverse");
    printf("\n5. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);

    if(ch == 1){
        printf("\nEnter the integer value you want to insert: ");
        scanf("%d",&value);
        insert_at_front(value);
        goto start;
    }else if(ch == 2){
        printf("\nEnter the integer value you want to delete: ");
        scanf("%d",&value);
        delete_value(value);
        goto start;
    }else if(ch == 3){
        printf("\nEnter the integer value you want to search for: ");
        scanf("%d",&value);
        search(value);
        goto start;
    }else if(ch == 4){
        printf("\n");
        traverse();
        goto start;
    }else if(ch == 5){
        goto end;
    }else{
        printf("\a\nError: Please enter a valid choice\n\n");
        goto start;
    }

end:
    return 0;


}