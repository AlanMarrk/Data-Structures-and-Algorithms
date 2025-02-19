#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0; // Current size of the array

// Function to display the array elements
void display() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insert(int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
    printf("Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element at a specific position
void delete(int position) {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Element at position %d deleted.\n", position);
}

int main() {
    int choice, element, position;

    do {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insert(element, position);
                break;
            case 2:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}