#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int c =0;
    cin >> n;
    vector<int> p(n);
    vector<int> swaps1;
    vector<int> swaps2;
    vector<int> index(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        index[p[i]]=i;
    }
    for (int i = 0; i < n-1; i++) {
        int min_idx = index[i+1];
        int min = i+1;

        if (i != min_idx) {
            if (abs(i-min_idx)*2 >= n) {
                // cout << i+1 << " " << min_idx+1 << endl;
                swaps1.push_back(i+1);
                swaps2.push_back(min_idx+1);
                c++;

            } else if (min_idx+1 <= n/2) {
    
                swaps1.push_back(min_idx+1);
                swaps2.push_back(n);
    
                swaps1.push_back(i+1);
                swaps2.push_back(n);
    
                swaps1.push_back(min_idx+1);
                swaps2.push_back(n);
    
                c += 3;
    
            } else if (i+1 > n/2) {
    
                swaps1.push_back(i+1);
                swaps2.push_back(1);
    
                swaps1.push_back(min_idx+1);
                swaps2.push_back(1);
    
                swaps1.push_back(1);
                swaps2.push_back(i+1);
    
                c += 3;
    
            } else {
    
                swaps1.push_back(i+1);
                swaps2.push_back(n);
    
                swaps1.push_back(1);
                swaps2.push_back(n);
    
                swaps1.push_back(1);
                swaps2.push_back(min_idx+1);
    
                swaps1.push_back(1);
                swaps2.push_back(n);
    
                swaps1.push_back(i+1);
                swaps2.push_back(n);
                c += 5;
            }
            swap(p[i], p[min_idx]);
            swap(index[p[i]], index[p[min_idx]]);
        }

    }
    cout << c << endl;
    for (int i = 0; i < c; i++) {
        cout << swaps1[i] << ' ' << swaps2[i] << endl;
    }

    return 0; 
}