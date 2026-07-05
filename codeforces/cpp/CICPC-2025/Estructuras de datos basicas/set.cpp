#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<int> s;
    s.insert(4);
    s.insert(2);
    s.insert(4); // no se repite
    // usando count: devuelve 1 si está, 0 si no
    if (s.count(2))
        cout << "Está el 2" << endl;
    s.erase(2); // eliminar el 2
    // usando find: devuelve iterador al elemento, o s.end() si no está
    auto it = s.find(2);
    if (it != s.end())
        cout << "Está el 2, valor: " << *it << endl; // con *it se accede al elemento
    if (!s.count(2))                                 // revisar que ya no está
        cout << "El 2 ya no está" << endl;
        
    // Conjunto ordenado y sin repetidos
    // Operaciones:
    //   insert()         // Inserta un elemento
    //   erase()          // Elimina un elemento
    //   count()          // Devuelve 0 o 1 dependiendo de si está o no
    //   find()           // Devuelve un iterador al elemento x si está, o end() si no está
    //   lower_bound(x)   // Iterador al primer elemento ≥ x, o end() si no hay
    //   upper_bound(x)   // Iterador al primer elemento > x, o end() si no hay
    // Complejidad: O(log n)
    // Existe también multiset, que hace lo mismo pero permite elementos repetidos
    return 0; // Return 0 to indicate successful execution
}