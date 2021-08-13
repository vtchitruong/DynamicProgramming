#include <bits/stdc++.h>

#define inputFile "maxsum4.inp"
#define outputFile "maxsum4.out"

using namespace std;

int n;
vector<int> arr;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    int x;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        arr.push_back(x);
    }

    f.close();
}

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

void Output()
{
    ofstream f;
    f.open(outputFile);
    
    int res = maxSubsetSum(arr);
    f << res;

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}