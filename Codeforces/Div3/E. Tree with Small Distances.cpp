// problem link: https://codeforces.com/problemset/problem/1029/E

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
int n;
vector<vector<int>>tree;
vector<int>len, par;
void bfs()
{
	
	queue<int> q;
	q.push(1);
	len[1] = 0;

	int cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		for (auto child : tree[cur])
		{
			if (len[child] == -1)
			{
				q.push(child);
				len[child] = len[cur] + 1;
				par[child] = cur;
			}
		}

	}
}

int main()
{
	A_M_S();
	cin >> n;
	tree = vector<vector<int>>(n + 1);
	len = vector<int>(n + 1, -1);
	par = vector<int>(n + 1, -1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs();

	int cnt = 0;
	set<pair<int, int>>st;
	for (int i = 1; i <= n; ++i)
	{
		if (len[i] > 2)
			st.insert({ -len[i], i });
	}

	while (!st.empty())
	{

		int node = st.begin()->second;
		int parent = par[node];
		++cnt;
		

		for (auto child : tree[parent])
		{
			auto it = st.find({ -len[child], child });
			if (it != st.end())
				st.erase(it);
		}

		auto it = st.find({ -len[parent], parent });
		if (it != st.end())
			st.erase(it);

	}
	cout << cnt << endl;

	return 0;
}
