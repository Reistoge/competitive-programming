    for (int i = 1; i < n+1; i++)
    {  
        int s = 0;
        for (auto it : m)
        {
            if(it.first.first == i){
                s++;
            }
            cout << s << " ";
        }
        
        
    }