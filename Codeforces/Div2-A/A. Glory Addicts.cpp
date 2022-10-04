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
int main()
{
	A_M_S();
	int T = 1;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<ll>t(n), d(n);
		full(t, n);
		full(d, n);
		vector<pair<ll, ll>>t1, t2;
		for (int i = 0; i < n; ++i)
		{
			if (!t[i])
				t1.push_back({ d[i], t[i] });
			else
				t2.push_back({ d[i], t[i] });
		}

		sort(all(t1));
		sort(all(t2));

		ll res = 0;
		if (sz(t1) == sz(t2))
			res -= min(t1.front().first, t2.front().first);

		while (!t1.empty() && !t2.empty())
		{
			res += (t1.back().first + t2.back().first) * 2;
			t1.pop_back();
			t2.pop_back();
		}

		for (auto i : t1)
			res += i.first;
		for (auto i : t2)
			res += i.first;

		cout << res << endl;
	}
	return 0;
}
