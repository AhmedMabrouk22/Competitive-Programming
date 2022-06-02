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

vector<vector<int>>graph, comp;
vector<int>low_link, n_dfs, id_comp;
vector<bool>in_stack;
stack<int>st;
int id;

void tarjan(int n)
{
	low_link[n] = n_dfs[n] = id++;
	in_stack[n] = 1;
	st.push(n);
	for (auto child : graph[n])
	{
		if (n_dfs[child] == -1)
		{
			tarjan(child);
			low_link[n] = min(low_link[n], low_link[child]);
		}
		else if (in_stack[child])
			low_link[n] = min(low_link[n], low_link[child]);
	}

	if (low_link[n] == n_dfs[n])
	{
		comp.push_back(vector<int>());
		int x = -1;
		while (x != n)
		{
			x = st.top();
			st.pop();
			in_stack[x] = 0;
			comp.back().push_back(x);
			id_comp[x] = sz(comp) - 1;
		}
	}
}

int main()
{
	A_M_S();
	
	int n, m;
	cin >> n >> m;
	graph = vector<vector<int>>(n + 1);
	low_link = vector<int>(n + 1);
	n_dfs = vector<int>(n + 1, -1);
	id_comp = vector<int>(n + 1);
	in_stack = vector<bool>(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (n_dfs[i] == -1)
			tarjan(i);
	}
	
	
	vector<int>out_deg(sz(comp));
	for (int i = 1; i <= n; ++i)
	{
		for (auto child : graph[i])
		{
			if (id_comp[i] != id_comp[child])
				++out_deg[id_comp[i]];
		}
	}

	int out = 0, id = 0;
	for (int i = 0; i < sz(out_deg); ++i)
	{
		if (!out_deg[i])
		{
			
			++out;
			id = i;
		}
	}

	if (out > 1)
		cout << 0 << endl;
	else
	{
		sort(all(comp[id]));
		cout << sz(comp[id]) << endl;
		for (auto i : comp[id])
			cout << i << " ";
		cout << endl;
	}

	return 0;
}
