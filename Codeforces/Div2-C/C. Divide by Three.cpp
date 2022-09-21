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
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

ll gcd(ll a, ll b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
const int MAX_IN = 1e5 + 5;
int n;
int memo[MAX_IN][3][2], dp[MAX_IN][3][2];

string s;
ll solve(int i, int rem, int tk)
{
	if (i == n)
	{
		if (rem == 0 && tk)
			return 0;
		return OO;
	}

	if (memo[i][rem][tk] != -1)
		return memo[i][rem][tk];

	ll c1 = solve(i + 1, rem, tk) + 1;
	ll c2 = OO;
	if (tk || s[i] != '0')
	{
		ll nx = rem * 10 + (s[i] - '0');
		c2 = solve(i + 1, nx % 3, 1);
	}
	
	if (c1 < c2)
	{
		memo[i][rem][tk] = c1;
		dp[i][rem][tk] = 1;
	}
	else
	{
		memo[i][rem][tk] = c2;
		dp[i][rem][tk] = 2;
	}
	
	return memo[i][rem][tk];

}	


void build(int i, int rem, int tk)
{
	if (i == n)
		return;
	if (dp[i][rem][tk] == 1)
		build(i + 1, rem, tk);
	else
	{
		cout << s[i];
		ll nx = rem * 10 + (s[i] - '0');
		build(i + 1, nx % 3, 1);
	}
}

int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (T--)
	{
		clr(memo, -1);
		cin >> s;
		n = sz(s);
		bool f = 0;
		for (auto i : s)
			f = max(f, (i == '0'));
		ll res = solve(0, 0, 0);

		if (res >= oo)
			cout << (f ? 0 : -1);
		else
			build(0, 0, 0);
	}
	return 0;
}
