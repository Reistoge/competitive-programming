#include <bits/stdc++.h>
using namespace std;
void print(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
bool checkIsCool(priority_queue<int> &pq1, priority_queue<int> &pq2, int n1, int n2)
{
    int s1 = n1;
    int s2 = n2;
    if(s1 == s2){
        if(pq1.top() <= pq2.top()){
            pq2.pop();
            n2--;
        }
        else{
            pq1.pop();
            n1--;
        }
    }
    while (n1 > 0)
    {
        if (pq1.top() != pq2.top())
        {
            pq1.pop();
            n1--;
        }
        else
        {
            pq1.pop();
            pq2.pop();
            n1--;
            n2--;
            if (n2 == 0)
            {
                return true;
            }
        }
    }

 
 

    return false;
}
int main()
{
    // Create empty priority queue
    int t = 0, n = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        vector<int> v(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        int l = 1;
        priority_queue<int> r;
        r.push(1);
        while (l < n)
        {
            
            bool cool = false;
            priority_queue<int> pq1(v.begin(), v.begin() + l);
            priority_queue<int> pq2(v.begin() + l, v.end());
            // cout << "before" << endl;
            // print(pq1);
            // cout << endl;
            // print(pq2);
            // cout << endl;
            // bool cool = false;
            if (n - l > l)
            {
                cool = checkIsCool(pq2, pq1, n - l, l);
                if (cool)
                {
                    r.push(l);
                }
            }
            else if (n - l <= l)
            {
                cool = checkIsCool(pq1, pq2, l, n - l);
                if (cool)
                {
                    r.push(n - l);
                }
            }

            // cout << "after " << endl;
            // print(pq1);
            // cout << endl;
            // print(pq2);
            // cout << endl;
            // cout << "cool :" << cool << endl;
            l++;
        }
        cout << r.top() << endl;
    }

    return 0;
}