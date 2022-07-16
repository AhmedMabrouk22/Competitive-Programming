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
vector<string>grid;
vector<vector<int>>dist;
int n, m;
bool valid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}
void bfs()
{
	queue<pair<int, int>>q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == '1')
			{
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int>cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (valid(x, y) && dist[x][y] == -1)
			{
				dist[x][y] = dist[cur.first][cur.second] + 1; 
				q.push({ x, y });
			}
		}
	}

}
int main()
{
	A_M_S();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		grid.clear();
		dist = vector<vector<int>>(n, vector<int>(m, -1));
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			grid.push_back(s);
		}

		bfs();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << dist[i][j] << " ";
			cout << endl;
		}

	}
	
	return 0;
}
