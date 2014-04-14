#include<cstdio>
  2 #include<cstring>
  3 #include<algorithm>
  4 #include<cmath>
  5 #include<vector>
  6 using namespace std;
  7
  8 template<class T>
  9 class Heap
 10 {
 11 public:
 12         Heap() { a.resize(1); size=0; }
 13         T top() { return a[1]; }
 14         void push(T x)
 15         {
 16                 int p;
 17                 a.push_back(x);
 18                 for(p=++size;p>1 && x<a[p>>1];p>>=1)
 19                         a[p]=a[p>>1];
 20                 a[p]=x;
 21         }
 22         void pop()
 23         {
 24                 int p,child;
 25                 T x=a[size--];
 26                 a.pop_back();
 27                 for(p=1;(p<<1)<=size;p=child)
 28                 {
 29                         child=(p<<1);
 30                         if(child<size && a[child+1]<a[child]) child++;
 31                         if(a[child]<x) a[p]=a[child];
 32                         else break;
 33                 }
 34                 a[p]=x;
 35         }
 36 private:
 37         vector<T> a;
 38         int size;
 39 };
 40
 41 #define HB 910109
 42 class Hash
 43 {
 44 public:
 45         Hash() { a=(sqrt(5.0)-1)*0.5; memset(board,0,sizeof(board)); }
 46         bool find(int x)
 47         {
 48                 for(Node *p=board[hash(x)];p;p=p->next)
 49                         if(p->v==x) return true;
 50                 return false;
 51         }
 52         void insert(int x)
 53         {
 54                 int i=hash(x);
 55                 board[i]=new Node(x,board[i]);
 56         }
 57 private:
 58         double a;
 59         struct Node
 60         {
 61                 int v;
 62                 Node *next;
 63                 Node(int _v,Node *_next):v(_v),next(_next) {}
 64         }*board[HB];
 65         double xiaoshu(double x) { return x-int(x); }
 66         int hash(int x)
 67         {
 68                 return int(xiaoshu(a*x)*HB);
 69         }
 70 };
 71
 72 int gcd(int a,int b)
 73 {
 74         while(b) { int t=a%b; a=b; b=t; }
 75         return a;
 76 }
 77
 78 struct Type
 79 {
 80         int x,y,f;
 81         Type() {}
 82         Type(int _x,int _y,int _f):x(_x),y(_y),f(_f) {}
 83         friend bool operator<(const Type &a,const Type &b)
 84         {
 85                 return a.f<b.f;
 86         }
 87 };
 88
 89 int n,lim;
 90 Heap<Type> q;
 91
 92 int h(int x,int y)
 93 {
 94         if(x==n || y==n) return 0;
 95         int ret,t;
 96         for(ret=0,t=x;t<n;ret++) t<<=1;
 97         return ret;
 98 }
 99
100 void gen(int x,int y,int g)
101 {
102         if(x<y) swap(x,y);
103         if(x==0 || x>lim || n%gcd(x,y)) return;
104         q.push(Type(x,y,g+h(x,y)));
105 }
106
107 #define generate(x,y) gen(x,y,g+1)
108 int Astar()
109 {
110         Hash visited;
111         q.push(Type(1,0,h(1,0)));
112         while(1)
113         {
114                 int x=q.top().x,y=q.top().y,g=q.top().f-h(x,y);
115                 q.pop();
116                 if(visited.find(x*40000+y)) continue;
117                 visited.insert(x*40000+y);
118                 if(x==n || y==n) return g;
119                 generate(x+x,y);
120                 generate(x+y,y);
121                 generate(y+y,y);
122                 generate(0,y);
123                 generate(abs(x-y),y);
124                 generate(x,x+x);
125                 generate(x,x+y);
126                 generate(x,y+y);
127                 generate(x,0);
128                 generate(x,abs(x-y));
129         }
130 }
131
132 int main()
133 {
134         scanf("%d",&n);
135         for(lim=1;lim<n;lim<<=1);
136         printf("%d\n",Astar());
137         return 0;
138 }

