#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
int vis[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;
  level[src] = 0;

  while (!q.empty())
  {
    int par = q.front();
    q.pop();

    for (int child : adj_list[par])
    {
      if (!vis[child])
      {
        q.push(child);
        vis[child] = true;
        level[child] = level[par] + 1;
        parent[child] = par;
      }
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;

  while (e--)
  {
    int a, b;
    cin >> a >> b;

    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  memset(vis, false, sizeof(vis));
  memset(level, -1, sizeof(level));
  memset(parent, -1, sizeof(parent));

  int src, dest;
  cin >> src >> dest;
  bfs(src);

  vector<int> path;
  int node = dest;

  while (node != -1)
  {
    path.push_back(node);
    node = parent[node];
  }
  reverse(path.begin(), path.end());
  for (int x : path)
  {
    cout << x << " ";
  }

  return 0;
}

// 7 7
// 0 1
// 1 3
// 3 2
// 1 4
// 3 5
// 2 5
// 5 6
// 0
// 6