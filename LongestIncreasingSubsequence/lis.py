import os
import sys
from collections import deque
from prettytable import PrettyTable

input_file = os.path.join(sys.path[0], 'lis.inp')
output_file = os.path.join(sys.path[0], 'lis.out')


def input_data():
    with  open(input_file) as f:
        global n # total number of element
        n = int(f.readline())

        global a # main array        
        a = list(map(int, f.readline().split()))


def process():
    # Init
    global d # d[i] is the maximum length of 0-th to i-th subsequence
    d = [1 for _ in range(n)] # The initial longest of a subsequence is 1

    global trace # for marking and output
    trace = [-1 for _ in range(n)]

    for i in range(1, n):
        for j in range(i): # j is the index of the subsequence from 0 to i-th
            if a[j] < a[i]: # if increasing
                
                # d[j] + 1 is the length of the subsequence plus 1 more element
                # We consider if d[j] + 1 is greater than d[i], which is storing the maximum length 
                if d[j] + 1 > d[i]:
                    d[i] = d[j] + 1
                    trace[i] = j # for tracing backward later


def output():   
    max_length = max(d) # the longest length of the increasing subsequence
    finish = d.index(max_length) # postition of the last element of the output subsequence

    sub_seq = deque()
    while not trace[finish] == -1:
        sub_seq.append(a[finish])
        finish = trace[finish] # trace backward    
    sub_seq.append(a[finish])

    with open(output_file, 'w') as f:
        f.write(f'{max_length}\n')
        
        s = ' '.join([str(e) for e in reversed(sub_seq)])        
        f.write(s)


def show_arrays():

    pt = PrettyTable()

    column_header = [r for r in range(n)]
    column_header.insert(0, '')
    pt.field_names = column_header

    tmp_a = a.copy()
    tmp_a.insert(0, 'a')

    tmp_d = d.copy()
    tmp_d.insert(0, 'd')

    tmp_trace = trace.copy()
    tmp_trace.insert(0, 'trace')

    pt.add_row(tmp_a)
    pt.add_row(tmp_d)
    pt.add_row(tmp_trace)
    print(pt)


if __name__ == '__main__':
    input_data()
    process()
    show_arrays()    
    output()
    