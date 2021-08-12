#include <bits/stdc++.h>

using namespace std;

int maxSubsetSum(vector<int> a)
{
    vector<int> sm(a.size()); // sum max
    
    sm[0] = a[0];
    sm[1] = max(a[0], a[1]);
    
    for (int i = 2; i < a.size(); ++i)
    {
        sm[i] = max(a[i],max(sm[i - 2] + a[i],max(sm[i - 1], sm[i -2])));
    }
    return sm[sm.size() - 1];
}

int main()
{


    return 0;
}