#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define Ceil(x,y) ((x+y-1)/y)
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define rt(s) return cout<<s,0
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define sz(s)	(int)(s.size())
#define full(v,n) for (int i = 0 ; i < n ; ++i) cin >> v[i]
#define full1(v,n) for (int i = 1 ; i <= n ; ++i) cin >> v[i]
#define OO 0x3f3f3f3f3f3f3f3fLL
using namespace std;
const int oo = 0x3f3f3f3f;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void A_M_S()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };

ll gcd(ll a, ll b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct DSU
{
	vector<int>parent, rank;
	int forestes;
	DSU(int n)
	{
		parent = vector<int>(n + 5);
		rank = vector<int>(n + 5);
		forestes = n;
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find_set(int v)
	{
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	bool union_sets(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if (a != b)
		{
			if (rank[b] > rank[a])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
			--forestes;
		}
		return a != b;
	}
};

struct edge
{
	int from, to, w;
	edge(int from, int to, int w) : from(from), to(to), w(w)
	{}

	bool operator < (const edge &e) const
	{
		return w > e.w;
	}

};

vector<edge>list_edges;
int n, m;
pair<ll, vector<edge>>kruskal()
{
	DSU dsu(n);
	int min_cost = 0;
	priority_queue<edge>pq;
	vector<edge>res;
	for (int i = 0; i < sz(list_edges); ++i)
		pq.push(list_edges[i]);

	while (!pq.empty())
	{
		edge e = pq.top();
		pq.pop();
		if (dsu.union_sets(e.from, e.to))
		{
			res.push_back(e);
			min_cost += e.w;
		}
	}
	if (dsu.forestes == 1)
		return{ min_cost, res };
	return{ -1, res };
}

int main()
{
	A_M_S();
	while (cin >> n >> m && n != 0)
	{
		list_edges.clear();
		for (int i = 0; i < m; ++i)
		{
			int from, to, w;
			cin >> from >> to >> w;
			edge e(from, to, w);
			list_edges.push_back(e);
		}

		pair < ll, vector<edge>>res = kruskal();
		if (res.first == -1)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			int mx = 0;
			for (auto i : res.second)
				mx = max(i.w, mx);
			cout << mx << endl;
		}
	}
	return 0;
}
