//https://infoarena.ro/problema/plantatie
#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("plantatie.in");
ofstream cout("plantatie.out");
int n, m;
int mat[503][503][10];
int cmmdc(int a, int b) {
	if (b == 0)
		return a;
	return cmmdc(b, a % b);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j][0];
	int lg = log2(n);
	for (int poz = 1; poz <= lg; poz++)
		for (int i = 0; i < n -( 1 << poz)+1; i++)
			for (int j = 0; j < n - (1 << poz) +1; j++)
				mat[i][j][poz] = max(mat[i][j][poz - 1],
					max(mat[i][j + (1 << (poz - 1))][poz - 1],
						max(mat[i + (1 << (poz - 1))][j][poz - 1],
							mat[i + (1 << (poz - 1))][j + (1 << (poz - 1))][poz - 1])));
	
	/*cout << "------------------------\n";
	for (int poz = 1; poz <= lg; poz++){
		for (int i = 0; i < n - (1 << poz) + 1; i++){
			for (int j = 0; j < n - (1 << poz) + 1; j++)
				cout << mat[i][j][poz] << "   ";
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "------------------------\n";*/

	for (int q = 0; q < m; q++)
	{
		int i, j, k;
		cin >> i >> j >> k;
		i--; j--;
		int k1 = k;
		k= log2(k);
		int ans = max(mat[i][j][k],
			max(mat[i][j+k1 -(1 << k)][k],
				max(mat[i+k1 - (1 << k)][j][k],
					mat[i+k1 - (1 << k)][j+k1 - (1 << k)][k])));
		//cout << mat[i][j][k] << " " << mat[i][j + k1 - 1 << k][k] << " " << mat[i + k1 - 1 << k][j][k] << " " << mat[i + k1 - 1 << k][j + k1 - 1 << k][k] << " \n";
		cout << ans << "\n";
	}
}
