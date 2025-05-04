#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Append node and update size
void append_node(struct Node** head_ref, int data, int* size) {
    struct Node* new_node = create_node(data);

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    (*size)++; // increment size
}

// Print list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int hasLoop(struct Node* head){
    struct Node* fast = head;
    struct Node* slow = head;

    while (fast == NULL && fast -> next == NULL){
        if (fast == slow){
            return 1;
        }
            fast = (fast -> next)-> next;
            slow = slow -> next;
    }
    return NULL; 
}

void loopLocation(struct Node* head){
    struct Node* cur = head;
    
    if (hasLoop(head) == 1){
        while (cur != NULL)
    }
    return;
}

void removeLoop(struct Node* head, struct node* ){
    struct Node* current = head;
    while current
}