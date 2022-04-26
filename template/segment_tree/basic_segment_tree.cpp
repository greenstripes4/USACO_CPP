#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

// we store the Segment Tree as an array t[] with a size of four times the input size n:
int n, t[4 * MAXN];

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
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

/**
 * @brief sum from a[l] to a[r]
 *
 * @param v the index of the current vertex
 * @param tl the left boundaries of the current vertex/segment
 * @param tr the right boundaries of the current vertex/segment
 * @param l the left boundaries of the query
 * @param r the right boundaries of the query
 * @return int
 */
int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

/**
 * @brief
 *
 * @param v the index of the current vertex
 * @param tl the left boundaries of the current vertex/segment
 * @param tr the right boundaries of the current vertex/segment
 * @param pos the position of the element to be updated
 * @param new_val new value
 */
void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    return 0;
}