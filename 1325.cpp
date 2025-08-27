#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> dist;

int bfs(int s)
{
    queue<int> q;
    dist.assign(n + 1, -1);
    dist[s] = 0;
    q.push(s);

    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : adj[u])
        {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
            ++cnt;               
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    dist.assign(n + 1, -1);

    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }

    vector<int> reach(n + 1, 0);
    int best = 0;
    for (int i = 1; i <= n; ++i)
    {
        reach[i] = bfs(i);
        if (reach[i] > best) best = reach[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (reach[i] == best) cout << i << ' ';
    }

    return 0;
}