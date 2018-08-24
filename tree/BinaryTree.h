/*************************************************************************
    > File Name: TREE_BINARYTREE_H
    > Author: 兰州小红鸡
    > email：flymysql@gmail.com
    > github：https://github.com/flymysql
    > Created Time: 18-8-22 下午4:43
 ************************************************************************/

#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H

#include <iostream>
using namespace std;

template<class T>
class BinaryTreeNode {
 //   friend class BinaryTree<T>;
public:
    BinaryTreeNode(T data = (T) 0, BinaryTreeNode<T> *lef = NULL, BinaryTreeNode<T> *rig = NULL);

    T value() const;

    BinaryTreeNode<T> *leftchild() const;

    BinaryTreeNode<T> *rightchild() const;

    void setLeftchild(BinaryTreeNode<T> *lef);

    void setRightchild(BinaryTreeNode<T> *rig);

    void setValue(const T &val);

    bool isLeaf() const;

    BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &Node);

    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    T info;
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T data , BinaryTreeNode<T> *lef , BinaryTreeNode<T> *rig ) {
    info = data;
    left = lef;
    right = rig;
}

template<class T>
T BinaryTreeNode<T>::value() const {
    return info;
}

template<class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::leftchild() const {
    return left;
}

template<class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::rightchild() const {
    return right;
}

template<class T>
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T> *lef) {
    left = lef;
}

template<class T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T> *rig) {
    right = rig;
}

template<class T>
void BinaryTreeNode<T>::setValue(const T &val) {
    info = val;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf() const {
    if (left == NULL && right == NULL)
        return true;
    return false;
}

template<class T>
BinaryTreeNode<T> &BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &Node) {
    left = Node.left;
    right = Node.right;
    info = Node.info;
    return *this;
}

template<class T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;
public:
    BinaryTree(BinaryTreeNode<T> *r = NULL);

    ~BinaryTree() { DeleteBinaryTree(root); };              // 析构函数
    bool isEmpty() const;                                   // 判定二叉树是否为空树
    BinaryTreeNode<T> *Root() { return root; };             // 返回根结点
    BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current);  // 返回父
    BinaryTreeNode<T> *LeftSibling(BinaryTreeNode<T> *current);             // 左兄
    BinaryTreeNode<T> *RightSibling(BinaryTreeNode<T> *current);            // 右兄
    void CreateTree(const T &info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree);      // 构造新树
    void PreOrder(BinaryTreeNode<T> *root);             // 前序遍历二叉树或其子树
    void InOrder(BinaryTreeNode<T> *root);              // 中序遍历二叉树或其子树
    void PostOrder(BinaryTreeNode<T> *root);            // 后序遍历二叉树或其子树
    void LevelOrder(BinaryTreeNode<T> *root);           // 按层次遍历二叉树或其子树
    void DeleteBinaryTree(BinaryTreeNode<T> *root);     // 删除二叉树或其子树
    void visit(BinaryTreeNode<T> *node);
};

template<class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *r ) {

}

template<class T>
bool BinaryTree<T>::isEmpty() const {
    if (root == NULL)
        return true;
    return false;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::Parent(BinaryTreeNode<T> *current) {
    return nullptr;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::LeftSibling(BinaryTreeNode<T> *current) {
    return nullptr;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::RightSibling(BinaryTreeNode<T> *current) {
    return nullptr;
}

template<class T>
void BinaryTree<T>::CreateTree(const T &info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree) {
    root90ol->info = info;
    root->left = (BinaryTree<T> *) leftTree;
    root->right = (BinaryTree<T> *) rightTree;
}

template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *root) {
    if(root!=NULL){
        visit(root);
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
    }
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *root) {
    if(root!=NULL){
        PreOrder(root->leftchild());
        visit(root);
        PreOrder(root->rightchild());
    }
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *root) {
    if(root!=NULL){
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
        visit(root);
    }
}

template<class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T> *root) {

}

template<class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *root) {
    if(root!=NULL){
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
        delete root;
    }
    root=NULL;
}

template<class T>
void BinaryTree<T>::visit(BinaryTreeNode<T> *node) {
    cout<<node->value()<<endl;
}

#endif //TREE_BINARYTREE_H
