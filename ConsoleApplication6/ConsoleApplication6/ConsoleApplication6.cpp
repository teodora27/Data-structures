//https://codeforces.com/gym/103999/problem/M
#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;
typedef long long ll;
int n;
int main()
{
    cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    stack<ll>s;
    vector<ll>stg(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[i] <= v[s.top()])
            s.pop();
        if (s.empty())
            stg[i] = 0;
        else
            stg[i] = s.top() + 1;
        s.push(i);
    }
    /*for (int i = 0; i < n; i++)
        cout << stg[i] << " ";
    cout << "\n";*/
    vector<ll>dr(n);
    s = stack<ll>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && v[i] < v[s.top()])
            s.pop();
        if (s.empty())
            dr[i] = n - 1;
        else
            dr[i] = s.top() - 1;
        s.push(i);
    }
    /*for (int i = 0; i < n; i++)
        cout << dr[i] << " ";
    cout << "\n";*/

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll sim = 2 * i - dr[i];//simetricul lui dr fata de i
        if (stg[i] < sim)
            sum += (sim - stg[i]) * (dr[i] - i + 1);
        //cout << sum << "\n";
        sum += (i - max(stg[i], sim) + 1) * (i - max(stg[i], sim)) / 2;
        //cout << i << " " << sum << "\n";
    }
    cout << sum;

}
/*


10+eps 46+2*eps 10+3*eps 10+4*eps 320+5*eps 10+6*eps

 7 7 7 7 3 7 8 3 10 3 19 20 6 7
 [       ] 
 [                ] 
 [                  ]        
a[i] = a[j]
i

10 3 4 10 3 5 3  53  5 3 6 234 453445 635245 6

6 6 6 6 6 6 6 6 
 
---i---
--i--

dr[i]-i
dr[i]-i-1
dr[i]-i-2
...
1
(dr[i]-i+1)*(dr[i]-i)/2
*/
