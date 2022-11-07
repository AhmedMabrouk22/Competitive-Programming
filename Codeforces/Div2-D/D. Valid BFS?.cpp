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
vector<int>order;
bool com(const int &a, const int &b)
{
	return order[a] < order[b];
}

int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<vector<int>>graph(n + 1);
		vector<bool>vis(n + 1);
		vector<int>v(n);
		order = vector<int>(n+1);
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			order[v[i]] = i;
		}

		for (int i = 1; i <= n; ++i)
			sort(all(graph[i]), com);
		
		vector<int>res;
		queue<int>q;
		q.push(1);
		vis[1] = 1;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			res.push_back(cur);
			for (auto child : graph[cur])
			{
				if (!vis[child])
				{
					vis[child] = 1;
					q.push(child);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (v[i] != res[i])
				rt("No");
		}
		cout << "Yes";
	}
	return 0;
}
