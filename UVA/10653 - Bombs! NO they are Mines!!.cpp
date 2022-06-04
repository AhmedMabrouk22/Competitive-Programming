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

int n, m;
vector<vector<bool>>grid;
vector<vector<int>>len;
bool vlaid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m && !grid[r][c];
}
int s1, s2, d1, d2;
int bfs()
{

	queue<pair<int, int>>q;
	q.push({ s1, s2 });
	len[s1][s2] = 0;
	while (!q.empty())
	{
		pair<int, int>cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
		
			if (vlaid(x, y) && !grid[x][y])
			{
				len[x][y] = len[cur.first][cur.second] + 1;
				q.push({ x, y });
				grid[x][y] = 1;
				if (x == d1&&y == d2)
					return len[x][y];

			}
		}

	}
	return len[d1][d2];
}

int main()
{
	A_M_S();
	while (cin >> n >> m && n != 0 && m != 0)
	{
		grid = vector<vector<bool>>(n, vector<bool>(m));
		len = vector<vector<int>>(n, vector<int>(m));
		int t;
		cin >> t;

		while (t--)
		{
			int row, q;
			cin >> row >> q;
			while (q--)
			{
				int col;
				cin >> col;
				grid[row][col] = 1;
			}
		}
		cin >> s1 >> s2 >> d1 >> d2;
		cout << bfs() << endl;
	}
	return 0;
}
