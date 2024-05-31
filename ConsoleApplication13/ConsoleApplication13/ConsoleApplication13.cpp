//https://kilonova.ro/problems/556
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
ifstream f("sirbun.in");
ofstream g("sirbun.out");
typedef long long ll;
const int N = 100005;

ll n;
ll v[N], pozitii[N];
ll arb[4 * N], lazy[4*N];

void build(ll nod, ll st, ll dr) {
	if (st == dr)
		arb[nod] = st;
	else {
		ll mij = (st + dr) / 2;
		build(2 * nod, st, mij);
		build(2 * nod + 1, mij + 1, dr);
		arb[nod] = min(arb[2*nod],arb[2*nod+1]);
	}
}

void update(ll nod, ll st, ll dr, ll qst, ll qdr, ll val)
{
	if (lazy[nod]&&(st!=dr))
	{
		lazy[2 * nod] += lazy[nod];
		lazy[2 * nod+1] += lazy[nod];
		arb[2 * nod] += lazy[nod];
		arb[2 * nod+1] += lazy[nod];
		lazy[nod] = 0;
	}
	if (qst <= st && dr <= qdr)
	{
		arb[nod] += val;
		lazy[nod]+= val;
	}
	else {
		ll mij = (st + dr) / 2;
		if (mij >= qst)
			update(2 * nod, st, mij, qst, qdr, val);
		if (mij < qdr)
			update(2 * nod + 1, mij + 1, dr, qst, qdr, val);
		arb[nod] = min(arb[2 * nod], arb[2 * nod + 1]);
	}
}


int main() {
	f >> n;
	for (ll i = 1; i <= n; i++)
		f >> v[i];
	build(1, 1, n);
	ll st = 1, dr = 1;
	ll sol = 0;
	for (ll dr = 1; dr <= n; dr++)
	{
		update(1, 1, n, v[dr], n, -1);
		while (arb[1] < 0)
		{
			update(1, 1, n, v[st], n, 1);
			st++;
		}
		sol += (dr - st + 1);
	}
	g << sol;
}

