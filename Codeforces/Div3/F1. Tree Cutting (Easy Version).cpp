// problem link: https://codeforces.com/problemset/problem/1118/F1

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

const int MAX = 3e5 + 5;
vector<vector<int>>tree;
int color[MAX];
vector<bool>vis;
int res, red, blue;

pair<int, int>dfs(int i)
{
	vis[i] = true;
	int r = (color[i] == 1);
	int b = (color[i] == 2);

	for (auto child : tree[i])
	{
		if (!vis[child])
		{
			pair<int, int>sub = dfs(child);
			if ((sub.first == red && !sub.second) ||
				(sub.second == blue && !sub.first))
				++res;
			r += sub.first;
			b += sub.second;
		}
	}
	return{ r, b };
}

int main()
{
	A_M_S();

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> color[i];
		if (color[i] == 1)
			++red;
		else if (color[i] == 2)
			++blue;
	}

	tree = vector<vector<int>>(n + 1);
	vis = vector<bool>(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	cout << res << endl;
	

	return 0;
}
