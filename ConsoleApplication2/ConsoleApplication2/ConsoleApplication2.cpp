//https://www.infoarena.ro/problema/proc2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("proc2.in");
ofstream g("proc2.out");
typedef long long ll;
int n, m;
class Comparare {
public:
	int operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return p1.second > p2.second;
	}
};
priority_queue<int, vector<int>, greater<int>>pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, Comparare>pq2;
int main()
{
	f >> n >> m;
	vector<pair<int, pair<int,int>>>task;
	vector<int>rasp(m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		f >> x >> y;
		task.push_back({ x,{y+x,i} });
	}
	sort(task.begin(), task.end());
	for (int i = 0; i < n; i++)
		pq1.push(i + 1);//procesoare libere
	for (int i = 0; i < m; i++)
	{
		while (!pq2.empty()&&pq2.top().second<=task[i].first) {
			pq1.push(pq2.top().first);
			pq2.pop();
		}
		rasp[task[i].second.second] = pq1.top();
		pq2.push({ pq1.top(),task[i].second.first });//proc, se termina
		pq1.pop();
	}
	for (int i = 0; i < m; i++)
		g << rasp[i] << "\n";


}
