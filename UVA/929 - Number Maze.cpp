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

ll grid[1000][1000];
vector<vector<bool>>vis;
vector<vector<ll>>dist;
int n, m;

bool valid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

int dijkstra()
{
	
	priority_queue <pair<ll, pair<int, int>>, vector < pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>>q;
	q.push({ 0, { 0, 0 } });
	dist[0][0] = grid[0][0];

	while (!q.empty())
	{
		pair<ll, pair<int, int>>cur = q.top();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = cur.second.first + dx[i];
			int y = cur.second.second + dy[i];

			if (!valid(x, y) || cur.first > dist[x][y])
				continue;

			if (dist[x][y] > dist[cur.second.first][cur.second.second] + grid[x][y])
			{
				dist[x][y] = grid[x][y] = dist[cur.second.first][cur.second.second] + grid[x][y];
				q.push({ grid[x][y], { x, y } });
			}

		}
	}
	return dist[n - 1][m - 1];
}

int main()
{
	A_M_S();
	
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		dist = vector<vector<ll>>(n, vector<ll>(m, OO));
		vis = vector<vector<bool>>(n, vector<bool>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cin >> grid[i][j];
		}

		cout << dijkstra() << endl;

	}

	return 0;
}
