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
const int MAX_IN = 1e3 + 5;
int n;
string s;
string memo[MAX_IN][MAX_IN];
string solve(int l, int r)
{
	if (l > r)
		return "";
	
	if (l == r)
		return string(1, s[l]);

	if (memo[l][r] != "")
		return memo[l][r];


	if (s[l] == s[r])
		memo[l][r] = s[l] + solve(l + 1, r - 1) + s[l];
	else
	{
		string c1 = solve(l + 1, r);
		string c2 = solve(l, r - 1);
		if (sz(c1) > sz(c2))
			memo[l][r] = c1;
		else if (sz(c2) > sz(c1))
			memo[l][r] = c2;
		else
			memo[l][r] = min(c1, c2);
	}
	return memo[l][r];
}

int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (cin >> s)
	{

		for (int i = 0; i < MAX_IN; ++i)
		{
			for (int j = 0; j < MAX_IN; ++j)
				memo[i][j] = "";
		}
		cout << solve(0, sz(s) - 1) << endl;
	}
	return 0;
}
