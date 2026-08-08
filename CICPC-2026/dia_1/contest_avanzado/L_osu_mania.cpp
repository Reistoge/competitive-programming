#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        //lectura inicial del n y defino mi array pa guardarlos (memo si o si jeje)
        int n; cin >> n;
        stack<int> orden;

        for(int j = 0; j < n; j++) {
            string osu; cin >> osu;
            for(int k = 0; k < 4; k++) {
                if(osu[k] == '#') {
                    orden.push(k+1);
                    break;
                }
            }
        }

        while(!orden.empty()) {
            cout << orden.top() << " ";
            orden.pop();
        }
    cout << endl;
    }
}
