//https://www.infoarena.ro/problema/bleach
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;
ifstream f("bleach.in");
ofstream g("bleach.out");
typedef long long ll;
int n, k;
int x;
priority_queue<int>pq;
int main()
{
    int putere;
    ll curent;
    f >> n>>k;
    for (int i = 0; i < k+1; i++) {
        f >> x;
        pq.push(x*(-1));
    }
    putere = pq.top()*(-1);
    curent = putere*2;
    pq.pop();
    for (int i = k+1; i < n; i++)
    {
        f >> x;
        pq.push(x * (-1));
        if (curent < (-1)*pq.top())
        {
            putere += ((-1) * pq.top() - curent);
            curent = 2 * (-1) * pq.top();
        }
        else {
            curent += (-1) * pq.top();
        }
        pq.pop();
    }
    while (!pq.empty()) {
        if (curent < (-1) * pq.top())
        {
            putere += ((-1) * pq.top() - curent);
            curent = 2 * (-1) * pq.top();
        }
        else {
            curent += (-1) * pq.top();
        }
        pq.pop();
    }
    g << putere;
   
}