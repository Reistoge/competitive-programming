//https://codeforces.com/group/TY5qlgX1RN/contest/624645/problem/K

#include <bits/stdc++.h>
using namespace std;
    int sets[13][3] = {
        {0, 1, 2},
        {0, 4, 9},
        {0, 5, 8},
        {0, 6, 7},
        {1, 3, 9},
        {1, 4, 8},
        {1, 5, 7},
        {2, 3, 8},
        {2, 4, 7},
        {2, 5, 6},
        {3, 4, 6},
        {3, 6, 4},
        {6, 8, 9}
    };
    int setsR[9][2] = {
        {0, 3},
        {2, 9},
        {3, 7},
        {4, 5},
        {5, 3},
        {6, 1},
        {7, 9},
        {8, 7},
        {9, 5},
    };
int main() {


    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N = 0;
        cin >> N;
        int arr[10] = {0};
        bool solved = false;
        
        for (int j = 0; j < N; j++) {
            int a = 0;
            cin >> a;
            string aux = to_string(a);
            // a = aux[aux.length()-1]-48;
            a = stoi(aux.substr(aux.length()-1, 1));
            arr[a]++;
            if (arr[1] == 3) {
                solved = true;
                j = N;
            }
         
        }

        if (!solved) {
            for (int s = 0; s < 9; s++) {
                if (arr[setsR[s][0]] >= 2 and arr[setsR[s][1]] > 0) {
                    solved = true;
                    s = 9;
                }
            }
            if (!solved) {
                for (int s1 = 0; s1 < 13; s1++) {
                    if (arr[sets[s1][0]] > 0 and arr[sets[s1][1]] > 0 and arr[sets[s1][2]] > 0) {
                        solved = true;
                        s1 = 13;
                    }
                }
            }
        }

        if (solved) {cout << "YES" << endl; }
        else {cout << "NO" << endl; }
    }
    return 0;
}