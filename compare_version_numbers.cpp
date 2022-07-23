#define ll long long int
#include <vector>
int compareVersions(string a, string b)
{
    ll asize = a.size();
    ll bsize = b.size();
    ll num = 0;
    vector<ll> a1, b1;
    for (int i = 0; i <= asize; i++)
    {
        if (a[i] == '.' || i == asize)
        {
            a1.push_back(num);
            num = 0;
        }
        else
        {
            num = (num * 10) + (a[i] - '0');
        }
    }
    for (int i = 0; i <= bsize; i++)
    {
        if (b[i] == '.' || i == bsize)
        {
            b1.push_back(num);
            num = 0;
        }
        else
        {
            num = (num * 10) + (b[i] - '0');
        }
    }
    ll temp = max(b1.size(), a1.size());
    // ll a2=0,b2=0;
    ll valuea=0,valueb=0;

    for (ll i = 0; i < temp; i++)
    {
        if (i>=a1.size()){
            valuea=0;
        }
        else{
             valuea=a1[i];
        }
        if (i>=b1.size())
        {
            valueb=0;
        }
        else{
             valueb=b1[i];
        }
        if (valuea>valueb){
            return 1;
        }
        else if(valueb>valuea){
            return -1;
        }

    }
    return 0;
}