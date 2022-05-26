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

int main()
{
	A_M_S();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>>v(n, vector<int>(m));
		vector<vector<int>>d(n, vector<int>(m));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> v[i][j];
				d[i][j] = v[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
			sort(all(d[i]));

		vector<int>pos;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (d[i][j] != v[i][j])
					pos.push_back(j);
			}
			if (sz(pos))
			{
				c1 = pos[0];
				c2 = pos[1];
				break;
			}
		}

		if (sz(pos) > 2)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < n; ++i)
				swap(v[i][c1], v[i][c2]);

			bool ok = true;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (d[i][j] != v[i][j])
					{
						ok = false;
						break;
					}
				}
				if (!ok)
					break;
			}

			if (!ok)
				cout << -1 << endl;
			else
				cout << c1 + 1 << " " << c2 + 1 << endl;

		}

	}

	return 0;
}
