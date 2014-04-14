#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct TreeNode
{
    TreeNode *left,*right;
    char c;
    TreeNode():left(0),right(0){}
    void getNext(char *pre,char *ino)
    {
        c=pre[0];
        int m,l=strlen(ino);
        for(int i=0;i<l;i++)
        {
            if(ino[i]==c)
            {
                m=i;
                break;
            }
        }
        ino[m]=0;
        if(m!=l-1)
        {
            right=new TreeNode();
            right->getNext(&pre[m+1],&ino[m+1]);
        }
        if(m)
        {
            left=new TreeNode();
            pre[m+1]=0;
            ino[m]=0;
            left->getNext(&pre[1],ino);
        }
    }
    void reset()
    {
        if(left)
        {
            delete left;
            left=0;
        }
        if(right)
        {
            delete right;
            right=0;
        }
    }
};

void print(TreeNode *a)
{
    if(a->left)
        print(a->left);
    if(a->right)
        print(a->right);
    printf("%c",a->c);
}

int main()
{
    freopen("in.txt","r",stdin);
    char pre[30],ino[30];
    TreeNode root;
    while(~scanf("%s%sd",pre,ino))
    {
        root.getNext(pre,ino);
        print(&root);
        putchar('\n');
    }
    return 0;
}
