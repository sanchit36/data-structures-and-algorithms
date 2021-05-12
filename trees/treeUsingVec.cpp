#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &tree, int s)
{
  cout << s << " ";
  for (int i = 0; i < tree[s].size(); i++)
  {
    dfs(tree, tree[s][i]);
  }
}

void bfs(vector<vector<int>> &tree, int s)
{
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    cout << front << " ";

    for (int i = 0; i < tree[front].size(); i++)
    {
      q.push(tree[front][i]);
    }
  }
}

int main()
{
  int nodes, u, v;
  cin >> nodes;
  vector<vector<int>> tree(nodes + 1);

  while (--nodes)
  {
    cin >> u >> v;
    tree[u].push_back(v);
  }

  dfs(tree, 1);
  cout << endl;

  bfs(tree, 1);
  cout << endl;

  return 0;
}