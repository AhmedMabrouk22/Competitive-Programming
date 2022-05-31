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

vector<vector<int>>graph, com;
vector<int>lowLink, n_dfs;
vector<bool>inStack;
stack<int>st;
int dfs;
void tarjan(int n)
{
	lowLink[n] = n_dfs[n] = dfs++;
	inStack[n] = 1;
	st.push(n);
	for (auto child : graph[n])
	{
		if (n_dfs[child] == -1)
		{
			tarjan(child);
			lowLink[n] = min(lowLink[n], lowLink[child]);
		}
		else if (inStack[child])
			lowLink[n] = min(lowLink[n], lowLink[child]);
	}

	
	if (lowLink[n] == n_dfs[n])
	{
		int x = -1;
		com.push_back(vector<int>());
		while (x != n)
		{
			x = st.top();
			st.pop();
			inStack[x] = 0;
			com.back().push_back(x);
		}
	}

}

int main()
{
	A_M_S();

	int n, m;
	while (cin >> n >> m && n != 0)
	{
		com.clear();
		graph = vector<vector<int>>(n + 1);
		lowLink = vector<int>(n + 1);
		n_dfs = vector<int>(n + 1, -1);
		inStack = vector<bool>(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(b);
			if (c == 2)
				graph[b].push_back(a);
		}


		tarjan(1);
		bool ok = true;
		for (auto i : com)
		{
			if (i.size() != n)
			{
				ok = false;
				break;
			}
		}
		cout << (ok ? 1 : 0) << endl;
	}
	return 0;
}
