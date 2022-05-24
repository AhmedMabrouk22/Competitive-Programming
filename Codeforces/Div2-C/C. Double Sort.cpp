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
using namespace std;

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

int a[105], b[105];

int main()
{
	A_M_S();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		full(a, n);
		full(b, n);

		vector<pair<int, int>>mov;

		for (int i = 0; i < n; ++i)
		{

			for (int j = 0; j < n-1; ++j)
			{
				if (a[j] > a[j+1] || b[j] > b[j+1])
				{
				    swap(a[j], a[j+1]);
			    	swap(b[j], b[j+1]);
			    	mov.push_back({ j + 1, j + 2 });
				}
			}
		}


		bool ok = true;

		for (int i = 0; i < n-1; ++i)
		{
			if (a[i] > a[i + 1])
			{
				ok = false;
				break;
			}
		}

		for (int i = 0; i < n - 1; ++i)
		{
			if (b[i] > b[i + 1])
			{
				ok = false;
				break;
			}
		}

		if (!ok)
			cout << -1 << endl;
		else if (sz(mov) <= 10000)
		{
			cout << sz(mov) << endl;
			for (auto i : mov)
				cout << i.first << " " << i.second << endl;
		}

	}

	return 0;
}
