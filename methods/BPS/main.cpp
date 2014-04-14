//lrj���ž���101ҳ
//������BPS�������봴��������������ж��������
//�漰ϡ�趯̬�ṹ������

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn=300;

char read[maxn];

typedef struct TNode   //��ʾһ���������ڵ�
{
    TNode()
    {
        reset();
    }
    void reset()
    {
        val=0;
        visited=0;
        left=NULL;
        right=NULL;
    }
    int val;
    bool visited;
    struct TNode *left,*right;
} Node;

void addNode(Node* tree,char* r) //����һ����
{

    int v;
    char a;
    sscanf(r,"%c%d",&a,&v);
    r=strchr(r,',')+1;
    int n=strlen(r);
    for(int i=0; i<n; ++i)
    {
        switch(r[i])
        {
        case 'L':
            if(tree->left==NULL) tree->left=new Node;
            tree=tree->left;
            break;
        case 'R':
            if(tree->right==NULL) tree->right=new Node;
            tree=tree->right;
            break;
        }
    }
    if(tree->visited)
        tree->val=-1;
    else
    {
        tree->val=v;
        tree->visited=1;
    }
}

Node* dui[maxn]= {0};
int out[maxn];
void printandreset(Node *root) //���ѽ��õ������жϲ����������ͷ��ڴ�
{
    int front=0,rear=1;
    bool fault=0;
    dui[front]=root;
    if(dui[front]==NULL)
        return;
    while(front!=rear)
    {
        if(dui[front]==NULL) break;
        if(dui[front]->visited==0||dui[front]->val==-1)
        {
            fault=1;
            break;
        }
        if(dui[front]->left!=NULL)
        {
            dui[rear++]=dui[front]->left;
        }
        if(dui[front]->right!=NULL)
        {
            dui[rear++]=dui[front]->right;
        }
        out[front]=dui[front]->val;
        ++front;
    }
    if(fault)
        cout<<-1<<endl;
    else
        for(int i=0; i<front; ++i)
            cout<<out[i]<<" ";
    for(int i=1; i<front; ++i)
        delete dui[i];
    root->left=root->right=NULL;
    root->visited=0;
    cout<<endl;
}


int main()
{
    freopen("in.txt","r",stdin);
    char ch;
    Node root;
    while(1)
    {
        while(1)  //per tree
        {
            int num=0;
            cin>>ch;
            if(!cin) return 0;
            while(ch!=')')
            {
                read[num++]=ch;
                cin>>ch;
            }
            read[num]=0;
            if(!strcmp(read,"("))
                break;
            addNode(&root,read);
        }
        printandreset(&root);
    }
    return 0;
}
