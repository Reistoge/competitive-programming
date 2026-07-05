#include <bits/stdc++.h>
using namespace std;

// Find shortest suffix that contains all unique elements of the current array
int find_shortest_suffix_start(const vector<int>& arr, int start) {
    unordered_set<int> all_unique(arr.begin() + start, arr.end()); // hasmap valores unicos
    unordered_set<int> seen;

    for (int i = arr.size() - 1; i >= start; --i) {
        seen.insert(arr[i]); // añadir valores vistos al hashmap
        if (seen.size() == all_unique.size()) {
            return i; // return starting index of the suffix
        }
    }
    return start; // fallback
}

int main() {
    // COPIA EL CODIGO PA RECIBIR LOS INPUTS ACA
    vector<int> arr ={1,2,2,3,1,5};
    // Y ACA
    
    int count = 0;
    int start = 0;

    while (start < arr.size()) {
        int suffix_start = find_shortest_suffix_start(arr, start); // buscamos el.sufijo en el subarray desde begin hasta el comienzo del sufijo previo
        count++;
        start = suffix_start + 1;
    }

    cout << count << endl;

    return 0;
}
