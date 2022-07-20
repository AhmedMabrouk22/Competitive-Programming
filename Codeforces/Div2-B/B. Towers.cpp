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

int main()
{
	A_M_S();
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(all(v));
	vector<pair<int, int>>res;
	int op = 1, m = v[n - 1].first - v[0].first, mn = m;
	while (op <= k && m && mn > 0)
	{
		++v[0].first;
		--v[n - 1].first;
		res.push_back({ v[n - 1].second, v[0].second });
		++op;
		sort(all(v));
		mn = v[n - 1].first - v[0].first;
	}
	cout << mn << " " << sz(res) << endl;
	for (auto i : res)
		cout << i.first << " " << i.second << endl;
	return 0;
}
