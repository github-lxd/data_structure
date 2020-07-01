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

int at(ArrayList* list, int index) {
    checkAddress(list);
    return list->data[index];
}

int indexOf(ArrayList* list, int item) {
    checkAddress(list);
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == item) {
            index = i;
            break;
        }
    }
    return index;
}

int pop(ArrayList* list) {
    checkAddress(list);
    int pop = list->data[--list->size];
    list->data[list->size] = 0;
    return pop;
}

void insert(ArrayList* list, int index, int item) {
    checkAddress(list);
    resize(list);
    for (int i = list->size; i >= index; i++)
        list->data[i + 1] = list->data[i];
    list->data[index] = item;
    list->size++;
}

void delete(ArrayList* list, int index) {
    checkAddress(list);
    for (int i = index; i < list->size - 1; i++)
        list->data[i] = list->data[i + 1];
    list->data[list->size - 1] = 0;
    list->size--;
}

void _remove(ArrayList* list, int item) {
    checkAddress(list);
    for (int i = list->size; i >= 0; i--) {
        if (list->data[i] == item) {
            delete(list, i);
        }
    }
}