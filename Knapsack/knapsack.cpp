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

// d[i][w] stores the max total value of items from 1 to n, in which w is the limit of weight
vector<vector<int>> d;

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



void Process()
{
    // init
    // n + 1 rows: denotes items
    // weightLimit + 1 columns: denotes limit of weight
    d.resize(n + 1, vector<int>(weightLimit + 1, 0));

    for (int i = 1; i < n + 1; ++i)
    {          
        for (int w = 1; w < weightLimit + 1; ++w)
        {
            // suppose item i-th is not selected
            d[i][w] = d[i - 1][w];

            // re-assign d[i][w] when item i-th will be selected for better total value
            if (weight[i] <=  w)
            {
                d[i][w] = max(d[i][w], d[i - 1][w - weight[i]] + value[i]);
            }
        }
    }
}

void Output()
{
    stack<int> itemStack; // contains items in order
    
    int wl = weightLimit; // temp weight limit
    int i = n; // tmp number of an item
    while (i)
    {
        // The weight changes due to item i
        if (d[i][wl] != d[i - 1][wl])
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
        int item = itemStack.top();
        f << item << ' ' << weight[item] << ' ' << value[item];
        if (itemStack.size() > 1) f << '\n';
        itemStack.pop();
    }

    f.close();
}

// show table
void show()
{
    // display column titles
    cout << string(6 + 2, ' ');
    for (int c = 0; c < weightLimit + 1; ++c)
    {
        cout << setw(6) << c;
    }
    cout << endl;

    // display a seperate line
    cout << string(6 + 2, ' ');    
    cout << string((weightLimit + 1) * 6, '-') << endl;
 
    // display row titles and values
    for (int r = 0; r < n + 1; ++r)
    {
        cout << setw(6) << r << " |";
        for (int c = 0; c < weightLimit + 1; ++c)
        {
            cout << setw(6) << d[r][c];
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