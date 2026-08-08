#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1734

#include <bits/stdc++.h>
using namespace std;

/* Segment Tree
 *Description:* Range queries, build $O(n)$, query and update $O(log n)$, positions [0, n - 1]
 *Status:* Highly tested
 */
template <class T, T m_(T, T)>
struct segment_tree
{
    long long n;
    vector<T> ST;
    segment_tree() {}
    segment_tree(vector<T> &a)
    {
        n = a.size();
        ST.resize(n << 1);
        for (long long i = n; i < (n << 1); i++)
            ST[i] = a[i - n];
        for (long long i = n - 1; i > 0; i--)
            ST[i] = m_(ST[i << 1], ST[i << 1 | 1]);
    }
    void update(long long pos, T val)
    { // replace with val
        ST[pos += n] = val;
        for (pos >>= 1; pos > 0; pos >>= 1)
            ST[pos] = m_(ST[pos << 1], ST[pos << 1 | 1]);
    }
    T query(long long l, long long r)
    { // [l, r]
        T ansL, ansR;
        bool hasL = 0, hasR = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansL = (hasL ? m_(ansL, ST[l++]) : ST[l++]), hasL = 1;
            if (r & 1)
                ansR = (hasR ? m_(ST[--r], ansR) : ST[--r]), hasR = 1;
        }
        if (!hasL)
            return ansR;
        if (!hasR)
            return ansL;
        return m_(ansL, ansR);
    }
};
long long merge(long long a, long long b)
{
    return a+b;
}

int main()
{
    long long n,q;
    cin >> n >> q;
    
    vector<long long > nums(n);
    vector<long long > ans(n);
    for(long long &a: nums) cin >> a;
    vector<vector<long long>> Q(q);
    for (int  i = 0; i < Q; i++)
    {
        long long l, r; cin >> l >> r;
        l--; r--;
        Q[i] = {l,r,i};

    }
    sort<long long , long long> pos;
    vector<long long> temp(n,0);
    segment_tree<long long, merge> st(temp);
    long long pos_p = n;

    for(auto v : Q){
        long long l = v[0], r = v[1], i = v[2];
        while(pos_p > l){
            pos_p --;
            if(pos.count(nums[pos_p])){
                st.update(pos[nums[pos_p]],0);
                pos[nums[pos_p]] = pos_p;
                st.update(pos_p,1);
            }else{
                pos[nums[pos_p]] =pos_p;
                st.update(pos_p,1);
            }
        }
        ans[i] = st.query(l,r);
        cout << ans[i]<<endl;

    }
 
    
    
    return 0;
}
 