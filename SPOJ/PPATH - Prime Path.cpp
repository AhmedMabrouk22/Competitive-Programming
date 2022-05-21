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
int n, m;
vector<vector<int>>graph;
vector<int>prime, len;

bool is_prime(int n)
{
	for (int i = 2; i*i <= n; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

bool valid(int a, int b)
{
	string s1 = to_string(a);
	string s2 = to_string(b);

	int c = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (s1[i] != s2[i])
			++c;
	}

	return c == 1;

}

void build_graph()
{
	graph = vector<vector<int>>(9999);

	for (int i = 0; i < sz(prime); ++i)
	{
		for (int j = i + 1; j < sz(prime); ++j)
		{
			if (valid(prime[i], prime[j]))
			{
				graph[prime[i]].push_back(prime[j]);
				graph[prime[j]].push_back(prime[i]);
			}
		}
	}
}

int bfs()
{
	len = vector<int>(9999, -1);
	queue<int>q;
	q.push(n);
	len[n] = 0;

	int cur, dep = 0, q_sz = sz(q);

	for (; !q.empty(); ++dep, q_sz = sz(q))
	{
		while (q_sz--)
		{
			cur = q.front();
			q.pop();
			for (auto child : graph[cur])
			{
				if (len[child] == -1)
				{
					len[child] = dep + 1;
					q.push(child);
				}
			}
		}
	}
	return len[m];
}

int main()
{
	A_M_S();

	for (int i = 1000; i <= 9999; ++i)
	{
		if (is_prime(i))
			prime.push_back(i);
	}

	build_graph();

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int res = bfs();
		if (res != -1)
			cout << res << endl;
		else
			cout << "Impossible" << endl;
	}

	return 0;
}
