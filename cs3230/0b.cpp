#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 2e18;
const int MOD = 10000007;

int n, m, a, b, dd;
vector<ii> adj[200001];
vector<pair<ll, int>> dns;
ll d1[200001], dn[200001];
ll ans;

bool cmp(ii a, ii b) { return a.first < b.first; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  while (m--) {
    cin >> a >> b >> dd;
    adj[a].push_back(make_pair(b, dd));
    adj[b].push_back(make_pair(a, dd));
  }
  for (int i = 1; i <= n; i++) {
    // sort adj list
    sort(adj[i].begin(), adj[i].end());
    // for (auto p = adj[i].begin(); p < adj[i].end(); p++)
    //   // printf("(%d,%d) ", p->first, p->second);
    // cout << endl;
    d1[i] = INF;
    dn[i] = INF;
  }
  d1[1] = 0;
  dn[n] = 0;

  // dijkstra from 1
  priority_queue<ii> pq;
  pq.push(make_pair(-d1[1], 1));
  while (!pq.empty()) {
    ii curr = pq.top();
    pq.pop();
    if (-curr.first > d1[curr.second])
      continue;
    for (ii fren : adj[curr.second]) {
      ll frendist = -curr.first + fren.second;
      if (frendist > d1[fren.first])
        continue;
      d1[fren.first] = frendist;
      pq.push(make_pair(-frendist, fren.first));
    }
  }

  // dijkstra from n
  pq.push(make_pair(-dn[n], n));
  while (!pq.empty()) {
    ii curr = pq.top();
    pq.pop();
    if (-curr.first > dn[curr.second])
      continue;
    for (ii fren : adj[curr.second]) {
      ll frendist = -curr.first + fren.second;
      if (frendist > dn[fren.first])
        continue;
      dn[fren.first] = frendist;
      pq.push(make_pair(-frendist, fren.first));
    }
  }

  // dns is a vector of pairs in the form of (dist, node)
  for (int i = 1; i <= n; i++) {
    dns.push_back(make_pair(dn[i], i));
  }
  sort(dns.begin(), dns.end());

  // form sorted_dn_nodes array with values as node num
  // form sorted_dn_dists array with values as dist from n (sorted)
  // (later) form cum_dist array where cum_dist[i] is the
  //   sum of d(sorted_dn[i], n) i=0...i
  int sorted_dn_nodes[200001];
  ll sorted_dn_dists[200001];
  for (int i = 0; i < n; i++) {
    // cout << dns[i].first << " " << dns[i].second << endl;
    sorted_dn_nodes[i + 1] = dns[i].second;
    sorted_dn_dists[i + 1] = dns[i].first;
  }

  // for every node from 1 to n,
  // binary search for suitable bs
  // then get the sum of all
  // minus (d-dsa-dbt-1) for each b where edge(a, b)
  for (int i = 1; i <= n; i++) {
    ll dsa = d1[i];
    // printf("looking for dist < %d\n", d1[n] - dsa);
    auto j =
        lower_bound(sorted_dn_dists + 1, sorted_dn_dists + n + 1, d1[n] - dsa) -
        1;
    for (int k = j - sorted_dn_dists; k >= 1; k--) {
      b = sorted_dn_nodes[k];
      ll dbt = sorted_dn_dists[k];
      ll d = d1[n];
      // printf("found dist[k]=%d, dist[k-1]=%d, dist[k+1]=%d\n", dbt,
      //        sorted_dn_dists[k - 1], sorted_dn_dists[k + 1]);
      int num_edges = (d - dsa - dbt - 1);
      auto lb = lower_bound(adj[i].begin(), adj[i].end(), make_pair(b, 0), cmp);
      // printf("search for lower bound of %d in adj[%d], got (%d, %d)\n", b, i,
      //        lb->first, lb->second);
      bool has_edge = lb->first == b;
      // printf("connecting node %d with node %d, found %d edges, has edge?
      // %s\n",
      //        i, b, num_edges, has_edge ? "true" : "false");
      if (!has_edge && num_edges > 0) {
        ans += num_edges;
        ans %= MOD;
        // printf("adding %d edges, current ans %d\n", num_edges, ans);
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
