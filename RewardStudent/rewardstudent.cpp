#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

#define inputFile "rs2.inp"
#define outputFile "rs2.out"

int rewards, students;
vector<vector<int>> d;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> rewards >> students;

    f.close();
}

// Approach 1: using table
void Process()
{
    // init    
    // students + 1 rows
    // rewards + 1 cols
    d.resize(students + 1, vector<int>(rewards + 1, 0));

    d[0][0] = 1; // 0 student receive 0 reward
    
    for (int s = 1; s < students + 1; ++s)
    {
        // Case 1: rewards < students
        // That means the student from number r + 1 to the end will receive nothing
        // Only r students will receive r rewards.
        for (int r = 0; r < s; ++r)
        {
            d[s][r] = d[r][r];
        }

        // Case 2: rewards >= students
        // In this case, we divide ways of rewarding into 2 groups
        // Group 1: The last student (The worst) will receive nothing
        //     Therefore, the number of ways is d[s - 1][r]

        // Group 2: The last student will receive something
        //     That means all of the students will receiving something.
        //     If we cut 1 item out of each student's rewards, then the number of cutting items is (r - s)
        //     Therefore, the number of ways is d[s][r - s]

        for (int r = s; r < rewards + 1; ++r)
        {
            d[s][r] = d[s - 1][r] + d[s][r - s];
        }
    }
}

// Approach 2: using 1-dimension array

// When reviewing the table d, we figure out that the first part of each row is the same as the previous row.
// Therefore, we just need to calculate the remaining values of the row.
vector<int> v;
void Process2()
{
    // init
    v.resize(rewards + 1, 0);
    v[0] = 1;

    for (int s = 1; s < students + 1; ++s)
    {
        for (int r = s; r < rewards + 1; ++r)
        {
            v[r] = v[r] + v[r - s];
        }
    }
}

void Output()
{
    ofstream f;
    f.open(outputFile);

    f << d[students][rewards] << endl;
    f << v[rewards];

    f.close();
}

void ShowTable()
{
    // display column titles
    cout << string(6 + 2, ' ');
    for (int col = 0; col < rewards + 1; ++col)
    {
        cout << setw(6) << col;
    }
    cout << endl;

    // display a seperate line
    cout << string(6 + 2, ' ');    
    cout << string((rewards + 1) * 6, '-') << endl;
 
    // display row titles and values    
    for (int row = 0; row < students + 1; ++row)
    {
        cout << setw(6) << row << " |";
        for (int col = 0; col < rewards + 1; ++col)
        {
            cout << setw(6) << d[row][col];
        }
        cout << endl;
    }

    cout << endl;
}

void ShowArray()
{
    // display titles
    cout << string(6 + 2, ' ');
    for (int col = 0; col < rewards + 1; ++col)
    {
        cout << setw(6) << col;
    }
    cout << endl;

    // display a seperate line
    cout << string(6 + 2, ' ');    
    cout << string((rewards + 1) * 6, '-') << endl;
 
    // display values    
    cout << setw(8) << " |";
    for (int col = 0; col < rewards + 1; ++col)
    {
        cout << setw(6) << v[col];
    }
    cout << endl;    
}

int main()
{
    Input();
    Process();
    Process2();

    //ShowTable();
    ShowArray();

    Output();
    return 0;
}