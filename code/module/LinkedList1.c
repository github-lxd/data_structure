#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList1.h"

//空指针检测
void checkAddress(void *p) {
    if (p == NULL) {
        printf("NULL Pointer Exception");
        exit(0);
    }
}

int size(LinkedList1* list) {
    checkAddress(list);
    return list->size;
}

LinkedList1* newLinkedList1() {
    Node *head = malloc(sizeof(Node));
    checkAddress(head);
    Node *tail = malloc(sizeof(Node));
    checkAddress(tail);
    LinkedList1 *list = malloc(sizeof(LinkedList1));
    checkAddress(list);
    list->size = 0;
    list->head = head;
    list->head->data = 0;
    list->tail = tail;
    list->tail->data = 0;
    list->head->next = list->tail;
    list->tail->next = NULL;
    return list;
}

void push(LinkedList1* list, int item) {
    Node *node = malloc(sizeof(Node));
    checkAddress(node);
    Node* p = list->head;
    //也可以利用size进行遍历
    while (p->next != list->tail) {
        p = p->next;
    }
    p->next = malloc(sizeof(Node));
    checkAddress(p->next);
    p->next->data = item;
    p->next->next = list->tail;
    list->size++;
}

void display(LinkedList1* list) {
    checkAddress(list);
    printf("Head->");
    for (Node *p = list->head->next; p != list->tail; p = p->next) {
        printf("%d->", p->data);
    }
    printf("Tail\n");
}

int empty(LinkedList1* list) {
    checkAddress(list);
    return list->size == 0;
}

int at(LinkedList1* list, int index) {
    checkAddress(list);
    if (index >= size) {
        printf("Out Of Index Exception\n");
        exit(0);
    }
    Node *p = list->head->next;
    for (int i = 0; i < index; i++)
        p = p->next;
    return p->data;
}

void pushFront(LinkedList1* list, int item) {
    checkAddress(list);
    Node *node = malloc(sizeof(Node));
    checkAddress(node);
    node->data = item;
    node->next = list->head->next;
    list->head->next = node;
    list->size++;
}

void insert(LinkedList1* list, int index, int item) {
    checkAddress(list);
    if (index > list->size) {
        printf("Out Of Index Exception");
        exit(0);
    }
    Node *p = list->head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    Node *node = malloc(sizeof(Node));
    checkAddress(node);
    node->data = item;
    node->next = p->next;
    p->next = node;
    list->size++;
}

void delete(LinkedList1* list, int index) {
    checkAddress(list);
    if (index >= list->size) {
        printf("Out Of Index Exception");
        exit(0);
    }
    Node *p = list->head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    Node *node = p->next;
    p->next = node->next;
    node->next = NULL;
    list->size--;
}

void reverse(LinkedList1* list) {
    checkAddress(list);
    Node* p = list->head->next;
    Node *q = p->next;
    p->next = list->tail;
    Node *r = NULL;
    while (q->next != list->tail) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    q->next = p;
    list->head->next = q;
}