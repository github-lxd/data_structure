#include <stdio.h>
#include <stdlib.h>
#include "../include/Tree.h"

BinaryTree* newBinaryTree(int count, int index) {
    if (index <= count) {
        BinaryTree* node = malloc(sizeof(BinaryTree));
        node->data = index;
        node->left = newBinaryTree(count, 2 * index);
        node->right = newBinaryTree(count, 2 * index + 1);
        return node;
    } else return NULL;
}

void preOrderTraverseRecursion(BinaryTree* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTraverseRecursion(root->left);
        preOrderTraverseRecursion(root->right);
    }
}

/**
 * 此处只实现固定容量的栈
 */
typedef struct {
    BinaryTree** data;
    int top;
}Stack;

Stack* newStack() {
    Stack* stack = malloc(sizeof(Stack));
    BinaryTree** data = malloc(sizeof(BinaryTree*) * 128);
    stack->data = data;
    stack->top = -1;
    return stack;
}

int stackEmpty(Stack* stack) {
    if (stack->top == -1) return 1;
    return 0;
}

void push(Stack* stack, BinaryTree* node) {
    stack->data[++stack->top] = node;
}

BinaryTree* pop(Stack* stack) {
    return stack->data[stack->top--];
}

void preOrderTraverseIteration(BinaryTree* root) {
    Stack* stack = newStack();
    //根节点入栈
    push(stack, root);
    BinaryTree* node = NULL;
    while (stack->top != -1) {
        node = pop(stack);
        while (node) {
            printf("%d ", node->data);
            if (node->right)
                push(stack, node->right);
            node = node->left;
        }
    }
}

void inOrderTraversalRecursion(BinaryTree* root) {
    if (root) {
        inOrderTraversalRecursion(root->left);
        printf("%d ", root->data);
        inOrderTraversalRecursion(root->right);
    }
}

void inOrderTraversalIteration(BinaryTree* root) {
    Stack* stack = newStack();
    BinaryTree* node = root;
    while (stack->top != -1 || node) {
        if (node) {
            push(stack, node);
            node = node->left;
        } else {
            node = pop(stack);
            printf("%d ", node->data);
            node = node->right;
        }
    }
}

void nextOrderTraversalRecursion(BinaryTree* root) {
    if(root) {
        nextOrderTraversalRecursion(root->left);
        nextOrderTraversalRecursion(root->right);
        printf("%d ", root->data);
    }
}

/**
 * 此处使用双栈方式实现
 * @param root
 */
void nextOrderTraversalIteration(BinaryTree* root) {
    Stack* stack1 = newStack();
    Stack* stack2 = newStack();
    //根节点入栈
    push(stack1, root);
    BinaryTree* node = NULL;
    while (stack1->top != -1) {
        node = pop(stack1);
        while (node) {
            push(stack2, node);
            if (node->left)
                push(stack1, node->left);
            node = node->right;
        }
    }
    while (stack2->top != -1)
        printf("%d ", pop(stack2)->data);
}

int set[5] = {0};
void powerSet(int i, int n) {
    if (i > n) {
        for (int j = 1; j <= n; j++) {
            if (set[j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    } else {
        set[i] = 0;
        powerSet(i + 1, n);
        set[i] = 1;
        powerSet(i + 1, n);
    }
}

#define N 8
void trial(int* queens, int curRow) {
    if (curRow > N) {
        for (int i = 1; i <= N; i++)
            printf("%d ", queens[i]);
        printf("\n");
    }
    //试探第curRow行的可行列
    for (int curCol = 1; curCol <= N; curCol++) {
        int flag = 1;
        //遍历之前所有行
        for (int row = 1; row < curRow; row++) {
            //获取第row行的列数
            int col = queens[row];
            //判断是否位于同一列
            if (col == curCol) {
                flag = 0;
                break;
            }
            //判断是否位于同一副对角线
            if (row + col == curCol + curRow) {
                flag = 0;
                break;
            }
            //判断是否处于同一主对角线
            if (row - col == curRow - curCol) {
                flag = 0;
                break;
            }
        }
        if (flag || curRow == 1) {
            //当前布局合法
            queens[curRow] = curCol;
            //查找下一行布局
            trial(queens, curRow + 1);
        }
    }
}
