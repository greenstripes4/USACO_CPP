/**
 * @file struct_segment_tree.cpp
 * @author your name (you@domain.com)
 * @brief Finding subsegments with the maximal sum
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

// This time we will store four values for each vertex:
// the sum of the segment,
// the maximum prefix sum,
// the maximum suffix sum,
// and the sum of the maximal subsegment in it.
struct tdata
{
    int sum, pref, suff, ans;
};

tdata t[4 * MAXN];

tdata combine(tdata l, tdata r)
{
    tdata res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

tdata make_data(int val)
{
    tdata res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = make_data(a[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = make_data(new_val);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

tdata query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
    return 0;
}