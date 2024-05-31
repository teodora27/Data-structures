#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;
typedef long long ll;
const int N = 1000005;

ll zero(int x) { return x & (-x); }

ll q;
vector<pair<ll, ll>>aib(N, {0,0});
//aib[i].first=cate nr sunt pana la i
//aib[i].second=suma nr <=i din vector

void add(ll a, pair<ll,ll> b) {
	for (ll i = a; i < N; i += zero(i))
	{
		aib[i].first += b.first;
		aib[i].second += b.second;
	}
}

pair<ll, ll> query(ll a) {
	//suma elem pana la poz a
	pair<ll, ll> sum = {0,0};
	for (ll i = a; i > 0; i -= zero(i))
	{
		sum.first += aib[i].first;
		sum.second += aib[i].second;
	}
	return sum;
}



int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		ll tip, nr;
		cin >> tip >> nr;
		if (tip == 1)
			add(nr, { 1,nr });
		else {
			ll st = 1;
			ll dr = N;
			ll sol = -1;
			while (st <= dr) {
				ll mij = (st + dr) / 2;
				pair<ll, ll> curent = query(mij);
				if (curent.first >= nr) {
					sol = mij;
					dr = mij - 1;
				}
				else {
					st = mij + 1;
				}
			}
			if (sol == -1)
				sol = st;

			/*for (int i = 0; i <= 20; i++)
				cout << i << ": " << aib[i].first << " " << aib[i].second << "\n";
			cout << "\n";*/

			ll scad = query(sol).first -nr;
			cout <<query(sol).second-(sol*scad)<< "\n";

		}
	}
}
