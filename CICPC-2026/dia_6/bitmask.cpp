#include <bits/stdc++.h>
using namespace std;

int main() {
    // set a specific bit
    // integer | (1 << bit_position_to_be_set)
    cout << (1 | (1 << 2)) << endl; // 0 0 1 << 1 0 0 -> 1 0 1 ---> 5

    // clearing a bit
    // integer & ~ (1 << bit_position_to_clear)

    cout << (5 & ~(1 << 2)) <<endl; // 1 0 1 << 1 0 0  --> 0 0 1 -> 1


    // toggling a bit
    // integer ^ (1 << bit_position_to_toggle)

    cout << (5 ^ (1 << 1)) << endl; // 1 0 1 << 0 1 0 -> 1 1 1 --> 7
    

    // cout << (('aa' ^ 'aaa') + 'a') << endl;
    for (int i = 0; i < 128; i++)
    {
        cout << (char)(i)<< " ";
    }
    
    
    return 0; 
}