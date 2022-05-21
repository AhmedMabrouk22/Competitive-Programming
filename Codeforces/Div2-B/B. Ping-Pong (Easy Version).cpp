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


vector<pair<int, int>> sets;
int nodes;

bool bfs(int s, int d)
{
	vector<bool>vis(nodes+1);
	queue<int>q;
	q.push(s-1);
	vis[s-1] = true;
	--d;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == d)
			return true;

		for (int i = 0; i < nodes; ++i)
		{
			if (cur != d && !vis[i])
			{
				if ((sets[cur].first < sets[i].second && sets[cur].first > sets[i].first)
					|| (sets[cur].second < sets[i].second && sets[cur].second > sets[i].first))
				{
					vis[i] = true;
					q.push(i);
				}
			}
		}

	}
	return false;
}

int main()
{
	A_M_S();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 1)
		{
			++nodes;
			sets.push_back({ a, b });
		}
		else
		{
			if (bfs(a,b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
