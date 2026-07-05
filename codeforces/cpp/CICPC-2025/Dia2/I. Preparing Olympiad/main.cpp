#include <bits/stdc++.h>
using namespace std;

template <class T, T sumMerge(T, T)>
struct SegmentTreeSum
{
    int n;
    vector<T> tree;

    SegmentTreeSum() {}
    SegmentTreeSum(vector<T> &values)
    {
        n = values.size();
        tree.resize(n << 1);

        for (int i = 0; i < n; i++)
            tree[i + n] = values[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = sumMerge(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int position, T value)
    {
        position += n;
        tree[position] = value;

        for (position >>= 1; position > 0; position >>= 1)
            tree[position] = sumMerge(tree[position << 1], tree[position << 1 | 1]);
    }

    T query(int left, int right) // [left, right]
    {
        bool hasAnswer = false;
        T answer = T();

        for (left += n, right += n + 1; left < right; left >>= 1, right >>= 1)
        {

            if (left & 1)
            {
                answer = hasAnswer ? sumMerge(answer, tree[left]) : tree[left];
                hasAnswer = true;
                left++;
            }

            if (right & 1)
            {
                right--;
                answer = hasAnswer ? sumMerge(answer, tree[right]) : tree[right];
                hasAnswer = true;
            }
        }

        return answer;
    }
};
int sumMerge(int a, int b)
{
    return a + b;
}
template <class T, T minMerge(T, T)>
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
            tree[i] = minMerge(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int position, T value)
    {
        position += n;
        tree[position] = value;

        for (position >>= 1; position > 0; position >>= 1)
            tree[position] = minMerge(tree[position << 1], tree[position << 1 | 1]);
    }

    T query(int left, int right) // [left, right]
    {
        bool hasAnswer = false;
        T answer = T();

        for (left += n, right += n + 1; left < right; left >>= 1, right >>= 1)
        {

            if (left & 1)
            {
                answer = hasAnswer ? minMerge(answer, tree[left]) : tree[left];
                hasAnswer = true;
                left++;
            }

            if (right & 1)
            {
                right--;
                answer = hasAnswer ? minMerge(answer, tree[right]) : tree[right];
                hasAnswer = true;
            }
        }

        return answer;
    }
};
int minMerge(int a, int b)
{
    return min(a, b);
}
template <class T, T maxMerge(T, T)>
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
            tree[i] = maxMerge(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int position, T value)
    {
        position += n;
        tree[position] = value;

        for (position >>= 1; position > 0; position >>= 1)
            tree[position] = maxMerge(tree[position << 1], tree[position << 1 | 1]);
    }

    T query(int left, int right) // [left, right]
    {
        bool hasAnswer = false;
        T answer = T();

        for (left += n, right += n + 1; left < right; left >>= 1, right >>= 1)
        {

            if (left & 1)
            {
                answer = hasAnswer ? maxMerge(answer, tree[left]) : tree[left];
                hasAnswer = true;
                left++;
            }

            if (right & 1)
            {
                right--;
                answer = hasAnswer ? maxMerge(answer, tree[right]) : tree[right];
                hasAnswer = true;
            }
        }

        return answer;
    }
};
int maxMerge(int a, int b)
{
    return max(a, b);
}

int main()
{
    // Your code here
    int n = 0, l = 0, r = 0, x = 0;
    // n, the minimum and maximum value of total difficulty of the problemset and the minimum difference in difficulty between the hardest problem in the pack and the easiest one.
    cin >> n >> l >> r >> x;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        int v = 0;
        cin >> v;
        values[i] = v;
    }

    SegmentTreeMin<int, minMerge> mins(values);
    SegmentTreeMax<int, maxMerge> maxs(values);
    SegmentTreeSum<int, sumMerge> sums(values);
    for (int i = 0; i < mins.tree.size(); i++)
    {
        cout << mins.tree[i] << " ";
    }
    cout <<endl;
    for (int i = 0; i < maxs.tree.size(); i++)
    {
        cout << maxs.tree[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < mins.tree.size(); i++)
    {
        cout << sums.tree[i] << " ";
    }
    cout << endl;


    return 0; // Return 0 to indicate successful execution
}