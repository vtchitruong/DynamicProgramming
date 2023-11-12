import os
import sys
from prettytable import PrettyTable

input_file = os.path.join(sys.path[0], 'rs.inp')
output_file = os.path.join(sys.path[0], 'rs.out')

rewards = 0
students = 0
d = None

def input_data():
    with open(input_file) as f:
        global rewards, students
        rewards, students = map(int, f.readline().split())


# Approach 1: using table
def process():
    # Init
    global d
    d = [[0 for col in range(rewards + 1)] for row in range(students + 1)]
    d[0][0] = 1 # 0 student receive 0 reward

    for s in range(1, students + 1):

        # Case 1: rewards < students
        # That means the student from number r + 1 to the end will receive nothing.
        # Only r students will receive r rewards.
        for r in range(0, s):
            d[s][r] = d[r][r]
        
        # Case 2: rewards >= students
        # Case 2a: The last student (The worst) will receive nothing
        #     Therefore, the number of ways is d[s - 1][r]

        # Case 2b: The last student will receive something
        #     That means all of the students will receiving something.
        #     If we cut 1 item out of each student's rewards, then the number of cutting items is (r - s)
        #     Therefore, the number of ways is d[s][r - s]
        
        for r in range(s, rewards + 1):
            d[s][r] = d[s - 1][r] + d[s][r - s]


# Approach 2: using 1-dimension array

# When reviewing the table d, we figure out that the first part of each row is the same as the previous row.
# Therefore, we just need to calculate the remaining values of the row.
l = list()
def process2():
    # init
    global l
    l = [0 for _ in range(rewards + 1)]
    l[0] = 1
    
    # The 2D-array will be transformed to a 1D-array, which is a row.
    # Doing similar to the approach 1
    # The row-subscript is skipped and the column-subscript is retained
    for s in range(1, students + 1):
        for r in range(s, rewards + 1):
            l[r] = l[r] + l[r - s]


def output():
    with open(output_file, 'w') as f:            
        f.write(f'{d[students][rewards]}\n')
        f.write(f'{l[rewards]}')

def show_table():
    pt = PrettyTable()
    print(rewards)

    # column header
    column_header = [r for r in range(rewards + 1)]
    column_header.insert(0, '') ## insert blank cell
    pt.field_names = column_header

    # row
    for s in range(students + 1):
        row = [x for x in d[s]]
        row.insert(0, s) # row header    
        pt.add_row(row)
    print(pt)


def show_array():
    pt = PrettyTable()
    
    # column header
    column_header = [r for r in range(rewards + 1)]
    pt.field_names = column_header   
    
    # row of values
    pt.add_row(l)
    print(pt)

if __name__ == '__main__':
    input_data()
    process()
    show_table()

    process2()
    show_array()

    output()