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
	ll a, b;
	cin >> a >> b;
	vector<ll>v;
	for (ll i = a; i <= a*b; i += a)
		v.push_back(i);
	for (ll i = b; i < a*b; i += b)
		v.push_back(i);
	sort(all(v));
	/*
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	*/

	ll ta = 0, tb = 0;
	for (int i = 0; i < sz(v); ++i)
	{
		if (v[i] % a == 0 && v[i] % b == 0)
		{
			if (ta>tb) ++tb;
			else ++ta;
			break;
		}
		else if (v[i] % a == 0 && v[i] % b != 0)
			++ta;
		else if (v[i] % a != 0 && v[i] % b == 0)
			++tb;
	}
	if (ta == tb) cout << "Equal";
	else if (ta > tb) cout << "Dasha";
	else if (ta < tb) cout << "Masha";
	return 0;
}
