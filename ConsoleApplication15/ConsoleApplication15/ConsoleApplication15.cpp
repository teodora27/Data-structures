//https://kilonova.ro/problems/304
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const ll N = 100005;
const ll INF = 1e5 + 27;


struct node {
	ll maxpref, maxsuf, best, sum;
};

ll n, m;
ll minpref;
vector<ll>v1(N), v2(N), sume(N);
node arb_plus[N * 4], arb_minus[N*4];
ll maxsum, maxsum2, prefix, prefix2;

void update_plus(ll nod, ll st, ll dr, ll poz, ll val)
{
	if (st == dr) {
		arb_plus[nod].maxpref = v1[st];
		arb_plus[nod].maxsuf = v1[st];
		arb_plus[nod].best = v1[st];
		arb_plus[nod].sum = v1[st];
	}
	else {
		ll mij = (st + dr) / 2;
		if (poz <= mij)
			update_plus(nod * 2, st, mij, poz, val);
		if (poz > mij)
			update_plus(2 * nod + 1, mij + 1, dr, poz, val);

		arb_plus[nod].sum = arb_plus[2 * nod].sum + arb_plus[2 * nod + 1].sum;
		arb_plus[nod].maxpref = max(arb_plus[2 * nod].maxpref, arb_plus[2 * nod].sum + arb_plus[2 * nod + 1].maxpref);
		arb_plus[nod].maxsuf = max(arb_plus[2 * nod + 1].maxsuf, arb_plus[2 * nod].maxsuf + arb_plus[2 * nod + 1].sum);
		arb_plus[nod].best = max({ arb_plus[2 * nod].best,
			arb_plus[2 * nod + 1].best,
			arb_plus[2 * nod].maxsuf + arb_plus[2 * nod + 1].maxpref });
	}

}

void update_minus(ll nod, ll st, ll dr, ll poz, ll val)
{
	if (st == dr) {
		arb_minus[nod].maxpref = v2[st];
		arb_minus[nod].maxsuf = v2[st];
		arb_minus[nod].best = v2[st];
		arb_minus[nod].sum = v2[st];
	}
	else {
		ll mij = (st + dr) / 2;
		if (poz <= mij)
			update_minus(nod * 2, st, mij, poz, val);
		if (poz > mij)
			update_minus(2 * nod + 1, mij + 1, dr, poz, val);

		arb_minus[nod].sum = arb_minus[2 * nod].sum + arb_minus[2 * nod + 1].sum;
		arb_minus[nod].maxpref = max(arb_minus[2 * nod].maxpref, arb_minus[2 * nod].sum + arb_minus[2 * nod + 1].maxpref);
		arb_minus[nod].maxsuf = max(arb_minus[2 * nod + 1].maxsuf, arb_minus[2 * nod].maxsuf + arb_minus[2 * nod + 1].sum);
		arb_minus[nod].best = max({ arb_minus[2 * nod].best,
			arb_minus[2 * nod + 1].best,
			arb_minus[2 * nod].maxsuf + arb_minus[2 * nod + 1].maxpref });
	}

}

void query_plus(ll nod, ll st, ll dr, ll qst, ll qdr) {
	if (qst <= st && dr <= qdr)
	{
		maxsum = max(arb_plus[nod].best, maxsum);
		maxsum = max(maxsum, prefix + arb_plus[nod].maxpref);
		prefix = max(prefix + arb_plus[nod].sum, arb_plus[nod].maxsuf);
	}
	else
	{
		ll mij = (st + dr) / 2;
		if (qst <= mij)
			query_plus(2 * nod, st, mij, qst, qdr);
		if (qdr > mij)
			query_plus(2 * nod + 1, mij + 1, dr, qst, qdr);
	}
}

void query_minus(ll nod, ll st, ll dr, ll qst, ll qdr) {
	if (qst <= st && dr <= qdr)
	{
		maxsum2 = max(arb_minus[nod].best, maxsum2);
		maxsum2 = max(maxsum2, prefix2 + arb_minus[nod].maxpref);
		prefix2 = max(prefix2 + arb_minus[nod].sum, arb_minus[nod].maxsuf);
	}
	else
	{
		ll mij = (st + dr) / 2;
		if (qst <= mij)
			query_minus(2 * nod, st, mij, qst, qdr);
		if (qdr > mij)
			query_minus(2 * nod + 1, mij + 1, dr, qst, qdr);
	}
}


int main() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if(i%2==1)
		{
			v1[i] = x;
			v2[i] = -x;
		}
		else
		{
			v1[i] = -x;
			v2[i] = x;
		}
		update_plus(1, 1, n, i, v1[i]);
		update_minus(1, 1, n, i, v2[i]);
	}
	
	while (m--) {
		int tip, a, b;
		cin >> tip >> a >> b;
		if (tip == 1) {
			if (a % 2 == 1) {
				v1[a] = b;
				v2[a] = -b;
				update_plus(1, 1, n, a, v1[a]);
				update_minus(1, 1, n, a, v2[a]);
			}
			else {
				v1[a] = -b;
				v2[a] = b;
				update_plus(1, 1, n, a, v1[a]);
				update_minus(1, 1, n, a, v2[a]);
			}
		}
		else{
			maxsum = -INF;
			maxsum2 = -INF;
			prefix = 0;
			prefix2 = 0;
			query_plus(1, 1, n, a, b);
			query_minus(1, 1, n, a, b);
			cout << max(maxsum, maxsum2) << "\n";
		}

	}
}