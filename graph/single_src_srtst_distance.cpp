#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
int vis[1005];
int level[1005];

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

    // cout << par << " ";
    for (int child : adj_list[par])
    {
      if (!vis[child])
      {
        q.push(child);
        vis[child] = true;
        level[child] = level[par] + 1;
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

  int src, dest;
  cin >> src >> dest;
  bfs(src);

  // if (vis[dest])
  //   cout << "YES\n";
  // else
  //   cout << "NO\n";
  // for (int i = 0; i < n; i++)
  // {
  //   cout << i << " => " << level[i] << endl;
  // }

  cout << level[dest] << endl;

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

// 4