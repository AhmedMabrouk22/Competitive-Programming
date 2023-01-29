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

int main()
{
	A_M_S();
	int T = 1;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<vector<int>>graph(n+1);
		vector<int>dis(n+1,(int)1e9);
		vector<int>c(n+1);
		full1(c, n);
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int res = 1e9;
		for (int i = 1; i <= n; ++i)
		{
			res = min(res, dis[c[i]]);
			if (i > 1)
				cout << res << " ";
			if (i == n)
			{
				cout << endl;
				break;
			}

			queue<int>q;
			q.push(c[i]);
			dis[c[i]] = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto child : graph[cur])
				{
					if (dis[child] > dis[cur] + 1 && res > dis[cur] + 1)
					{
						q.push(child);
						dis[child] = dis[cur] + 1;
					}
				}
			}

		}
	}
	return 0;
}
