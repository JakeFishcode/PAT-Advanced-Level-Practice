#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

#define ElementType int
using namespace std;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
void PostOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    stack<BinTree> S1;
    stack<BinTree> S2; 
    while(T || !S1.empty())
    {
        while(T)        //一直向右并将沿途节点访问（压入S2）后压入堆栈S1 
        {
            S2.push(T);
            S1.push(T);
            T = T->Right;
        }
        if (!S1.empty())
        {
            T = S1.top();    //节点弹出堆栈
            S1.pop();
            T = T->Left;  //转向左子树
        }
    }
    while(!S2.empty())    //访问（打印）S2中元素
    {
        T = S2.top();
        S2.pop();
        if(S2.empty())
            printf("%d", T->Data);
        else 
            printf("%d ", T->Data);
    }          
}
int main(void)
{
    stack<BinTree> temp;
    BinTree ptree=NULL,tree=NULL,first=NULL;
    string ml;
    ElementType data;
    int num=0,flag=0;
    cin >> num;
    for(int i=0;i<num*2;i++)
    {
        cin >> ml;
        if(ml == "Push")
        {
            cin >> data;
            ptree = tree;
            tree = (BinTree)malloc(sizeof(TNode));
            if(flag==0) first=tree;
            flag++;
            tree->Right=NULL;
            tree->Left=NULL;
            tree->Data = data;
            if(ptree!=NULL)
            {
                if(ptree->Left==NULL)
                {
                    ptree->Left=tree;
   
                }
                else if(ptree->Right==NULL)
                {   
                    ptree->Right=tree;

                }
            }
            temp.push(tree);
        }
        else if(ml == "Pop")
        {
            tree = temp.top();
            temp.pop();
        }
    }
    PostOrderTraversal(first);
    return 0;
}