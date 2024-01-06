#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <set>
using namespace std;
typedef long long ll;
const int INF = 1e9;
vector<vector<int>>gr;
const int heavy_bound = 550;
vector<int>deg;

inline bool comp(int a, int b) {
	return deg[a] < deg[b] || (deg[a] == deg[b] && a < b);
}
int main()
{
	int n, m;
	cin >> n >> m;
	gr.resize(n);
	deg.resize(n);
	//vector<bool>is_heavy(n);
	vector<int>nodes(n);
	iota(nodes.begin(), nodes.end(), 0);
	vector<pair<int, int>>edges;
	for (int i = 0;i < m;i++) {
		int v, u;
		cin >> v >> u;
		v--;u--;
		edges.push_back({ v, u });
		deg[v]++;
		deg[u]++;
	}
	sort(nodes.begin(), nodes.end(), comp);
	for (auto& e:edges) {
		int v = e.first;
		int u = e.second;
		if (deg[v] < deg[u] || (deg[v] == deg[u] && v < u)) {
			gr[v].push_back(u);
		}
		else {
			gr[u].push_back(v);
		}
	}
	//for (int i = 0;i < n;i++) {
	//	if (deg[i] >= heavy_bound) {
	//		is_heavy[i] = true;
	//	}
	//}
	vector<bool>used(n);
	int ans = 0;
	vector<int>cur;
	for (int v : nodes)
	{
		cur.clear();
		for (int u : gr[v]) {
			used[u] = true;
			cur.push_back(u);
		}
		for (int node : cur) {
			for (int u : gr[node]) {
				if (used[u]) {
					ans++;
				}
			}
		}
		for (int node : cur){
			used[node] = false;
		}
	}
	cout << ans << '\n';
}
