//https://www.infoarena.ro/problema/euclid
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
typedef long long ll;
const int N = 405;
ll mat[N][N];

int cmmdc(int a, int b) {
	if (b == 0)
		return a;
	return cmmdc(b, a % b);
}


int main() {
	//rmq 2D cin
	int tc;
	f >> tc;
	for(int t=1;t<=tc;t++)
	{
		int n, m, h, w;
		int curent = 0, maxcmmdc = 0;
		f >> n >> m >> h >> w;
		for (int i =1 ; i <=n; i++)
			for (int j = 1; j <= m; j++)
				f >> mat[i][j];
		for (int k = 1; k <= n - h + 1; k++)
			for (int l = 1; l <= m - w + 1; l++)
			{
				curent = mat[k][l];
				for (int i = k;curent>maxcmmdc && i <= k + h - 1; i++)
					for (int j = l; curent > maxcmmdc && j <= l + w - 1; j++)
					{
						curent = cmmdc(curent, mat[i][j]);
					}
				if (curent > maxcmmdc)
					maxcmmdc = curent;
			}

		g << "Case #" << t << ": " << maxcmmdc << "\n";
		
	}

}
/*

1
4 5 1 1
1 2 3 4 5
6 7 8 9 10
1 2 3 4 5
6 7 8 9 10


*/


