//https://codeforces.com/gym/103999/problem/l
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll putere(ll exp) {
	ll rez = 1;
	ll nr = 2;
	while (exp > 0) {
		if (exp % 2 == 1)
			rez = (rez * nr) % MOD;
		exp /= 2;
		nr = (nr * nr) % MOD;
	}
	return rez;
}

int arb[N * 4];
int v[N];
void build(int nod, int st, int dr) {
	if (st == dr){
		arb[nod] = v[st];
	}
	else {
		int mij = (st + dr) / 2;
		build(2 * nod, st, mij);
		build(2 * nod + 1, mij + 1, dr);
		arb[nod] = max(arb[2 * nod], arb[2 * nod + 1]);
	}

}
int query(int nod, int st, int dr, int qst, int qdr) {
	if (qst <= st && dr <= qdr)
		return arb[nod];
	int mij = (st + dr) / 2;
	if (mij >= qdr)
		return query(2 * nod, st, mij, qst, qdr);
	if (mij+1 <= qst)
		return query(2 * nod + 1, mij + 1, dr, qst, qdr);
	return max(query(2 * nod, st, mij, qst, qdr), query(2 * nod + 1, mij + 1, dr, qst, qdr));
}
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int s, d;
		cin >> s >> d;
		//1<<(d-s)*maxi
		ll sol = putere(d-s) * query(1, 1, n, s, d) % MOD;
		cout <<sol  << "\n";
	}
}
