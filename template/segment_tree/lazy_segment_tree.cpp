/**
 * @file lazy_segment_tree.cpp
 * @author your name (you@domain.com)
 * @brief Adding on segments, querying for maximum
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define INF 0x3f3f3f3f

// we store the Segment Tree as an array t[] with a size of four times the input size n:
int n, t[4 * MAXN], lazy[4 * MAXN];

/**
 * @brief constructing the Segment Tree t[] from a given array a[]
 *
 * @param a the input array
 * @param v the index of the current vertex
 * @param tl the left boundaries of the current segment
 * @param tr the right boundaries of the current segment
 */
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void push(int v)
{
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

/**
 * @brief maximum from a[l] to a[r]
 *
 * @param v the index of the current vertex
 * @param tl the left boundaries of the current vertex/segment
 * @param tr the right boundaries of the current vertex/segment
 * @param l the left boundaries of the query
 * @param r the right boundaries of the query
 * @return int
 */
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

/**
 * @brief
 *
 * @param v the index of the current vertex
 * @param tl the left boundaries of the current vertex/segment
 * @param tr the right boundaries of the current vertex/segment
 * @param l the left boundaries of the update segment
 * @param r the right boundaries of the update segment
 * @param addend added value
 */
void update(int v, int tl, int tr, int l, int r, int addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        t[v] += addend;
        lazy[v] += addend;
    }
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int main()
{
    return 0;
}