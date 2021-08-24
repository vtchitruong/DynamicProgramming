#include <bits/stdc++.h>

#define inputFile "lis3.inp"
#define outputFile "lis3.out"

using namespace std;

int n;
vector<int> a;

vector<int> d; // d[i] là độ dài lớn nhất của chuỗi con tính từ đầu tới i
vector<int> trace;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    int x;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        a.push_back(x);
    }

    f.close();
}

void Init()
{
    d.resize(n, 1); // khởi tạo độ dài lớn nhất của chuỗi con tăng là 1

    trace.resize(n, -1);
}

void Process()
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j) // j là chỉ số của chuỗi con tính từ đầu đến i
        {
            if (a[j] < a[i]) // xét tăng
            {
                // d[j] + 1 là độ dài tính tới j và thêm 1 phần tử nữa
                // Xét xem d[j] + 1 có lớn hơn độ dài dài nhất mà d[i] hiện đang giữ không
                if (d[j] + 1 > d [i])
                {
                    d[i] = d[j] + 1;
                    trace[i] = j;
                }
            }
        }
    }
}

void Output()
{
    stack<int> sub_arr;

    vector<int>::iterator max_len = max_element(d.begin(), d.end());
    int finish = max_len - d.begin();

    while (!(trace[finish] == -1))
    {
        sub_arr.push(a[finish]);
        finish = trace[finish];
    }
    sub_arr.push(a[finish]);

    ofstream f;
    f.open(outputFile);
    
    f << *max_len << endl;

    while (!sub_arr.empty())
    {
        f << sub_arr.top();
        if (sub_arr.size() > 1) f << ' ';
        sub_arr.pop();
    }

    f.close();
}

int main()
{
    Input();
    Init();    
    Process();
    Output();
    return 0;
}

