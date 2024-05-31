//https://www.infoarena.ro/problema/timbre
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("timbre.in");
ofstream g("timbre.out");
typedef long long ll;
int n, m, k;
class Comparare1 {
public:
	int operator()(const pair<int, int>& p1, const pair<int, int>& p2)const
	{
		return p1.first < p2.first;
	}
};
class Comparare2 {
public:
	int operator()(const pair<int, int>& p1, const pair<int, int>& p2)const
	{
		return p1.second > p2.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Comparare1>pq1;//dupa capat
priority_queue<pair<int, int>, vector<pair<int, int>>, Comparare2>pq2;//dupa cost
//capat, cost
int main()
{
	f >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y;
		f >> x >> y;
		pq1.push({ x,y });
	}
	ll suma = 0;
	bool se_poate = true;
	while (n>0)
	{
		while (!pq1.empty() && pq1.top().first >= n)
		{
			pq2.push(pq1.top());
			pq1.pop();
		}
		if (pq2.empty())
		{
			se_poate = false;
			break;
		}
		suma += pq2.top().second;
		pq2.pop();
		n -= k;
	}
	if (se_poate)
		g << suma;
	else g << "-1";
}

