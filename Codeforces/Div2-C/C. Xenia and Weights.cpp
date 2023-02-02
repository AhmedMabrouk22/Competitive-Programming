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
const int MAX_IN = 1e5 + 5;
string s;
int k;
vector<int>res,v;
void solve(int cnt, int sum1, int sum2, bool who)
{
	if (cnt == k)
	{
		cout << "YES" << endl;
		for (int i = 0; i < k; ++i)
			cout << res[i] << " ";
		exit(0);
	}

	for(auto i : v)
	{
		if (res.empty() || i != res.back())
		{
			if (who && sum1 + i > sum2)
			{
				res.push_back(i);
				solve(cnt + 1, sum1+i, sum2, !who);
				res.pop_back();
			}
			else if (!who && sum2 + i > sum1) 
			{
				res.push_back(i);
				solve(cnt + 1, sum1, sum2+i, !who);
				res.pop_back();
			}
		}
	}
	

}

int main()
{
	A_M_S();
	int T = 1;
	//cin >> T;
	while (T--)
	{
		cin >> s >> k;
		for (int i = 0; i < 10; ++i)
		{
			if (s[i] == '1')
				v.push_back(i + 1);
		}
		solve(0, 0, 0, 0);
		cout << "NO" ;
	}
	return 0;
}
