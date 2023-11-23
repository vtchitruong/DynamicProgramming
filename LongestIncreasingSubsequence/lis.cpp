#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

#define inputFile "lis.inp"
#define outputFile "lis.out"

using namespace std;

int n;
vector<int> a; // input array

vector<int> d; // d[i] is the maximum length of 0-th to i-th subsequence
vector<int> trace; // for marking and output

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n; // total number of element

    int x;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        a.push_back(x);
    }

    f.close();
}

void Process()
{
    // Init
    d.resize(n, 1); // The initial longest of a subsequence is 1

    trace.resize(n, -1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j) // j is the index of the subsequence from 0 to i-th
        {
            if (a[j] < a[i]) // if increasing
            {
                // d[j] + 1 is the length of the subsequence plus 1 more element
                // We consider if d[j] + 1 is greater than d[i], which is storing the maximum length 
                if (d[j] + 1 > d [i])
                {
                    d[i] = d[j] + 1;
                    trace[i] = j; // for tracing backward later
                }
            }
        }
    }
}

void Output()
{   
    // find the position that stores the maximum length
    vector<int>::iterator max_len = max_element(d.begin(), d.end());
    
    // the postition of the last element of the sub_seq
    int finish = max_len - d.begin();

    stack<int> sub_seq; // subsequence
    while (!(trace[finish] == -1))
    {
        sub_seq.push(a[finish]);
        finish = trace[finish]; // trace backward
    }
    sub_seq.push(a[finish]);

    ofstream f;
    f.open(outputFile);
    
    f << *max_len << endl;

    while (!sub_seq.empty())
    {
        f << sub_seq.top();
        if (sub_seq.size() > 1) f << ' ';
        sub_seq.pop();
    }

    f.close();
}

int main()
{
    Input();    
    Process();
    Output();
    return 0;
}

