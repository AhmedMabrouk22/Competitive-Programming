// problem link: https://codeforces.com/problemset/problem/1095/D
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

map<int, set<int>>graph;
vector<int> res;
vector<bool>vis;
void dfs(int i = 1)
{
	vis[i] = true;
	res.push_back(i);
	for (auto child : graph[i])
	{
		if (!vis[child])
			dfs(child);
	}
}


int main()
{
	A_M_S();
	int n;
	cin >> n;
	vector<pair<int, int>> v(n+1);
	vis = vector<bool>(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a, b };
	}

	for (int i = 1; i <= n; ++i)
	{
		int a = v[i].first;
		int b = v[i].second;
		bool f = false;

		if (v[a].first == b || v[a].second == b)
			f = true;

		if (f)
		{
			graph[i].insert(a);
			graph[a].insert(b);
		}
		else
		{
			graph[b].insert(a);
			graph[i].insert(b);
		}

	}

	dfs();
	for (auto i : res)
		cout << i << " ";

	return 0;
}
