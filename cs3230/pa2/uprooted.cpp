#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
auto hash = [](ii &a) { return 200001 * a.first + a.second; };
auto equals = [](ii &a, ii &b) {
  return a.first == b.first && a.second == b.second;
};
int n, m, s, a, b, c, p;
unordered_map<int, int> adj[200001];
unordered_set<int> tree[200001];
// unordered_map<ii, int, decltype(hash), decltype(equals)> edge;
map<ii, int> edge;
bool taken[200001];

unordered_map<int, int> votes[200001];
// comp[u] = the component number of u in tree
int comp[200001];

// return true if connecting node1, node2 (guaranteed to have an edge in adj)
// will cause a cycle in tree
bool causesCycle(int node1, int node2) {
  // set everything to unvisited
  for (int i = 1; i <= n; i++) {
    comp[i] = -1;
  }
  int count = 0;
  queue<int> toVisit;
  // for each node, visit its friends
  for (int i = 1; i <= n; i++) {
    if (comp[i] != -1) {
      continue;
    }
    toVisit.push(i);
    while (!toVisit.empty()) {
      int u = toVisit.front();
      toVisit.pop();
      if (comp[u] == -1) { // visit
        comp[u] = count;
        for (int fri : tree[u]) {
          if (comp[fri] == -1) { // not yet visited
            toVisit.push(fri);
          }
        }
      }
    }
    // finished a component.
    count++;
  }
  return comp[node1] == comp[node2];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m >> s;
//  printf("n:%d m:%d s:%d\n",n,m,s);
  // load the graph
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    adj[a].insert(ii(b, c));
    adj[b].insert(ii(a, c));
    edge[ii(a, b)] = i;
  }

  // all nodes are not in the tree by default
  for (int i = 1; i <= n; i++)
    taken[i] = false;
  // node 1 must be in the tree.
  taken[1] = true;


  vector<int> goFrom[200001];
  // for the ith permutation
  for (int i = 0; i < s; i++) {
    // goFrom[v] stores all u such that u->v, AND u already in the growth
    // sequence in other words, goFrom[v] stores all safe edges to v
    // growth sequence cfm start from 1
    /*for (auto fri : adj[1]) {
      goFrom[fri.first].push_back(1);
    }*/
    unordered_set<int> intree;
    intree.insert(1);
    // each permutation entry
    for (int j = 0; j < n - 1; j++) {
      cin >> p;
      int edges = 0;
      int bestedge = 0;
      int bestedgeweight = 0;
      vector<int> toprune;
      for (auto edge : adj[p]) {
        if(intree.count(edge.first) == 1) {
          edges++;
          votes[p][edge.first]++;
          //votes[edge.first][p]++;
          if(votes[p][edge.first] != i+1) {
            toprune.emplace_back(edge.first);
          }
          if(i == s-1 && votes[p][edge.first] == s) {
            if(bestedgeweight < edge.second) {
              bestedge = edge.first;
              bestedgeweight = edge.second;
            }
          }
        } else {
          toprune.emplace_back(edge.first);
        }
      }
      for(auto i : toprune) {
        adj[p].erase(i);
        //adj[i].erase(p);
      }
      if(edges == 0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
      }
      if(i == s-1) {
        if(bestedge == 0) {
          cout<<"IMPOSSIBLE\n";
          return 0;
        }
        tree[p].insert(bestedge);
        tree[bestedge].insert(p);
      }
      intree.insert(p);
      continue;
      // the growth sequence is invalid
      if (goFrom[p].empty()) {
        cout << "IMPOSSIBLE 1\n";
        return 0;
      }
      // the growth sequence result in a cfmed edge
      if (goFrom[p].size() == 1) {
        int u = goFrom[p][0];
        // if both nodes are taken, then either p->u has an edge already or not.
        bool bothTaken = taken[p] == taken[u] && taken[p];
        // if both taken and p->u is not an edge, we check if it causes a cycle.
        if (bothTaken && !tree[p].count(u) && causesCycle(p, u)) {
          cout << "IMPOSSIBLE 2\n";
          return 0;
        }
        // add to confirmed tree (not the growth sequence tree)
        taken[p] = true;
        taken[u] = true;
        tree[p].insert(u);
        tree[u].insert(p);
      } // else there are multiple choices thus we don't choose
      // now p is in the growth sequence. future nodes can build from p
      for (auto fri : adj[p]) {
        goFrom[fri.first].push_back(p);
      }
    }
  }

  set<int> treeEdgeSet;
  for (int i = 1; i <= n; i++) {
    for (int j: tree[i]) {
      ii e = ii(i, j);
      int edgeNum = edge[e];
      if (edgeNum!=0) {
        treeEdgeSet.insert(edgeNum);
      }
    }
  }
  cout << treeEdgeSet.size() << endl;
  for (int edge : treeEdgeSet) {
    cout << edge << ' ';
  }
  cout << endl;
}
