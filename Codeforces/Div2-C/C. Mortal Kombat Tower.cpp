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
const int MAX_IN = 2e5 + 5;
int memo[MAX_IN][2];
int arr[MAX_IN];
int n;
int solve(int i, int p)
{
	if (i >= n)
		return 0;
	if (memo[i][p] != -1)
		return memo[i][p];

	int c1 = 1e9, c2 = 1e9;
	if (!p)
	{
		c1 = min(c1, solve(i + 1,!p) + arr[i]);
		c2 = min(c2, solve(i + 2, !p) + arr[i] + arr[i + 1]);
	}
	else
	{
		c1 = solve(i + 1, !p);
		c2 = solve(i + 2, !p);
	}
	return memo[i][p] = min(c1, c2);
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
		full(arr, n);
		cout << solve(0, 0) << endl;
	}
	return 0;
}
