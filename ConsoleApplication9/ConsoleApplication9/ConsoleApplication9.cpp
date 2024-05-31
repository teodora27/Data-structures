//https://infoarena.ro/problema/pikachu
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
ifstream f("pikachu.in");
ofstream g("pikachu.out");
typedef long long ll;

int n, k;
vector<int>v;
int maxi;

ll valoare(int x) {
	ll sum = 0;
	for (int i = 0; i < k; i++)
		sum += abs(v[i] - x);
	ll mini = sum;
	for (int i = k; i < n; i++)
	{
		sum += abs(v[i] - x);
		sum -= abs(v[i - k] - x);
		if (sum < mini)
			mini = sum;
	}
	return mini;
}

int main() {
	f >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		f >> v[i];
		if (v[i] > maxi)
			maxi = v[i];
	}
	/*for (int i = 0; i <= maxi; i++)
		cout << i << " ";
	cout << "\n";

	for (int i = 0; i <= maxi; i++)
		cout << valoare(i) << " ";
	cout << "\n";*/
	ll st = 0, dr = maxi;
	while (st < dr) {
		//cout << st << " " << dr << "\n";
		ll mij = (st + dr) / 2;
		ll val1 = valoare(mij - 1);
		ll val2 = valoare(mij);
		ll val3 = valoare(mij + 1);
		if (val2 > val3)
			st = mij +1;
		else
			dr = mij;
	}
	g << valoare(st);

}
