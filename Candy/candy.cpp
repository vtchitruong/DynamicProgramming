#include <bits/stdc++.h>

#define inputFile "candy1.inp"
#define outputFile "candy1.out"

using namespace std;

typedef long long lol;
int children;
vector<int> rating;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> children;

    int x;
    for (int i = 0; i < children; ++i)
    {
        f >> x;
        rating.push_back(x);
    }

    f.close();
}

lol candies(int n, vector<int> a)
{
    // init: 1 candy per child
    vector<int> candy(n, 1);
    //show(candy);

    // iterate forward from left to right
    for (int i = 1; i < n; ++i)
    {
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;
    }

    // iterate backward from right to left
    for (int i = n - 1; i > 0; --i)
    {
        if (rating[i - 1] > rating[i]) // we can use && operator here
            if (candy[i - 1] <= candy[i])
            {
                candy[i - 1] = candy[i] + 1;
            }
    }

    lol sum;
    sum = accumulate(candy.begin(), candy.end(), 0LL * 0LL); // 0 in long long

    /*
    for (auto i : candy)
    {
        sum += i;
    }
    */

    return sum;
}

void Output()
{
    ofstream f;
    f.open(outputFile);
    
    lol res = candies(children, rating);
    f << res;

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}