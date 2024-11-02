import os
import sys

input_file = os.path.join(sys.path[0], 'candypack1.inp')
output_file = os.path.join(sys.path[0], 'candypack1.out')

n = 0
m = 0

pack = [] # pack[i] là số kẹo của gói thứ i
P = []
result = []


def input_data():
    global n, m, pack

    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().split())

        # gói thứ 0 không có kẹo
        pack = [0]
        some_packs = list(map(int, f.readline().split()))
        pack.extend(some_packs)


def process():
    global P, result

    # P[candy] là số thứ tự của gói được chọn để đạt số candy kẹo và là nhỏ nhất
    P = [int(1e12)] * (m + 1)
    P[0] = 0

    # Duyệt số kẹo cần lấy từ 1 đến m
    for candy in range(1, m + 1):
        # Duyệt qua từng gói kẹo từ 1 đến n
        for i in range(1, n + 1):
            # Số kẹo của gói thứ i phải ít hơn số candy kẹo đang xét
            if pack[i] <= candy:
                # P[candy - pack[i]] là số thứ tự của gói nào đó trước khi chọn gói i
                if P[candy - pack[i]] < i:
                    P[candy] = i
                    break

    # Nếu P[m] vô cực thì nghĩa là không có lời giải
    # Ngược lại, thì thực hiện truy ngược từ P[m] về đầu
    if P[m] == int(1e12):
        result.append(-1)
    else:
        # Số kẹo còn lại dùng để truy ngược
        remaining_candy = m

        # Trong khi vẫn còn kẹo để xét
        while remaining_candy > 0:
            # Nạp số thứ tự của gói kẹo được chọn vào result
            result.append(P[remaining_candy])

            # Trừ đi số kẹo của gói vừa nạp vào
            remaining_candy -= pack[result[-1]]


def output():
    global result

    with open(output_file, 'w') as f:
        f.write(' '.join(map(str, result[::-1])))


if __name__ == '__main__':
    input_data()
    process()
    output()