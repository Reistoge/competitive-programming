#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ej con set
    set<int> s = {2, 4, 6};
    auto it = s.begin(); // apunta al 2
    cout << *it << endl; // imprime 2
    ++it;                // apunta ahora al 4
    cout << *it << endl; // imprime 4

    // ej con map
    map<string, int> m = {{"a", 1}, {"b", 2}};
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    } // printearía "a - > 1"...

    /*
        Los contenedores como set y map devuelven iteradores.
        Un iterador es como un puntero: se puede avanzar, retroceder y acceder al valor apuntado.
            Operaciones comunes:
                ++it / --it : avanzar o retroceder
                *it : acceder al valor (clave o par clave→valor)
                it != contenedor.end() : verificar si el iterador está en el contenedor
    */

    return 0; // Return 0 to indicate successful execution
}