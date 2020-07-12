/**
 * 二叉树结点
 */
typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
}BinaryTree;

//完全二叉树生成算法
BinaryTree* newBinaryTree(int, int);
//二叉树先序遍历递归算法
void preOrderTraverseRecursion(BinaryTree*);
//二叉树先序遍历迭代算法
void preOrderTraverseIteration(BinaryTree*);
//二叉树中序遍历递归算法
void inOrderTraversalRecursion(BinaryTree*);
//二叉树中序遍历迭代算法
void inOrderTraversalIteration(BinaryTree*);
//二叉树后续遍历递归算法
void nextOrderTraversalRecursion(BinaryTree*);
//二叉树后序遍历迭代算法
void nextOrderTraversalIteration(BinaryTree*);

//求幂集(回溯算法，状态树)
void powerSet(int, int);
//8皇后
void trial(int*, int);
