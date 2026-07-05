#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    stack<int> pila;
    pila.push(7);
    pila.push(5);
    pila.push(10);
    cout << pila.top() << endl; // imprime 10
    pila.pop();
    cout << pila.top() << endl; // imprime 5
    return 0;                   // Return 0 to indicate successful execution

    //  LIFO: Último en entrar, primero en salir
    //  Operaciones principales:
    //  push()
    //  → agregar
    //  pop()
    //  → quitar
    //  top()
    //  → acceder al tope
    //  empty()
    //  → verificar si está vacía
}