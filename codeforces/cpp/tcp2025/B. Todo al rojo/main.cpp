#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int largo, casos;
    string ruleta;
    cin >> largo >> casos >> ruleta;

    vector<bool> patron;

    for (int i = 0; i < largo; i++)
    {
        bool isRed;
        string respuesta;

        cout << "ROJO" << endl;
        cin >> respuesta;
        if (respuesta == "GANASTE")
        {

            isRed = true;

            patron.push_back(isRed);
        }
        else
        {

            isRed = false;
            patron.push_back(isRed);
        }
    }
    int j = 0;
    string caca;
    // cout<< "PATRON"; 
    // for(auto i : patron){
    //     cout << i << " ";
    // }
    for (int i = 0; i < casos - largo; i++)
    {

        if (j >= patron.size())
        {
            j = 0;
        }
        string s = (patron[j] == 0) ? "NEGRO" : "ROJO";
        cout << s << endl
        << flush;
        cin >> caca;
        j++;
    }
}