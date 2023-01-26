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
const int MAX_IN = 1e6 + 5;
int prf[MAX_IN];
int suf[MAX_IN];
int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (T--)
	{
		string s;
		int a, b;
		cin >> s >> a >> b;
		ll rem = 0;
		for (int i = 0; i < sz(s); ++i)
		{
			rem *= 10;
			rem = (rem + (s[i] - '0')) % a;
			prf[i] = rem;
		}

		ll pos = 1;
		rem = 0;
		for (int i = sz(s) - 1; i >= 0; --i)
		{
			rem = (rem + ((s[i] - '0')*pos)) % b;
			pos = (pos * 10) % b;
			suf[i] = rem;
		}

		for (int i = 0; i < sz(s) - 1; ++i)
		{
			if (!prf[i] && !suf[i + 1] && s[i + 1] != '0')
			{
				cout << "YES" << endl;
				for (int j = 0; j <= i; ++j)
					cout << s[j];
				cout << endl;
				for (int j = i + 1; j < sz(s); ++j)
					cout << s[j];
				return 0;
			}
		}
		cout << "NO";
	}
	return 0;
}
