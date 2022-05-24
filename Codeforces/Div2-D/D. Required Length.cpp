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
ll n, x;

ll num(string x)
{
	ll sum = 0;
	for (auto i : x)
		sum = sum * 10 + i - '0';
	return sum;
}

int bfs()
{
	map<ll, ll>len;
	queue<ll>q;
	q.push(x);
	len[x] = 0;

	ll cur;
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		string cur_s = to_string(cur);
		if (sz(cur_s) == n)
			return len[cur];

		for (int i = 0; i < sz(cur_s); ++i)
		{
			ll ne = cur*(cur_s[i] - '0');
			if (!len.count(ne))
			{
				q.push(ne);
				len[ne] = len[cur] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	A_M_S();


	
	cin >> n >> x;
	cout << bfs() << endl;
	return 0;
}
