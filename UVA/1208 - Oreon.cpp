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

struct edge
{
	int from, to, w;
	edge(int from, int to, int w) :from(from), to(to), w(w)
	{}
	bool operator < (const edge &e) const
	{
		return w>e.w;
	}
};

vector<vector<edge>>graph;
int n;
vector<edge>prim()
{
	vector<bool>vis(n);
	priority_queue<edge>pq;
	vector<edge>edges;
	pq.push(edge(-1, 0, 0));
	while (!pq.empty())
	{
		edge e = pq.top();
		pq.pop();
		if (vis[e.to])
			continue;
		vis[e.to] = 1;
		if (e.to)
			edges.push_back(e);
		for (auto child : graph[e.to])
		{
			if (!vis[child.to])
				pq.push(child);
		}
	}
	return edges;
}

void solve()
{
	cin >> n;
	graph = vector<vector<edge>>(n + 1);
	int a;
	char x;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			cin >> a >> x;
			if (a)
				graph[i].push_back(edge(i, j, a));
		}
		cin >> a;
		if (a)
			graph[i].push_back(edge(i, n-1, a));
	}
	vector<edge>res = prim();
	sort(allr(res));
	for (auto i : res)
		cout << char(min(i.from, i.to) + 'A') << '-' << char(max(i.from, i.to) + 'A') << " " << i.w << endl;
}

int main()
{
	A_M_S();
	int t;
	cin >> t;
	int cnt = 1;
	while (t--)
	{
		cout << "Case " << cnt++ << ":" << endl;
		solve();
	}


	return 0;
}
