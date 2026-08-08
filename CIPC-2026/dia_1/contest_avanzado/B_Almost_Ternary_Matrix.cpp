#include <bits/stdc++.h>
using namespace std;


int main() {

	int t;
	int n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<int>> v(n,vector<int>(m,0));

		bool c1 = false;
		for(int i = 0; i < n; i=i+2) {
			//cout << "i: "<< i << " ";
			if(c1) {
				// put base case 1
				bool c2 = false;
				for(int j = 0; j < m; j=j+2) {
					//cout << j << " ";
					if(c2) {
						v[i][j] = 1;
						v[i][j+1] = 0;
						v[i+1][j+1]=1;
						v[i+1][j] = 0;

					} else {
						v[i][j] = 0;
						v[i][j+1] = 1;
						v[i+1][j+1]=0;
						v[i+1][j] = 1;

					}
					c2 = !c2;
				}


			}
			else {
				bool c3 = true;
				for(int j = 0; j < m;  j=j+2) {
					// put base case 1
					//cout << j << " ";
					if(c3) {
						v[i][j] = 1;
						v[i][j+1] = 0;
						v[i+1][j+1]=1;
						v[i+1][j] = 0;

					} else {
						v[i][j] = 0;
						v[i][j+1] = 1;
						v[i+1][j+1]=0;
						v[i+1][j] = 1;

					}
					c3=!c3;
				}

			}
			// cout << endl;
			c1 = !c1;

		}
		for(auto rows : v) {
			for(auto col : rows) {
				cout << col << " ";
			}
			cout << endl;
		}

	}





}
