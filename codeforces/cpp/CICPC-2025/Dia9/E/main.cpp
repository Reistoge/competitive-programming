#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    unordered_map<int, int> um;
    set<int> s;
    vector<int> arr(n);
    vector<int> ans;
    for (int &x : arr) cin >> x;

    for (int i = n-1; i >= 0; i--)
    {
        if(!s.count(arr[i])) {
            ans.push_back(arr[i]);
            s.insert(arr[i]);
        }
        
    }
    cout << ans.size() << endl;
    for (int i = ans.size(); i > 0; i--)
    {
        cout << ans[i-1] << " ";
    }
    
    
  


    

    return 0;
}