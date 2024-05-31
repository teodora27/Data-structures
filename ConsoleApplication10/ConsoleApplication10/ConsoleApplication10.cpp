//https://www.infoarena.ro/problema/stramosi
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
ifstream f("stramosi.in");
ofstream g("stramosi.out");
typedef long long ll;
const ll N = 250005;
const int logN = 20;
int n, m;
int mat[N][logN];
int lg[N];

int main() {
	f >> n >> m;
	for (int i = 1; i <= n; i++)
		f >> mat[i][0];

	for (int i = 0; i <= 18; i++)
		lg[1<<i] = i;
	for (int i = 1; i <= n; i++)
		if (lg[i] == 0)
			lg[i] = lg[i - 1];

	for(int j=1;j<=18;j++)
		for (int i = 1; i <= n; i++)
			mat[i][j] = mat[mat[i][j - 1]][j - 1];
	while (m--) {
		int om, nr;
		f >> om >> nr;
		while (om > 0 && nr > 0) {
			int log = lg[nr];
			om = mat[om][log];
			nr -= (1<<log);
		}
		g << om << "\n";
	}
}


