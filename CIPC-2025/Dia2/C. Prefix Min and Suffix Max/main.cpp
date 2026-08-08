#include <bits/stdc++.h>
using namespace std;

template <class T, T mergeMin(T, T)>
struct SegmentTreeMin
{
    int n;
    vector<T> tree;

    SegmentTreeMin() {}
    SegmentTreeMin(vector<T> &values)
    {
        n = values.size();
        tree.resize(n << 1);

        for (int i = 0; i < n; i++)
            tree[i + n] = values[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = mergeMin(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int position, T value)
    {
        position += n;
        tree[position] = value;

        for (position >>= 1; position > 0; position >>= 1)
            tree[position] = mergeMin(tree[position << 1], tree[position << 1 | 1]);
    }

    T query(int left, int right) // [left, right]
    {
        bool hasAnswer = false;
        T answer = T();

        for (left += n, right += n + 1; left < right; left >>= 1, right >>= 1)
        {

            if (left & 1)
            {
                answer = hasAnswer ? mergeMin(answer, tree[left]) : tree[left];
                hasAnswer = true;
                left++;
            }

            if (right & 1)
            {
                right--;
                answer = hasAnswer ? mergeMin(answer, tree[right]) : tree[right];
                hasAnswer = true;
            }
        }

        return answer;
    }
};
int mergeMin(int a, int b)
{
    return min(a, b);
}
template <class T, T mergeMax(T, T)>
struct SegmentTreeMax
{
    int n;
    vector<T> tree;

    SegmentTreeMax() {}
    SegmentTreeMax(vector<T> &values)
    {
        n = values.size();
        tree.resize(n << 1);

        for (int i = 0; i < n; i++)
            tree[i + n] = values[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = mergeMax(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int position, T value)
    {
        position += n;
        tree[position] = value;

        for (position >>= 1; position > 0; position >>= 1)
            tree[position] = mergeMax(tree[position << 1], tree[position << 1 | 1]);
    }

    T query(int left, int right) // [left, right]
    {
        bool hasAnswer = false;
        T answer = T();

        for (left += n, right += n + 1; left < right; left >>= 1, right >>= 1)
        {

            if (left & 1)
            {
                answer = hasAnswer ? mergeMax(answer, tree[left]) : tree[left];
                hasAnswer = true;
                left++;
            }

            if (right & 1)
            {
                right--;
                answer = hasAnswer ? mergeMax(answer, tree[right]) : tree[right];
                hasAnswer = true;
            }
        }

        return answer;
    }
};
int mergeMax(int a, int b)
{
    return max(a, b);
}

int main()
{
    // Your code here
    int t = 0, n = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
     
        cin >> n;
        vector<int> values(n);
        for (int i = 0; i < n; i++)
        {
            int v = 0;
            cin >> v;
            values[i] = v;
        }
        SegmentTreeMax<int, mergeMax> segmentTreeMax(values);
        SegmentTreeMin<int, mergeMin> segmentTreeMin(values);
        
        // 1 3 5 4 7 2
        // 1 1 1 1 1 1
        // 7 7 7 7 7 2
        
        
        for (int i = 0; i <n; i++)
        {
            int v=values[i];
            int p= segmentTreeMin.query(0,i);
            int s = segmentTreeMax.query(i,n-1);
            if(v==p || v==s){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0; // Return 0 to indicate successful execution
}