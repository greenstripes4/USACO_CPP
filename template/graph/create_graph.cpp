#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 10000; //最大顶点数
const int maxm = 10000; //最大边数
int cnt = 0;            //边数
int head[maxn];         //头节点数组，存储每个顶点(从i出发)的第一条边(相当于头指针,指向首元结点)

struct node
{
    int next;
    int to;
    int w;
} edge[maxm]; //注意edge存的是所有边数(边的连接信息,终点,权值,下条边都在这里),无向图每条边要输入两次

void add(int u, int v, int w) //加边操作
{
    edge[cnt].next = head[u]; //相当于链表前插法,新结点指向了头指针指的结点
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++; //前插完成,头指针已经指向了新结点
}

int main()
{
    memset(head, -1, sizeof(head));
    int u, v, w;
    for (int i = 0; i < maxm; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        //无向图加反向边
        add(v, u, w);
    }

    int x = 0;
    for (int i = head[x]; i != -1; i = edge[i].next) //遍历(与某个点x连接的所有边和点)
    {
        cout << x << ' ' << edge[i].to << endl; //输出这条边的两个端点(x一直是一端,存的就是所有与它连接的点)
        cout << edge[i].w << endl;              //输出这条边的权值
    }
    return 0;
}