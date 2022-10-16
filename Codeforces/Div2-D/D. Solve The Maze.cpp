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
int n, m;
bool valid(int i, int j)
{
	return i > 0 && i <= n && j > 0 && j <= m;
}
int main()
{
	A_M_S();
	int T = 1;
	cin >> T;
	while (T--)
	{
		char arr[55][55];
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				cin >> arr[i][j];
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (arr[i][j] == 'B')
				{
					for (int k = 0; k < 4; ++k)
					{
						int x = i + dx[k];
						int y = j + dy[k];

						//cout << x << " " << y << endl;

						if (valid(x, y) && arr[x][y] == '.')
							arr[x][y] = '#';
					}
				}
			}
		}

		/*
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				cout << arr[i][j];
			cout << endl;
		}
		*/

		queue<pair<int, int>>q;
		bool vis[55][55] = { 0 };
		if (arr[n][m] == '.')
		{
			q.push({ n, m });
			vis[n][m] = true;
		}

		while (!q.empty())
		{
			pair<int, int>cur = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (valid(x, y) && !vis[x][y] && arr[x][y] != '#')
				{
					q.push({ x, y });
					vis[x][y] = true;
				}
			}
		}

		bool good = true;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if ((arr[i][j] == 'G' && !vis[i][j]) || (arr[i][j] == 'B' && vis[i][j]))
					good = false;
			}
		}

		cout << (good ? "Yes" : "NO") << endl;


	}
	return 0;
}
