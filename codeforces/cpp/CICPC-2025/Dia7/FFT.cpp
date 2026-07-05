#include <bits/stdc++.h>
using namespace std;
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

int inverse(int a, int m)
{
    return a <= 1 ? a : m - (long long)(m / a) * inverse(m % a, m) % m;
}
void fft(vector<int> &a, bool invert)
{
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len)
        {
            int w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert)
    {
        int n_1 = inverse(n, mod);
        for (int &x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

int main()
{
    vector<int> p1 = {1, 2};
    vector<int> p2 = {2,3};
    vector<int> p3 = multiply(p1,p2);
    for (auto &x : p3)
    {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}