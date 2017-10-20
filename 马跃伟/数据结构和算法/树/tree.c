#include"tree.h"
#include <stdio.h>

void PreOrderTraversal(BinTree BT) //先序 --根，左子树，右子树
{
    if(BT)
    {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
void InOrderTraversal(BinTree BT) //中序---左子树，根，右子树
{
  if(BT)
    {
        PreOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Right);
    }
}
void PostOrderTraversal(BinTree BT) //后序---左子树，右子树，根
{
    if(BT)
    {
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}
