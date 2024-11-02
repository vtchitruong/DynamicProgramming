#include <iostream>
#include <vector>

#define input_file "candypack2.inp"
#define output_file "candypack2.out"

using namespace std;

int n; // tổng số gói
int m; // tổng số kẹo cần lấy

vector<int> pack; // pack[i] là số kẹo của gói thứ i
vector<int> P;
vector<int> result;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen(input_file, "r", stdin);
    
    cin >> n >> m;

    // Gói thứ 0 không có kẹo
    pack.push_back(0);

    int x;
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> x;
        pack.push_back(x);
    }
}


void process()
{
    // P[candy] là số thứ tự của gói được chọn để đạt số candy kẹo và là nhỏ nhất
    P.resize(m + 1, INT_MAX);
    P[0] = 0;

    // Duyệt số kẹo cần lấy từ 1 đến m
    for (int candy = 1; candy < m + 1; ++candy)
    {
        // Duyệt qua từng gói kẹo từ 1 đến n
        for (int i = 1; i < n + 1; ++i)
        {
            // Số kẹo của gói thứ i phải ít hơn số candy kẹo đang xét
            if (pack[i] <= candy)
            {
                // P[candy - pack[i]] là số thứ tự của gói nào đó trước khi chọn gói i
                if (P[candy - pack[i]] < i)
                {
                    P[candy] = i;
                    break;
                }
            }
        }
    }

    // Nếu P[m] vô cực thì nghĩa là không có lời giải
    // Ngược lại, thì thực hiện truy ngược từ P[m] về đầumảng P 
    if (P[m] == INT_MAX)
    {
        result.push_back(-1);
    }
    else
    {
        // Số kẹo còn lại dùng để truy ngược
        int remaining_candy = m;

        // Trong khi vẫn còn kẹo để xét
        while (remaining_candy > 0)
        {
            // Nạp số thứ tự của gói kẹo được chọn vào result
            result.push_back(P[remaining_candy]);
            
            // Trừ đi số kẹo của gói vừa nạp vào
            remaining_candy -= pack[result.back()];
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);
    
    for (int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i] << ' ';
    }
}


int main()
{
    input();
    process();
    output();
    
    return 0;
}