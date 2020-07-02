#include <stdio.h>
#include <stdlib.h>
#include "include/LinkedList1.h"

int main() {
    LinkedList1 *list = newLinkedList1();
    for (int i = 1; i < 7; i++)
        push(list, i);
    display(list);
    pushFront(list, 11);
    display(list);
    insert(list, 1, 12);
    display(list);
    insert(list, 0, 13);
    display(list);
    insert(list, list->size, 14);
    display(list);
    reverse(list);
    display(list);
    printf("%d\n", list->size);
    return 0;
}