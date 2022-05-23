// problem link : https://codeforces.com/contest/1006/problem/E
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

const int MAX = 2e5 + 5;
vector<vector<int>>tree;
int preorder[MAX]; // store elements in preorder 
int in_preorder[MAX]; // store index elements in preorder array
int last[MAX]; // index last element in the subtree

int order;
void dfs(int i)
{
	preorder[order] = i;
	in_preorder[i] = order++;
	for (auto child : tree[i])
		dfs(child);
	last[i] = order - 1;
}

int main()
{
	A_M_S();

	int n, q;
	cin >> n >> q;
	tree = vector < vector<int>>(n);
	for (int i = 1; i < n; ++i)
	{
		int x;
		cin >> x;
		--x;
		tree[x].push_back(i);
	}

	dfs(0);

	for (int i = 0; i < q; ++i)
	{
		int u, k;
		cin >> u >> k;
		--u;
		--k;
		k += in_preorder[u];
		if (k <= last[u]) // if k is still in the subtree
			cout << preorder[k] + 1 << endl;
		else
			cout << -1 << endl;

	}


	return 0;
}
