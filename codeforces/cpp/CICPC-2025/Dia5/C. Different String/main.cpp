#include <bits/stdc++.h>
using namespace std;
string sortString(string &s)
{
    string r;
    // Count array to keep count of characters
    int charCount[26] = {0};

    // Traverse string and increment count of characters
    for (int i = 0; i < s.length(); i++)
    {

        // 'a'-'a' will be 0, 'b'-'a' will be 1, etc.
        charCount[s[i] - 'a']++;
    }

    // Traverse the hash array
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < charCount[i]; j++)
        {
            r += (char)('a' + i);
        }
    }
    return r;
}
// string sortRandomString(string s ){

//     random_shuffle(s.begin(),s.end());
// }
int main()
{

    // Your code here
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        string aux = s;

        map<char, int> m;
        char c0 = s[0];
        char c1;
        // falta colocar cuando el string es palindromo
        for (int i = 0; i < s.size(); i++)
        {
            if (c0 != aux[i])
            {
                c1 = aux[i];
            }
            m[aux[i]] += 1;
        }

        if (m.size() > 1)
        {
            cout << "YES" << endl;
            string temp = s;
            while (temp == s)
            {
                temp = s;
                random_shuffle(temp.begin(), temp.end());
            }
            cout << temp;
        }
        else
        {
            cout << "NO";
        }

        cout << endl;
    }

    return 0;
}