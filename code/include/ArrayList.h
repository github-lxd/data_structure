/**
 * 顺序表
 */
typedef struct {
    int size;           //元素个数
    int capacity;       //容量
    int *data;          //容器
}ArrayList;

//顺序表创建函数
ArrayList *newArrayList(int);
//打印顺序表中的元素
void display(ArrayList*);
//向末尾添加元素(入栈)
void push(ArrayList*, int);
//销毁顺序表
void destroy(ArrayList*);
//获取元素个数
int size(ArrayList*);
//判断是否为空
int isEmpty(ArrayList*);
//返回对应索引的元素
int at(ArrayList*, int);
//返回元素第一次出现的索引
int indexOf(ArrayList*, int);