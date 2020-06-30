#include <stdio.h>
#include <stdlib.h>
#include "../include/ArrayList.h"

//空指针检测
void checkAddress(void *p) {
    if (p == NULL) {
        printf("NULL Pointer Exception");
        exit(0);
    }
}

//若需要扩容则进行扩容(针对单个元素)
void resize(ArrayList* list) {
    if (list->size >= list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        int *data = realloc(list->data, sizeof(int) * newCapacity);
        checkAddress(data);
        list->data = data;
        list->capacity = newCapacity;
    }
}

ArrayList *newArrayList(int capacity) {
    int *data = malloc(sizeof(int) * capacity);
    checkAddress(data);
    ArrayList* list = malloc(sizeof(ArrayList));
    checkAddress(list);
    list->data = data;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void display(ArrayList* list) {
    checkAddress(list);
    for (int i = 0; i < list->size - 1; i++)
        printf("%d ", list->data[i]);
    printf("%d\n", list->data[list->size - 1]);
}

void push(ArrayList* list, int item) {
    checkAddress(list);
    resize(list);
    list->data[list->size++] = item;
}

void destroy(ArrayList* list) {
    checkAddress(list);
    free(list->data);
    list->data = NULL;
    free(list);
}

int size(ArrayList* list) {
    checkAddress(list);
    return list->size;
}

int isEmpty(ArrayList* list) {
    checkAddress(list);
    return list->size == 0;
}

