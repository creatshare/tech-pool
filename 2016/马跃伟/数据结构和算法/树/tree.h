typedef struct TreeNode *PtrToNode;
struct TreeNode
{
    ElementType Element;    //当前所存的数据
    PtrToNode FirstChild;   //指向它的第一个儿子
    PtrToNode NextSibling;  //指向它的下一个兄弟
};

//二叉树的链表定义
typedef struct Treenode *BinTree;
typedef BinTree Position;
struct Treenode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

#ifndef _Tree_H

Boolean IsEmpty(BinTree BT); //判断二叉树是否为空
void Traversal(BinTree BT); //遍历，按照某种顺序访问每一个结点
BinTree CreatBinTree(); //创建一个二叉树

void PreOrderTraversal(BinTree BT); //先序 --根，左子树，右子树
void InOrderTraversal(BinTree BT); //中序---左子树，根，右子树
void PostOrderTraversal(BinTree BT); //后序---左子树，右子树，根
void LevelOrderTraversal(BinTree BT); //层次遍历，从上到下，从左到右
void MakeEmpty(BinTree BT); //初始化一棵树
#endif
