#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <iomanip>

#define inputFile "knapsack.inp"
#define outputFile "knapsack.out"

using namespace std;

int n; // number of items
int weightLimit;

vector<int> weight;
vector<int> value;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> weightLimit;

    weight.resize(n + 1, 0);
    value.resize(n + 1, 0);

    for (int i = 1; i < n + 1; ++i)
    {
        f >> weight[i] >> value[i];
    }

    f.close();
}

// d[i][w] stores the max total value of items from 1 to n, in which w is the limitation of weight
vector<vector<int>> d;

void Process()
{
    d.resize(n + 1, vector<int>(weightLimit + 1, 0));

    for (int i = 1; i < n + 1; ++i)
    {          
        for (int w = 1; w < weightLimit + 1; ++w)
        {
            // suppose item i-th is not taken
            d[i][w] = d[i - 1][w];

            // re-assign d[i][w] when item i-th will be selected for better value
            if (weight[i] <=  w)
            {
                if (d[i][w] < d[i - 1][w - weight[i]] + value[i]) // for better value
                {
                    d[i][w] = d[i - 1][w - weight[i]] + value[i];
                }
            }
        }
    }
}

void Output()
{
    stack<int> itemStack;
    int i = n; // tmp number of item
    int wl = weightLimit; // temp weight limit    

    while (i)
    {
        if (!(d[i][wl] == d[i - 1][wl]))
        {
            itemStack.push(i);
            wl = wl - weight[i];
        }
        --i;
    }

    ofstream f;
    f.open(outputFile);

    f << d[n][weightLimit] << '\n';

    while (!itemStack.empty())
    {
        f << itemStack.top();
        if (itemStack.size() != 1) f << ' ';
        itemStack.pop();
    }

    f.close();
}

// show distribution table
void show()
{
    for (int r = 0; r < n + 1; ++r)
    {
        for (int c = 0; c < weightLimit + 1; ++c)
        {
            cout << setw(4) << d[r][c] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    Input();  

    Process();
    show();      

    Output();

    return 0;
}
