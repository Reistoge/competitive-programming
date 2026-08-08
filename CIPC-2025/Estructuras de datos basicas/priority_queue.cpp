#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Priority queue default (devuelve mayor)
    priority_queue<int> pq1;
    pq1.push(3);
    pq1.push(8);
    pq1.push(1);
    cout << pq1.top() << endl; // imprime 8
    pq1.pop();
    cout << pq1.top() << endl; // imprime 3

    // Priority queue que devuelve menor
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(3);
    pq2.push(8);
    pq2.push(1);
    cout << pq2.top() << endl; // imprime 1
    pq2.pop();
    cout << pq2.top() << endl; // imprime 3
    
    // Siempre devuelve el mayor o menor elemento.
    //  Operaciones:
    //  -> push()
    //  -> pop()
    //  Usos comunes:
    //  -> top()
    //  -> empty()
    //  Seleccionar el mayor o el más importante

    // Complejidad: O(log n)

    return 0; // Return 0 to indicate successful execution
}