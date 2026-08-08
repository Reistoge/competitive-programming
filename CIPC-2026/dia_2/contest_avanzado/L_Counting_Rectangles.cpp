#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
// ------- *** MAIN *** ------- //
int main() {
    int t;
    cin >> t;
    while (t--) {
      ll matrix[1001][1001] = {0};
      ll prefix[1001][1001] = {0};
      int totalFig, pruebas; cin >> totalFig >> pruebas; //contadores figuras yy casos d prueba

      for(int j = 0; j < totalFig; j++) {
          int largo, ancho; cin >> largo >> ancho;
          matrix[largo][ancho] += largo * ancho; //llenando la matriz con el area de cada figura
      }

      for(int h = 1; h < 1001; h++) {
        for(int w = 1; w < 1001; w++) {
          prefix[h][w] = matrix[h][w] + prefix[h - 1][w] + prefix[h][w - 1] - prefix[h - 1][w - 1];
        }
      }

      for(int j = 0; j < pruebas; j++) {
          int largoChico, anchoChico, largoGrande, anchoGrande;
          cin >> largoChico >> anchoChico >> largoGrande >> anchoGrande;

          ll totalQuery = prefix[largoGrande-1][anchoGrande-1] - prefix[largoChico][anchoGrande-1] - prefix[largoGrande-1][anchoChico] + prefix[largoChico][anchoChico];
          cout << totalQuery << endl;
        }
    }
    return 0;
}