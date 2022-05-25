// problem link: https://codeforces.com/problemset/problem/999/E

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

vector<vector<int>>graph;
vector<bool>reachable;

void dfs(int i)
{
	reachable[i] = true;
	for (auto child : graph[i])
	{
		if (!reachable[child])
			dfs(child);
	}
}

int main()
{
	A_M_S();
	int n, m, s;
	cin >> n >> m >> s;
	graph = vector<vector<int>>(n + 1);
	reachable = vector<bool>(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	dfs(s);
	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		if (!reachable[i])
		{
			dfs(i);
			v.push_back(i);
		}
	}

	reachable = vector<bool>(n + 1);
	reverse(all(v));
	for (auto i : v)
	{
		if (!reachable[i])
		{
			dfs(i);
			++cnt;
		}
	}


	cout << cnt << endl;
	return 0;

	/*
	
	9 6 1
	1 2
	2 3
	1 5
	1 7
	9 8
	8 1
	
	*/
}
