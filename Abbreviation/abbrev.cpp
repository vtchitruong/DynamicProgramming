#include <bits/stdc++.h>

using namespace std;

#define inputFile "abbrev4.inp"
#define outputFile "abbrev4.out"

int n;
vector<string> query;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;
    string s;
    for (int i = 0; i < n * 2; ++i)
    {
        f >> s;
        query.push_back(s);
    }

    f.close();
}

string abbreviation(string sa, string sb)
{
    vector<vector<bool>> d(sa.size() + 1, vector<bool>(sb.size() + 1));
    
    // sa is empty and sb is empty    
    d[0][0] = true;
    
    // sa is emmty and sb is non-empty
    for (int b = 1; b < sb.size() + 1; ++b)
    {
        d[0][b] = false;
    }
    
    // sa is non-empty and sb is empty
    for (int a = 1; a < sa.size() + 1; ++a)
    {
        if (islower(sa[a - 1]))
            d[a][0] = d[a - 1][0] && true;
        else
            d[a][0] = false;
    }
    
    // sa is non-empty and sb is non-empty
    for (int a = 1; a < sa.size() + 1; ++a)
    {
        for (int b = 1; b < sb.size() + 1; ++b)
        {
            // last character of sa is upper
            if (isupper(sa[a - 1]))
            {
                // last of sa and sb is upper and equal
                if (sa[a - 1] == sb[b - 1])
                {
                    d[a][b] = d[a - 1][b - 1] && true;
                }
                else
                {
                    // last of sa is upper and not equal to last of sb
                    d[a][b] = false;
                }
            }           
            else
            {
                // last character of sa is lower                
                // and can be capitalized to last of sb
                if (toupper(sa[a - 1]) == sb[b - 1])
                {
                    // delete or capitalize the last of sa
                    d[a][b] = d[a - 1][b] || d[a - 1][b - 1];
                }
                else                    
                {
                    // cannot be made to last of sb
                    d[a][b] = d[a - 1][b];
                }
            }
        }
    }

    if (d[sa.size()][sb.size()])
        return "YES";
    else
        return "NO";
}

void Output()
{
    string a, b;
    string yesno;
    vector<string> res;
    for (int i = 0; i < n * 2; i += 2)
    {
        a = query[i];
        b = query[i + 1];
        yesno = abbreviation(a, b);
        res.push_back(yesno);
    }

    ofstream f;
    f.open(outputFile);

    for (auto i : res)
        f << i << endl;

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}