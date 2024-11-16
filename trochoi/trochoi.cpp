#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define input_file "trochoi.inp"
#define output_file "troichoi.out"

using namespace std;

typedef long long int lli;

int n, k;
vector<lli> A;
lli result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    A.resize(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
}


void process()
{
    // Khởi tạo giá trị 0 cho toàn mảng D
    vector<lli> D(n, 0);

    // Khai báo hàng đợi hai đầu q
    deque<int> q;

    // Nạp vị trí 0 hàng đợi
    q.push_back(0);

    // Duyệt từng phần tử D[i] trong phạm vi [1..n - 1]
    for (int i = 1; i < n; ++i)
    {
        // Nếu hàng đợi q vẫn còn phần tử và phần tử đầu nằm ngoài phạm vi [i - k..i - 1]
        if (!q.empty() && q.front() < i - k)
        {
            // thì loại bỏ phần tử đầu khỏi hàng đợi
            q.pop_front();
        }

        // Cập nhật D[i] bằng cách lấy phần tử D lớn nhất trước đó cộng thêm A[i]
        D[i] = D[q.front()] + A[i];

        // Trong khi hàng đợi q vẫn còn phần tử và D[j] nào đó nhỏ hơn hoặc bằng D[i]
        while (!q.empty() && D[q.back()] <= D[i])
        {
            // thì loại bỏ D[j] đó
            q.pop_back();
        }

        // Nạp vị trí i vào hàng đợi q
        q.push_back(i);
    }

    // Lấy giá trị lớn nhất của mảng D
    result  = *max_element(D.begin(), D.end());
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << result;
}


int main()
{
    input();
    process();
    output();

    return 0;
}