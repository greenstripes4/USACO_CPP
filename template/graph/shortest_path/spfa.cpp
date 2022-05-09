#include <bits/stdc++.h>
using namespace std;

/*
SPFA is a improvement of the Bellman-Ford algorithm 
which takes advantage of the fact that not all attempts at relaxation will work. 
The main idea is to create a queue containing only the vertices
that were relaxed but that still could further relax their neighbors. 
And whenever you can relax some neighbor, you should put him in the queue. 
This algorithm can also be used to detect negative cycles as the Bellman-Ford.
*/
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int> &d)
{
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                if (!inqueue[to])
                {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false; // negative cycle
                }
            }
        }
    }
    return true;
}