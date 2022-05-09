/**
 * @file find_bridge.cpp
 * @author your name (you@domain.com)
 * @brief Finding bridges in an undirected graph in O(N+M),
 * Note that this implementation malfunctions if the graph has multiple edges, since it ignores them.
 * @version 0.1
 * @date 2022-04-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;

int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void IS_BRIDGE(int a, int b)
{
    cout << a << "-" << b << " is a bridge" << endl;
}

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    return 0;
}