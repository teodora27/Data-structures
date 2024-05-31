//https://codeforces.com/gym/103999/problem/I
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;
vector<ll>toate;
vector<ll>a, b;

int intre(int st, int dr) {
	//intr toate[st] si toate[dr]
	if (st > dr)
		return 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= toate[st] && a[i] <= toate[dr])
			continue;
		if (b[i] >= toate[st] && b[i] <= toate[dr])
			continue;
		return 0;
	}
	return 1;
}
#include <cassert>
int main() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		toate.push_back(a[i]);
		toate.push_back(b[i]);
	}
	if (n == 2) {
		ll sol = min(abs(a[0] - a[1]), abs(a[0] - b[1]));
		sol = min(sol, abs(b[0] - b[1]));
		sol = min(sol, abs(b[0]- a[1]));
		cout << sol;
		return 0;
	}
	sort(toate.begin(), toate.end());
	toate.resize(unique(toate.begin(), toate.end()) - toate.begin());
	int st = 0, dr = 0;
	ll sol = 1e9;
	while (!intre(0, dr) && dr < toate.size() - 1)
		dr++;
	while (dr < toate.size() - 1) {
		while (intre(st, dr) && st < toate.size() - 1)
			st++;
		sol = min(sol, toate[dr] - toate[st - 1]);
		dr++;
	}
	cout << sol;
}
