import os
import sys
from collections import deque

input_file = os.path.join(sys.path[0], 'trochoi.inp')
output_file = os.path.join(sys.path[0], 'trochoi.out')

n = k = 0
A = []
result = 0


def input_data():
    global n, k, A

    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())
        A = list(map(int, f.readline().split()))


def process():
    global n, k, A, result

    # Khởi tạo giá trị 0 cho toàn mảng D
    D = [0] * n

    # Khai báo hàng đợi hai đầu q
    q = deque()

    # Nạp vị trí 0 hàng đợi
    q.append(0)

    # Duyệt từng phần tử D[i] trong phạm vi [1..n - 1]
    for i in range(1, n):
        # Nếu hàng đợi q vẫn còn phần tử và phần tử đầu nằm ngoài phạm vi [i - k..i - 1]
        if q and q[0] < i - k:
            # thì loại bỏ phần tử đầu khỏi hàng đợi
            q.popleft()

        # Cập nhật D[i] bằng cách lấy phần tử D lớn nhất trước đó cộng thêm A[i]
        D[i] = D[q[0]] + A[i]

        # Trong khi hàng đợi q vẫn còn phần tử và D[j] nào đó nhỏ hơn hoặc bằng D[i]
        while q and D[q[-1]] <= D[i]:
            # thì loại bỏ D[j] đó
            q.pop()

        # Nạp vị trí i vào hàng đợi q
        q.append(i)

    # Lấy giá trị lớn nhất của mảng D
    result  = max(D)


def output():
    global result    
    with open(output_file, 'w') as f:
        f.write(str(result))


if __name__ == '__main__':
    input_data()
    process()
    output()