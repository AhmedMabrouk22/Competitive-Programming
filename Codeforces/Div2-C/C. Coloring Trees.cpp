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
int n, m, k;
vector<int>c;
ll memo[105][105][105];
int tree[105][105];

ll solve(int i, int col, int rem)
{
	if (i == n)
		return (!rem ? 0 : 1e18);
	if (memo[i][col][rem] != -1)
		return memo[i][col][rem];

	memo[i][col][rem] = 1e18;
	if (!c[i])
	{
		for (int j = 1; j <= m; ++j)
			memo[i][col][rem] = min(memo[i][col][rem], solve(i + 1, j, rem - (j != col)) + tree[i][j]);
	}
	else 
		memo[i][col][rem] = solve(i + 1, c[i], rem - (c[i] != col));

	return memo[i][col][rem];
}

int main()
{
	A_M_S();
	clr(memo, -1);
	cin >> n >> m >> k;
	c = vector<int>(n+1);
	full(c, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> tree[i][j];
	}

	ll res = solve(0, 0, k);
	if (res >= 1e18)
		cout << -1;
	else
		cout << res;

/*
3 3 3
0 1 0
1 2 3
1 2 3
1 2 3
*/
	return 0;
}
