#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int parent[MAXN], tsize[MAXN];
//------basic version
// join by size
void make_set(int v)
{
    parent[v] = v;
    tsize[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (tsize[a] < tsize[b])
            swap(a, b);
        parent[b] = a;
        tsize[a] += tsize[b];
    }
}

//-------------------Support distances up to representative
//-----join by rank
pair<int, int> pparent[MAXN];
int rrank[MAXN];
void make_pset(int v)
{
    pparent[v] = make_pair(v, 0);
    rrank[v] = 0;
}

pair<int, int> find_pset(int v)
{
    if (v != pparent[v].first)
    {
        int len = pparent[v].second;
        pparent[v] = find_pset(pparent[v].first);
        pparent[v].second += len;
    }
    return pparent[v];
}

void union_psets(int a, int b)
{
    a = find_pset(a).first;
    b = find_pset(b).first;
    if (a != b)
    {
        if (rrank[a] < rrank[b])
            swap(a, b);
        pparent[b] = make_pair(a, 1);
        if (rrank[a] == rrank[b])
            rrank[a]++;
    }
}

int main()
{
    return 0;
}