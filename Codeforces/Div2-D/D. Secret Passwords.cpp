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
const int MAX_IN = 1e5 + 5;
struct DSU
{
	vector<int>par;
	vector<int>rank;
	DSU()
	{
		par = vector<int>(30);
		rank = vector<int>(30);
		for (int i = 0; i < 30; ++i)
			par[i] = i;
	}

	int find(int x)
	{
		if (x == par[x])
			return x;
		return par[x] = find(par[x]);
	}

	bool merge(int x, int y)
	{
		int a = find(x);
		int b = find(y);
		if (x != y)
		{
			if (rank[b] > rank[a])
				swap(a, b);
			par[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
		return x != y;
	}
};
int main()
{
	A_M_S();
	DSU dsu;
	vector<bool>vis(30);
	int T = 1;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		vis[s[0]-'a'] = true;
		for (int i = 1; i < sz(s); ++i)
		{
			int x = s[i - 1] - 'a';
			vis[s[i] - 'a'] = true;
			dsu.merge(x, s[i] - 'a');
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (dsu.find(i) == i && vis[i])
			++cnt;
	}
	cout << cnt << endl;
	return 0;
}
