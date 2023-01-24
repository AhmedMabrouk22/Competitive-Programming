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
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

ll gcd(ll a, ll b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
const int MAX_IN = 1e5 + 5;
vector<vector<int>>graph;
vector<int>color;
bool ok = true;
void bfs(int u,int c)
{
	queue<int>q;
	q.push(u);
	color[u] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto child : graph[cur])
		{
			if (color[child] == -1)
			{
				color[child] = 1 - color[cur];
				q.push(child);
			}

			if (color[child] == color[cur])
			{
				ok = false;
				return;
			}

		}
	}

}

int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		graph = vector<vector<int>>(n + 1);
		vector<bool>edges(n + 1);
		color = vector<int>(n + 1, -1);
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			edges[a] = edges[b] = 1;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (edges[i] && color[i] == -1)
				bfs(i, 1);
		}

		if (!ok)
			rt(-1);

		vector<int>r1, r2;
		for (int i = 1; i <= n; ++i)
		{
			if (color[i] != -1)
			{
				if (color[i])
					r1.push_back(i);
				else
					r2.push_back(i);
			}
		}

		cout << sz(r1) << endl;
		for (auto i : r1)
			cout << i << " ";
		cout << endl;
		cout << sz(r2) << endl;
		for (auto i : r2)
			cout << i << " ";

	}
	return 0;
}
