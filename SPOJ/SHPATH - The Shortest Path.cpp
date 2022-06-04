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
map<string, int>citys;
vector<vector<pair<int, int>>>graph;
int n;
int dijkstra(int s, int d)
{
	vector<ll>dist(n + 1, oo);
	priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0, s });
	dist[s] = 0;

	while (!q.empty())
	{
		pair<int, int> cur = q.top();
		q.pop();

		if (cur.first > dist[cur.second])
			continue;

		for (auto child : graph[cur.second])
		{
			if (dist[child.second] > dist[cur.second] + child.first)
			{
				dist[child.second] = child.first = dist[cur.second] + child.first;
				q.push(child);
			}
		}
	}
	return dist[d];
}

int main()
{
	A_M_S();

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		graph = vector<vector<pair<int, int>>>(n + 1);
		citys.clear();
		for (int i = 1; i <= n; ++i)
		{
			string city;
			cin >> city;
			citys[city] = i;
			int p;
			cin >> p;
			for (int x = 0; x < p; ++x)
			{
				int to, cost;
				cin >> to >> cost;
				graph[i].push_back({ cost, to });
			}
		}

		int r;
		cin >> r;
		for (int i = 0; i < r; ++i)
		{
			string c1, c2;
			cin >> c1 >> c2;
			cout << dijkstra(citys[c1], citys[c2]) << endl;
		}

	}

	return 0;
}
