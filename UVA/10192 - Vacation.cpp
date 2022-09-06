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
string s1, s2;

ll memo[150][150];
ll solve(int i, int j)
{
	if (i == sz(s1) || j == sz(s2))
		return 0;
	if (memo[i][j] != -1)
		return memo[i][j];
	ll c1 = 0, c2 = 0, c3 = 0;
	if (s1[i] == s2[j])
		c1 = solve(i + 1, j + 1) + 1;
	c2 = solve(i + 1, j);
	c3 = solve(i, j + 1);
	return memo[i][j] = max(c1, max(c2, c3));
}
int main()
{
	A_M_S();
	int t = 1;
	while (getline(cin,s1) && s1 != "#")
	{
		getline(cin, s2);
		clr(memo, -1);
		cout << "Case #" << t++ << ": you can visit at most " << solve(0, 0) << " cities." << endl;
	}
	return 0;
}
