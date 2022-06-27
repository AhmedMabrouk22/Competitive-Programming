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
		parent = vector<int>(n);
		rank = vector<int>(n);
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
	{
	}
	bool operator < (const edge& e) const
	{
		return w > e.w;
	}
};
int n;
vector<edge>list_edge;
ll kruskal()
{
	ll min_cost = 0;
	priority_queue<edge>pq;
	DSU dsu(n);
	for (int i = 0; i < sz(list_edge); ++i)
		pq.push(list_edge[i]);
	while (!pq.empty())
	{
		edge e = pq.top();
		pq.pop();
		if (dsu.union_sets(e.from, e.to))
			min_cost += e.w;
		
	}
	return min_cost;
}

int cal(string s1, string s2)
{
	int w = 0;
	for (int i = 0; i < 4; ++i)
	{
		int a = s1[i] - '0';
		int b = s2[i] - '0';
		w += min(abs(b - a), 10 - abs(a - b));
	}
	return w;
}

void solve()
{
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	list_edge.clear();
	int res = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		res = min(res, cal("0000", v[i]));
		for (int j = i + 1; j < n; ++j)
			list_edge.push_back(edge(i, j, cal(v[i], v[j])));
	}
	cout << res + kruskal() << endl;
}
int main()
{
	A_M_S();


	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
