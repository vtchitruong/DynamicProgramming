#include <bits/stdc++.h>

#define inputFile "ss1.inp"
#define outputFile "ss1.out"

using namespace std;

vector<int> a;

void Input()
{
    ifstream f;
    f.open(inputFile);

    string line;
    getline(f, line);
    istringstream iss(line);

    int x;
    while (iss >> x)
    {
        a.push_back(x);
    }

    f.close();
}

int Process()
{
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        switch (a[i])
        {
            case 0: count_0 += count_0 + 1;
                break;
            
            case 1: count_1 += count_1 + count_0;
                break;

            case 2: count_2 += count_2 + count_1;
                break;
        }
    }

    return count_2;
}

void Output()
{
    int res = Process();

    ofstream f;
    f.open(outputFile);

    f << res;

    f.close();
}

void Show()
{
    for (auto i : a)
    {
        cout << i << ' ';
    }
}



int main()
{
    Input();
    Output();

    return 0;
}