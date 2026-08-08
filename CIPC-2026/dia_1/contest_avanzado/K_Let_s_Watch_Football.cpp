#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, cargaTemp, total;
    cin >> a >> b >> c;
    cargaTemp = b*c;
    total = (a*c)-cargaTemp;
    cout << ceill(total/b);
}
