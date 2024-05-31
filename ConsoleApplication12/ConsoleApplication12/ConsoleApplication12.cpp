//https://www.infoarena.ro/problema/kami
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
ifstream f("kami.in");
ofstream g("kami.out");
typedef long long ll;
const int N = 100005;

int n;
int v[N];

int main() {
	
	f >> n;
	int maxi = 0;
	for (int i = 1; i <= n; i++)
	{
		f >> v[i];
		if (v[i] > maxi)
			maxi = v[i];
	}
	int q;
	f >> q;
	while (q--) {
		int tip;
		f >> tip;
		if (tip == 0) {
			int a, b;
			f >> a >> b;
			v[a] = b;
			maxi = max(maxi, b);
		}
		else {
			int a;
			f >> a;
			int sol = 0;
			int s = v[a];
			for (int i = a - 1; i >= 1; i--)
			{
				if (v[i] >= s) {
					sol = i;
					break;
				}
				else if (s >= maxi) {
					sol = 0;
					break;
				}
				else s += v[i];
			}
			g << sol << "\n";
		}


	}
}

