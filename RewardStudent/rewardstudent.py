import os
import sys
from prettytable import PrettyTable

input_file = os.path.join(sys.path[0], 'rewardstudent.inp')
output_file = os.path.join(sys.path[0], 'rewardstudent.out')

reward = 0 # tổng số phần thưởng
student = 0 # tổng số học sinh

# D[r][s] là số cách mà s học sinh nhận r phần thưởng
D = None


def input_data():
    with open(input_file, 'r') as f:
        global reward, student
        reward, student = map(int, f.readline().split())


# Cách 1: sử dụng mảng hai chiều
def process():
    global D
    
    # Khởi tạo giá trị 0 cho toàn bảng quy hoạch
    D = [[0 for col in range(reward + 1)] for row in range(student + 1)]
    
    # Chỉ có 1 cách để 0 học sinh nhận 0 phần thưởng
    D[0][0] = 1

    # Duyệt hàng (số học sinh) bằng biến s trong phạm vi [1..student]
    for s in range(1, student + 1):
        # Trường hợp 1: số phần thưởng < số học sinh
        # Chỉ có r học sinh được nhận r phần thưởng

        # Duyệt cột (số phần thưởng) bằng biến r trong phạm vi [0..s - 1]
        for r in range(0, s):
            D[s][r] = D[r][r]
        
        # Trường họp 2: số phần thưởng >= số học sinh
        # Trường họp 2a: học sinh hạng chót sẽ không được nhận thưởng
        # Số cách chia thưởng là D[s - 1][r]

        # Trường họp 2b: học sinh hạng chót vẫn được nhận thưởng
        # Số cách chia thưởng D[s][r] sẽ không thay đổi nếu ta bỏ bớt 1 phần thưởng của mỗi học sinh. Số phần thưởng tạm bỏ bớt là (r - s) 
        # Số cách chia thưởng là D[s][r - s]

        # Duyệt cột (số phần thưởng) bằng biến r trong phạm vi [s..reward]        
        for r in range(s, reward + 1):
            D[s][r] = D[s - 1][r] + D[s][r - s]


# Cách 2: sử dụng mảng một chiều
L = list()
def process2():
    global L
    L = [0 for _ in range(reward + 1)]
    L[0] = 1

    for s in range(1, student + 1):
        for r in range(s, reward + 1):
            L[r] = L[r] + L[r - s]


def output():
    with open(output_file, 'w') as f:            
        f.write(f'{D[student][reward]}\n')


def show_table():
    global D

    pt = PrettyTable()
    print(reward)

    # In tiêu đề cột
    column_header = [r for r in range(reward + 1)]
    column_header.insert(0, '') ## insert blank cell
    pt.field_names = column_header

    # Hàng
    for s in range(student + 1):
        row = [x for x in D[s]]
        
        # Tiêu đề hàng
        row.insert(0, s)    
        pt.add_row(row)
    print(pt)


def show_array():
    global L

    pt = PrettyTable()
    
    # Tiêu đề cột
    column_header = [r for r in range(reward + 1)]
    pt.field_names = column_header   
    
    # Hàng giá trị
    pt.add_row(L)
    print(pt)


if __name__ == '__main__':
    input_data()
    process()
    output()