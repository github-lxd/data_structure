#include <stdio.h>
#include <stdlib.h>
#include "include/LinkedList1.h"

int main() {
    LinkedList1 *list = newLinkedList1();
    for (int i = 1; i < 7; i++)
        push(list, i);
    display(list);
    return 0;
}