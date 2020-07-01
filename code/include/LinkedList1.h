/**
 * 结点
 */
typedef struct node{
    int data;
    struct node *next;
}Node;

/**
 * 单链表
 */
typedef struct {
    Node *head;
    Node *tail;
    int size;
}LinkedList1;

int size(LinkedList1*);
LinkedList1* newLinkedList1();
void push(LinkedList1*, int);
void display(LinkedList1*);