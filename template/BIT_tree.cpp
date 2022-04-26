#include <bits/stdc++.h>
using namespace std;

// Finding sum in one-dimensional array
struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

struct FenwickTreeOneBasedIndexing
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    // same as range_add(i, i, val)
    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    // ONLY for Range Update and Point Query
    // Let the Fenwick tree be initialized with zeros.
    /*
    void range_add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    */
};

struct FenwickTree2D
{
    vector<vector<int>> bit;
    int n, m;

    // init(...) { ... }
    FenwickTree2D(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (size_t i = 0; i < bit.size(); i++)
            bit[i].assign(m, 0);
    }

    FenwickTree2D(vector<vector<int>> a) : FenwickTree2D(a.size(), a[0].size())
    {
        for (size_t i = 0; i < a.size(); i++)
            for (size_t j = 0; j < a[0].size(); j++)
                add(i, j, a[i][j]);
    }

    int sum(int x, int y)
    {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta)
    {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

// Finding sum in one-dimensional array with range update
struct FenwickTreeRange
{
    // Range Updates and Range Queries
    // To support this we will use two BITs namely B1[] and B2[], initialized with zeros.
    vector<int> B1; // binary indexed tree
    vector<int> B2; // binary indexed tree
    int n;

    FenwickTreeRange(int n)
    {
        this->n = n;
        B1.assign(n, 0);
        B2.assign(n, 0);
    }

    FenwickTreeRange(vector<int> a) : FenwickTreeRange(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            range_add(i, i, a[i]);
    }

    int sum(vector<int> bit, int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    void add(vector<int> bit, int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void range_add(int l, int r, int x)
    {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }

    int prefix_sum(int idx)
    {
        return sum(B1, idx) * idx - sum(B2, idx);
    }

    int range_sum(int l, int r)
    {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

int main(){
    return 0;
}
