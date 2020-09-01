#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void print_list(struct Node * head){
    head = head->next;
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");

}

void insert_node(struct Node* elem_before, int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = elem_before->next;
    elem_before->next = newNode;
}

void delete_node(struct Node* head, int data){
    struct Node * curr = head->next;
    struct Node * prev = head->next;
    if (curr != NULL && curr->data == data) 
    { 
        head->next = curr->next;    
        free(curr); 
        return; 
    } 
    while (curr != NULL && curr->data != data) 
    { 
        prev = curr; 
        curr = curr->next; 
    } 
    if (curr == NULL) return; 
    prev->next = curr->next; 
  
    free(curr);  // Free memory 
}

struct Node* find_node(struct Node* head,int d){
    struct Node * curr = head->next;
    while (curr != NULL && curr->data != d) 
    {  
        curr = curr->next; 
    } 
    if(curr != NULL)
        return curr;
    else 
        return NULL;
} 

int main(){
    struct Node* head= (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    insert_node(head, 4);
    struct Node * n = find_node(head,4);
    insert_node(n,6);    
    print_list(head);
    delete_node(head,6);
    print_list(head);
}
