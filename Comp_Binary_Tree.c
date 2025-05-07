/*
Group members:
Ireri Mark Muthomi - SCT221-0098/2023
Denis Mwedia - SCT221-0091/2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

int no_of_valuesInA;
int no_of_valuesInB;
int no_of_valuesInC;

int no_of_leftSubtreeValues;
int no_of_rightSubtreeValues;

struct Node* A = NULL;
struct Node* B = NULL;
struct Node* C = NULL;

int getNoOfValuesInA(struct Node* root){
    
    if(root == NULL){
        return no_of_valuesInA;
    }else{
        no_of_valuesInA++;
        getNoOfValuesInA(root -> left);
        getNoOfValuesInA(root -> right);
    }
}
int getNoOfValuesInB(struct Node* root){
    
    if(root == NULL){
        return no_of_valuesInB;
    }else{
        no_of_valuesInB++;
        getNoOfValuesInB(root -> left);
        getNoOfValuesInB(root -> right);
    }
}
int getNoOfValuesInC(struct Node* root){
    
    if(root == NULL){
        return no_of_valuesInC;
    }else{
        no_of_valuesInC++;
        getNoOfValuesInC(root -> left);
        getNoOfValuesInC(root -> right);
    }
}

void compareBinaryTree(struct Node* A, struct Node* B, struct Node* C){
    int a, b, c, largest;
    no_of_valuesInA = 0;
    no_of_valuesInB = 0;
    no_of_valuesInC = 0;

    a = getNoOfValuesInA(A);
    printf("\nA = %d", a);
    b = getNoOfValuesInB(B);
    printf("\nB = %d", b);
    c = getNoOfValuesInC(C);
    printf("\nC = %d", c);

    if(a == b && a == c && b == c){
        if(a == 0){
            printf("\nAll trees have 0 nodes");
        }else{
            printf("\nAll trees have equal number of nodes");
        }
    }else if(a == b){
        largest = (a > c) ? a : c;
        if(largest == c){
            printf("\nC is the largest binary tree");
        }else{
            printf("\nA and B are the largest binary trees");
        }
    }else if(a == c){
        largest = (a > b) ? a : b;
        if(largest == b){
            printf("\nB is the largest binary tree");
        }else{
            printf("\nA and C are the largest binary trees");
        }
    }else if(b == c){
        largest = (a > b) ? a : b;
        if(largest == a){
            printf("\nA is the largest binary tree");
        }else{
            printf("\nB and C are the largest binary trees");
        }
    }else{
        largest = ((a > b) && (a > c)) ? a : ((b > c) ? b : c);

        if(largest == a){
            printf("\nA is the largest binary tree");
        }else if(largest == b){
            printf("\nB is the largest binary tree");
        }else{
            printf("\nC is the largest binary tree");
        }
    }
   
}

struct Node* traverseLeftSubTree(struct Node* root){
    no_of_leftSubtreeValues = 0;

    while(root -> left != NULL){
        root = root -> left;
        no_of_leftSubtreeValues++;
   }
   return root;
}

struct Node* traverseRightSubTree(struct Node* root){
    no_of_rightSubtreeValues = 0;

    while(root -> right != NULL){
        root = root -> right;
        no_of_rightSubtreeValues++;
    }
   return root;
}

void link(struct Node* root, struct Node* left, struct Node* right){

    if((no_of_leftSubtreeValues - no_of_rightSubtreeValues) >= 1){
        struct Node* current = traverseRightSubTree(root);
        current -> left = left;
        current -> right = right;
    }else{
        struct Node* current = traverseLeftSubTree(root);
        current -> left = left;
        current -> right = right;
    }
       
}

void preorder(struct Node* root){
    if(root == NULL){
        return;
    }else{
        printf("%d ",root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void traverse(){
    printf("\nA: ");
    preorder(A);
    printf("\nB: ");
    preorder(B);
    printf("\nC: ");
    preorder(C);
}

void insert(int leftVal, int rightVal, int tree){
    struct Node* tempLeft = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tempRight = (struct Node*)malloc(sizeof(struct Node));

    tempLeft -> data = leftVal;
    tempLeft -> left = NULL;
    tempLeft -> right = NULL;

    tempRight -> data = rightVal;
    tempRight -> left = NULL;
    tempRight -> right = NULL;

    if(tree == 1){
        if(A == NULL){
            A = (struct Node*)malloc(sizeof(struct Node));
            A -> data = 1;
            A -> left = tempLeft;
            A -> right = tempRight;

            printf("Preorder traversal of binary tree A after insertion: \n");
            preorder(A);
        }else{
            struct Node* current = A;

            link(current, tempLeft, tempRight);
            printf("Preorder traversal of binary tree A after insertion: \n");
            preorder(current);
        }
    }else if(tree == 2){
        if(B == NULL){
            B = (struct Node*)malloc(sizeof(struct Node));
            B -> data = 2;
            B -> left = tempLeft;
            B -> right = tempRight;
            printf("Preorder traversal of binary tree B after insertion: \n");
            preorder(B);
        }else{
            struct Node* current = B;

            link(current, tempLeft, tempRight);
            printf("Preorder traversal of binary tree B after insertion: \n");
            preorder(current);
        }
    }else{
        if(C == NULL){
            C = (struct Node*)malloc(sizeof(struct Node));
            C -> data = 3;
            C -> left = tempLeft;
            C -> right = tempRight;
            printf("Preorder traversal of binary tree C after insertion: \n");
            preorder(C);
        }else{
            struct Node* current = C;

            link(current, tempLeft, tempRight);
            printf("Preorder traversal of binary tree C after insertion: \n");
            preorder(current);
        }
    }
}

bool isValid(int val){

    if(val < 1 || val > 3){
        return false;
    }else{
        return true;
    }
}

int main(){
    int choice, tree, left, right;

    do{
        printf("\n--------------Menu---------------");
        printf("\n1. Insert");
        printf("\n2. Compare");
        printf("\n3. Traverse");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
        insert:
            printf("\nEnter the binary tree you want to insert to[1 for A, 2 for B and 3 for C]: ");
            scanf("%d", &tree);

            if(isValid(tree)){
                printf("\nEnter value for left sub-tree: ");
                scanf("%d", &left);

                printf("Enter value for right sub-tree: ");
                scanf("%d", &right);

                if(tree == 1){
                    insert(left,right,tree);
                }else if(tree == 2){
                    insert(left,right,tree);
                }else{
                    insert(left,right,tree);
                }
                
            }else{
                printf("Invalid choice: Please enter a valid tree");
                goto insert;
            }
            
        }else if(choice == 2){
            compareBinaryTree(A, B, C);
        }else if(choice == 3){
            traverse();
        }else if(choice == 4){
            printf("\nExiting program..\n");
        }else{
            printf("Invalid choice. Please try again.\n");
        }

    }while(choice != 4);

}