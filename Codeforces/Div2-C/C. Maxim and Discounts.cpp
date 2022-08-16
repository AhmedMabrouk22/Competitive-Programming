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
bool com(int a, int b)
{
	return a > b;
}
int main()
{
	A_M_S();
	int m, n;
	cin >> m;
	vector<int>q(m);
	full(q, m);
	cin >> n;
	vector<int>v(n+1);
	full1(v, n);
	sort(v.begin() + 1, v.end(), com);
	for (int i = 1; i <= n; ++i)
		v[i] += v[i - 1];
	/*
	for (int i = 0; i <= n; ++i)
		cout << v[i] << " ";
	cout << endl;
	*/
	ll res = LLONG_MAX;
	ll sum = 0;
	for (int i = 0; i < m; ++i)
	{
		sum = 0;
		int j = 1;
		for (; j + q[i] <= n; j += q[i] + 2)
			sum += v[j + q[i]-1] - v[j-1];
		if (j <= n)
			sum += v[n] - v[j - 1];
		res = min(res, sum);
	}
	cout << res;
	
	return 0;
}
