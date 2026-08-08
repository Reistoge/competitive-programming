#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["gato"] = 3;
    mp["perro"] = 5;
    // acceso con []
    cout << mp["gato"] << endl; // imprime 3
    // acceso con find
    auto it = mp.find("perro");
    if (it != mp.end())
        cout << "perro tiene valor: " << it->second << endl;
    mp.erase("gato"); // elimina la clave "gato"
    if (!mp.count("gato"))
        cout << "gato ya no está" << endl;

        
    // Your code here
    // Diccionario clave → valor ordenado
    // Operaciones:
    //  - insert()
    //  - erase()
    //  - find()
    //      → devuelve un iterador al elemento x si está, o end() si no está.
    //  - []
    //      → accede al valor de una clave (y la crea si no existe)
    //  - lower_bound(clave)
    //      → iterador al primer par con clave ≥ clave dada.
    //  - upper_bound(clave)
    //      → iterador al primer par con clave > clave dada.
    // Complejidad: O(log n)
    // Usos comunes:
    //  - Contar frecuencias
    //  - Asociar información a claves

    return 0; // Return 0 to indicate successful execution
}