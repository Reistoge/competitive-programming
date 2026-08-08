#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Estructura para poder usar pair en un unordered_set de forma ultra rápida
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

int main() {
    // Optimización de entrada/salida para evitar TLE
    
    string s;
    if (!(cin >> s)) return 0;

    string good;
    cin >> good;

    int k;
    cin >> k;

    int n = s.size();

    // Guardamos un par de hashes por cada substring para asegurar unicidad por tamaño y contenido
    unordered_set<pair<ll, ll>, pair_hash> goods;

    vector<bool> is_good(26);
    for (int i = 0; i < 26; i++) {
        is_good[i] = (good[i] == '1');
    }

    // Dos bases y dos módulos para evitar colisiones cruzadas de longitudes
    const ll B1 = 67, M1 = 1e9 + 7;
    const ll B2 = 71, M2 = 1e9 + 9;

    vector<ll> P1(n + 1, 1), P2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        P1[i] = (P1[i - 1] * B1) % M1;
        P2[i] = (P2[i - 1] * B2) % M2;
    }

    for (int w = 1; w <= n; w++) {
        int bad_count = 0;  
        ll hash1 = 0;
        ll hash2 = 0;
      
        for (int i = 0; i < w; i++) {
            if (!is_good[s[i] - 'a']) {
                bad_count++;
            }
            hash1 = (hash1 * B1 + s[i]) % M1;
            hash2 = (hash2 * B2 + s[i]) % M2;
        }

        for (int i = 0; i + w <= n; i++) {
            if (bad_count <= k)
                goods.insert({hash1, hash2});

            if (i + w == n) break;

            // Actualización del Hash 1
            ll char_to_remove1 = (s[i] * P1[w - 1]) % M1;
            hash1 = (hash1 + M1 - char_to_remove1) % M1;
            hash1 = (hash1 * B1 + s[i + w]) % M1;

            // Actualización del Hash 2
            ll char_to_remove2 = (s[i] * P2[w - 1]) % M2;
            hash2 = (hash2 + M2 - char_to_remove2) % M2;
            hash2 = (hash2 * B2 + s[i + w]) % M2;

            if (!is_good[s[i] - 'a'])
                bad_count--;

            if (!is_good[s[i + w] - 'a'])
                bad_count++;
        }
    }

    cout << goods.size() << endl;

    return 0;
}
