/*
 * C++ Program to Implement Z-Algorithm
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define ll long long
bool zalgo(string pat, string tar)
{
    string s = pat + '$' + tar;
    ll n = s.length();
    vector<ll> z(n, 0);
    ll goal = pat.length();
    ll r = 0, l = 0, i;
    for (ll k = 1;  k < n; k++)
    {
        if (k > r)
        {
            for (i = k; i < n && s[i] == s[i - k]; i++);
            if (i > k)
            {
                z[k] = i - k;
                l = k;
                r = i - 1;
            }
        }
        else
        {
            ll kt = k - l, b = r - k + 1;
            if (z[kt] > b)
            {
                for (i = r + 1; i < n && s[i] == s[i - k]; i++);
                z[k] = i - k;
                l = k;
                r = i - 1;
            }
        }
    }
    cout<<s<<endl;
    for(ll i=0;i<n;i++)cout<<z[i]<<" ";
    cout<<endl;
    
    return false;
}
 
int main()
{
    cout<<zalgo("ab","abababa");
    return 0;
}
