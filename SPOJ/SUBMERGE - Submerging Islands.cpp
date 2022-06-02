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
vector<int>low_link, n_dfs;
set<int>st;
int id;
bool root;
void tarjan(int n,int par)
{
	low_link[n] = n_dfs[n] = id++;


	for (auto child : graph[n])
	{
		if (n_dfs[child] == -1)
		{
			tarjan(child, n);
			low_link[n] = min(low_link[n], low_link[child]);

			if (low_link[child] >= n_dfs[n] && par != -1)
			{
				if (!n_dfs[n] && !root)
					root = true;
				else
					st.insert(n);
			}

		}
		else if (child != par)
			low_link[n] = min(low_link[n], n_dfs[child]);
	}

	

}

int main()
{
	A_M_S();
	
	int t;
	int n, m;
	while (cin >> n >> m && n !=0)
	{

		graph = vector<vector<int>>(n + 1);
		low_link = vector<int>(n + 1);
		n_dfs = vector<int>(n + 1, -1);
		st.clear();
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (n_dfs[i] == -1)
				tarjan(i, -1);
		}

		cout << sz(st) << endl;
	}

	return 0;
}
