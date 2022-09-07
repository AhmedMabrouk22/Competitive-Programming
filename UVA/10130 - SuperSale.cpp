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
int v[1005], w[1005];
int memo[1005][100];
int n, W;
int solve(int i, int rem)
{
	if (i == n || rem == 0)
		return 0;
	if (memo[i][rem] != -1)
		return memo[i][rem];
	int c1 = solve(i + 1, rem);
	int c2 = 0;
	if (w[i] <= rem)
		c2 = solve(i + 1, rem - w[i]) + v[i];
	return memo[i][rem] = max(c1, c2);
}
int main()
{
	A_M_S();
	int T = 1;
	cin >> T;
	while (T--)
	{
		clr(memo, -1);
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> v[i] >> w[i];
		int p;
		cin >> p;
		ll res = 0;
		while (p--)
		{
			cin >> W;
			res += solve(0, W);
		}
		cout << res << endl;
	}
	return 0;
}