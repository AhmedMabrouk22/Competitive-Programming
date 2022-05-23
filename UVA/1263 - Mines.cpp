// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3704

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
using namespace std;

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
vector<bool> vis;
vector<vector<int>>graph;
int x[2005], y[2005], d[2005];
int n;

void build_graph()
{

	for (int f = 0; f < n; ++f)
	{
		pair<int, int> l = { x[f] - (d[f] / 2), x[f] + (d[f] / 2) };
		pair<int, int> w = { y[f] - (d[f] / 2), y[f] + (d[f] / 2) };
		for (int i = 0; i < n; ++i)
		{
			if (i != f)
			{

				if (x[i] >= l.first && x[i] <= l.second && y[i] >= w.first && y[i] <= w.second)
					graph[f].push_back(i);

			}
		}
	}

}

void dfs(int i)
{
	vis[i] = true;
	for (auto child : graph[i])
	{
		if (!vis[child])
			dfs(child);
	}
}

int main()
{
	A_M_S();
	
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		graph = vector<vector<int>>(n + 1);
		vis = vector<bool>(n + 1);
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i] >> d[i];

		build_graph();
		vector<int> v1;
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				dfs(i);
				v1.push_back(i);
			}
		}

		int c = 0;
		vis = vector<bool>(n + 1);
		reverse(all(v1));
		for (auto i : v1)
		{
			if (!vis[i])
			{
				dfs(i);
				++c;
			}
		}

		cout << c << endl;
	}

	return 0;
}
