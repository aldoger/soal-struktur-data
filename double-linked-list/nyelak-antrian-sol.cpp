#include <iostream>
#include<stdlib.h>

typedef struct {
    char *nama;
    Person *next;
    Person *prev;
} Person;

typedef struct {
    Person *head;
    Person *tail;
    int jumlah;
} Antrian;

void masuk_antrian(Antrian *at, char *nama) {
    Person *p = (Person*) malloc(sizeof(Person));
    p->nama = nama;
    if(at->head == NULL && at->tail == NULL) {
        at->head = p;
        at->tail = p;
        at->jumlah++;
        return;
    }
    at->tail->next = p;
    p->prev = at->tail;
    at->tail = p;
    at->jumlah++;
}

char* nomor_antrian(Antrian *at, int nomor) {
    if(at->jumlah < nomor) {
        std::cout << "error: nomor melebihi antrian" << '\n';
        return;
    }
    Person *current = at->head;
    int currentNomor = 0;
    while (currentNomor != nomor) 
    {
        current = current->next;
    }
    return current->nama; 
}

void nyelak_antrian(Antrian *at, int nomor, char *nama) {
    Person *p = (Person*) malloc(sizeof(Person));
    p->nama = nama;
    if(at->head == NULL && at->tail == NULL) {
        at->head = p;
        at->tail = p;
        at->jumlah++;
        return;
    }
    Person *current = at->head;
    int currentNomor = 0;
    while (currentNomor != nomor) 
    {
        current = current->next;
    }
    p->next = current->next;
    current->next = p;
    p->prev = current;
}

int main() {
    
}