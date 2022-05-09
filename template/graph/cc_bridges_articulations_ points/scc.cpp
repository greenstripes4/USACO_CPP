/**
 * @file scc.cpp
 * @author your name (you@domain.com)
 * @brief Find SCC in directed graph
 * @version 0.1
 * @date 2022-04-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v)
{
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main()
{
    int n;
    // ... read n ...

    for (;;)
    {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    // 1. Handle SCC directly
    for (auto v : order)
        if (!used[v])
        {
            dfs2(v);

            // ... processing next component ...

            component.clear();
        }

    // 2. To generate the Condensation Graph
    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n);
    for (auto v : order)
        if (!used[v])
        {
            dfs2(v);

            int root = component.front();
            for (auto u : component)
                roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }

    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
        {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                adj_scc[root_v].push_back(root_u);
        }
}