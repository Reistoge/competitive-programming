#include <bits/stdc++.h>
 
using namespace std;

const int MAX_CHAR = 26;

string sortStringInc(string s)
{

    int charCount[MAX_CHAR] = {0};
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        //cout << charCount[s[i] - 'a'] + 1 ;
        charCount[s[i] - 'a']++;
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        for (int j = 0; j < charCount[i]; j++)
        {
            res += (char)('a' + i);
        }
    }
    
    return res;
}

 




int main()
{

    cout <<  sortStringInc("zxycda");
    return 0;
    int n=0;
    int q=0;
    string s="";
    cin >> n>>q;
    cin >> s;
    for(int i =0;i<q;i++) {
        int j = 0;
        int k = 0;
        int order = 0;
        cin >>j;
        cin >>k;
        cin >> order;
        string stringToSort = s.substr(j-1,k-j+1);
        //cout << stringToSort<< " ";
        string left=s.substr(0,j-1);
        //cout << left<< " ";
        string right = s.substr(k,s.size()-k);
        // cout << right<<  " ";
  
        string partiallySorted = sortStringInc(stringToSort);
        //cout << partiallySorted<< " ";
        if(order == 0){
            reverse(partiallySorted.begin(),partiallySorted.end());
        }
        
        s = left + partiallySorted + right;
         
        //cout << s << endl;
        
    }
    cout << s;
 
   
     

    return 0;  
}