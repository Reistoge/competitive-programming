#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    cout << dq.front() << endl; // imprime 2
    cout << dq.back() << endl;  // imprime 1
    
    // Your code here
    //     Permite insertar y eliminar por ambos extremos en O(1)
    //  Combina propiedades de
    // stack
    //  y
    // queue
    //  Operaciones:
    // -> push_back()
    //
    //  ->push_front()
    //
    // Acceso por índice: dq[i]
    //  -> pop_back()
    //
    // -> pop_front()
    return 0; // Return 0 to indicate successful execution
}