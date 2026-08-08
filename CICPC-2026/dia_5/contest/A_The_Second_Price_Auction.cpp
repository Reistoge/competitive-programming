#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<tuple<int, int, int>> pq;
    int n = 0, k = 0;
    cin >> n;
    cin >> k;
    // cout << (int)(pow(10,5) * pow(10,4)) + 1<< endl;

    for (int i = 0; i < n; i++)
    {
        int qi;
        int bi;
        cin >> qi;
        cin >> bi;
        tuple<int, int, int> t = make_tuple(qi * bi, i, qi);
        pq.push(t);
    }
    if (get<0>(pq.top()) == 0)
    {
        cout << "AUCTION EMPTY";
    }
    else
    {
        while (k && !pq.empty())
        {

            auto high = pq.top();
            auto high_mult = get<0>(high);

            if(high_mult <=0){
                break;
            }
            pq.pop();
            if (pq.empty())
            {
                cout << get<1>(high) + 1 << " " << 1 << endl;
                break;
            }

            auto next = pq.top();
            int calc = (ceil(get<0>(next) / get<2>(high)) + 1);
            cout << get<1>(high) + 1 << " " << calc << endl;
            k--;
        }
    }

    return 0;
}