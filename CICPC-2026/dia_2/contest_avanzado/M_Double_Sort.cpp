    #include <bits/stdc++.h>
    #include <cmath>
    using namespace std;
    typedef long long ll;


bool selectionSort(vector<int> arrA, vector<int> arrB, int n) {
    // Loop through the array up to the second-to-last element
    vector<pair<int, int>> swaps;

    for (int i = 0; i < n - 1; i++) {
        // Assume the current index holds the minimum value
        int min_idx = i;
        
        // Loop through the remaining unsorted portion
        for (int j = i + 1; j < n; j++) {
            // Change '>' to '<' to sort the array in descending order
            if (arrA[j] < arrA[min_idx]) {
                min_idx = j;
            } if (arrA[j] == arrA[min_idx] && arrB[j] < arrB[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            swap(arrA[i], arrA[min_idx]);
            swap(arrB[i], arrB[min_idx]);
            swaps.push_back({i, min_idx});
        }
    }
    if (is_sorted(arrB.begin(), arrB.end())) {
        cout << swaps.size() << endl;
        for (const auto& swap_pair : swaps) {
            cout << swap_pair.first + 1 << " " << swap_pair.second + 1 << endl; // +1 for 1-based indexing
        }
        return true;
    } else {
        return false;
    }
}

// ------- *** MAIN *** ------- //
int main() {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<int> a(n);
      vector<int> b(n);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }
      for (int i = 0; i < n; i++) {
        cin >> b[i];
      }

      bool foo = selectionSort(a, b, n);
      if (foo == false) {
        foo = selectionSort(b, a, n);
      }
      if (foo == false) {
        cout << -1 << endl;
      }


    }
    return 0;
}