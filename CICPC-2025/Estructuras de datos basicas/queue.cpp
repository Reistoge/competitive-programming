#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    queue<int> cola;
    cola.push(1);
    cola.push(2);
    cout << cola.front() << endl; // imprime 1
    cola.pop();
    cout << cola.front() << endl; // imprime 2

    //  FIFO: Primero en entrar, primero en salir
    //  Operaciones principales:
    //  push()
    //  pop()
    //  front()
    //  back()
    //  empty()

    return 0; // Return 0 to indicate successful execution
}