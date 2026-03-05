#include <iostream>
#include <string.h>

typedef struct 
{
    int data;
    Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void push(Stack *st, int angka) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = angka;
    if(st->top == NULL) {
        st->top = new_node;
        new_node->next = NULL;
    }
    new_node->next = st->top;
    st->top = new_node;
}

int pop(Stack *st) {
    int angka = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    free(temp);
    return angka;
}

bool is_palindrom(Stack *st, int angka) {
    return pop(st) == angka;
}

int main() {
    
}