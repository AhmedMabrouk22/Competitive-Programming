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
int MOD = 1e9 + 7;
vector<string>grid;
int n, m;
int memo[1005][1005];

bool valid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '.';
}

int solve(int i, int j)
{
	if (!valid(i, j))
		return 0;

	int cnt = 0;

	if (i == n - 1 && j == m - 1)
		return 1;

	if (memo[i][j] != -1)
		return memo[i][j];

	cnt += solve(i, j + 1);
	cnt += solve(i + 1, j);

	memo[i][j] = cnt % MOD;

	return cnt % MOD;
	
}

int main()
{
	A_M_S();
	clr(memo, -1);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		grid.push_back(s);
	}
	cout << solve(0, 0);

	return 0;
}
