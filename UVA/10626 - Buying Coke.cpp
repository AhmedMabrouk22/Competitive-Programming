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
int cnt, n1, n5, n10;
int memo[500][500][500];
int solve(int c, int x, int y, int z)
{
	if (c == cnt)
		return 0;
	if (memo[c][y][z] != -1)
		return memo[c][y][z];
	memo[c][y][z] = 1e9;
	if (z)
		memo[c][y][z] = min(memo[c][y][z], solve(c + 1, x + 2, y, z - 1) + 1);
	if (y > 1)
		memo[c][y][z] = min(memo[c][y][z], solve(c + 1, x + 2, y - 2, z) + 2);
	if (x >= 3 && y)
		memo[c][y][z] = min(memo[c][y][z], solve(c + 1, x - 3, y - 1, z) + 4);
	if (x >= 3 && z)
		memo[c][y][z] = min(memo[c][y][z], solve(c + 1, x - 3, y + 1, z - 1) + 4);
	if (x >= 8)
		memo[c][y][z] = min(memo[c][y][z], solve(c + 1, x - 8, y, z) + 8);
	return memo[c][y][z];

}

int main()
{
	A_M_S();

	int t;
	cin >> t;
	while (t--)
	{
		clr(memo, -1);
		cin >> cnt >> n1 >> n5 >> n10;
		cout << solve(0, n1, n5, n10) << endl;
	}

	return 0;
}
