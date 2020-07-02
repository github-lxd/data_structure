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
int empty(LinkedList1*);
int at(LinkedList1*, int);
//添加元素到链表首部
void pushFront(LinkedList1*, int);
//在指定位置插入元素
void insert(LinkedList1*, int, int);
//删除指定位置元素
void delete(LinkedList1*, int);
//逆序链表
void reverse(LinkedList1*);