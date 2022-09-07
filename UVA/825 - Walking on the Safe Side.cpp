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
int m, n;
int arr[1000][1000];
int memo[1000][1000];
bool valid(int r, int c)
{
	return r >= 0 && r < n&&c >= 0 && c < m&&!arr[r][c];
}

int solve(int r, int c)
{
	if (!valid(r, c))
		return 0;
	if (r == n-1 && c == m-1)
		return 1;
	if (memo[r][c] != -1)
		return memo[r][c];
	int c1 = 0;
	c1 += solve(r + 1, c);
	c1 += solve(r, c + 1);
	return memo[r][c] = c1;
}

int main()
{
	A_M_S();
	int T = 1;
	cin >> T;
	while (T--)
	{
		clr(arr, 0);
		clr(memo, -1);
		cin >> n >> m;
		cin.ignore();
		for (int i = 0; i < n; ++i)
		{
			vector<int>v;
			string s;
			getline(cin, s);
			stringstream ss(s);
			string temp;
			while (ss >> temp)
			{
				int num = stoi(temp);
				v.push_back(num - 1);
			}
			int x = sz(v);
			for (int k = 1; k < x; ++k)
				arr[v[0]][v[k]] = 1;
		}
		cout << solve(0, 0) << endl;
		if (T)
			cout << endl;
	}
	return 0;
}
