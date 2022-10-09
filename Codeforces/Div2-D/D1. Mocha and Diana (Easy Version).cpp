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
	vector<int> par, rank;
	DSU(int n)
	{
		par = vector<int>(n + 1);
		rank = vector<int>(n + 1);
		for (int i = 1; i <= n; ++i)
			par[i] = i;
	}

	int find(int x)
	{
		if (x == par[x])
			return x;
		return par[x] = find(par[x]);
	}

	bool meage(int x, int y)
	{
		int a = find(x);
		int b = find(y);

		if (a != b)
		{
			if (rank[a] > rank[b])
				swap(a, b);

			par[a] = b;
			if (rank[a] == rank[b])
				++rank[b];
		}
		return a != b;
	}
};

int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (T--)
	{
		int n, m1, m2;
		cin >> n >> m1 >> m2;
		DSU d1(n), d2(n);

		for (int i = 0; i < m1; ++i)
		{
			int x, y;
			cin >> x >> y;
			d1.meage(x, y);
		}

		for (int i = 0; i < m2; ++i)
		{
			int x, y;
			cin >> x >> y;
			d2.meage(x, y);
		}


		vector<pair<int, int>>res;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (d1.find(i) == d1.find(j) || d2.find(i) == d2.find(j))
					continue;
				res.push_back({ i, j });
				d1.meage(i, j);
				d2.meage(i, j);
			}
		}

		cout << sz(res) << endl;
		for (auto i : res)
			cout << i.first << " " << i.second << endl;

	}
	return 0;
}
