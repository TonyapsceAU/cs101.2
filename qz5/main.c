#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

void show_list(node_t *list){
    while(list != NULL){
        printf("[%d]->",list->data);
        list = list->next;
    }
    printf("null\n");
}

node_t* allocate_node(int data){
    node_t* new = (node_t*)malloc(sizeof(node_t*));
    new->next = NULL;
    new->data = data;
    return new; 
}

node_t* append_node(node_t* list,int data){
    node_t *direct = list;
    node_t *prev = NULL;
    node_t * new = allocate_node(data);

    while (direct) {
        prev = direct;           
        direct = direct->next;
    }

    if (prev){
        prev->next = new;
    }else{
        list = new;
    }
    
    return list;
}

void free_all_nade(node_t* list){
    node_t *current, *tmp;
    current = list;
    while(current != NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main(){
    node_t* head = NULL;
    head = append_node(head,0);
    show_list(head);
    head = append_node(head,11);
    show_list(head);
    head = append_node(head,222);
    show_list(head);
    head = append_node(head,3333);
    show_list(head);
    
    

    return 0;
}
