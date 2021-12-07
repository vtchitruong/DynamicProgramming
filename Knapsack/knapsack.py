import os
import sys
from prettytable import PrettyTable

input_file = os.path.join(sys.path[0], 'knapsack.inp')
output_file = os.path.join(sys.path[0], 'knapsack.out')

#-----------------------------------------------------------------------------
def input_data():
    global n, weight_limit
    global weight, value
    weight = list()
    value = list()

    with open(input_file) as f:
        n, weight_limit = map(int, f.readline().split())

        weight.append(0) # the zero-th element is not used
        value.append(0) # the zero-th element is not used
        for line in f.readlines():
            w, v = map(int, line.split())
            weight.append(w)
            value.append(v)

#-----------------------------------------------------------------------------
def process():
    # d[i][w] stores the max total value of items from 1 to n,
    # in which w is the limit of weight
    global d
    d = list()

    # init
    # n + 1 rows: denotes items
    # weight_limit + 1 columns: denotes limit of weight
    d = [[0 for col in range(weight_limit + 1)] for row in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, weight_limit + 1):
            # suppose item i-th is not taken
            d[i][w] = d[i - 1][w]

            # re-assign d[i][w] when item i-th will be selected for better total value
            if weight[i] <= w:
                d[i][w] = max(d[i][w], d[i - 1][w - weight[i]] + value[i])

#-----------------------------------------------------------------------------
def output():
    s = list() # this is used as a stack

    wl = weight_limit # temp weight limit
    i = n # temp number of an item
    while i:
        if not d[i][wl] == d[i - 1][wl]:
            s.append(i)
            wl = wl - weight[i]
        i -= 1

    with open(output_file, 'w') as f:
        f.write(f'{d[n][weight_limit]}\n')
        for idx, item in enumerate(reversed(s)):
            line = f'{item} {weight[item]} {value[item]}'
            f.write(line) if idx == len(s) - 1 else f.write(line + '\n')

#-----------------------------------------------------------------------------
def show_table():
    pt = PrettyTable()

    # column header
    column_header = [w for w in range(weight_limit + 1)]
    column_header.insert(0, '') # insert blank cell
    pt.field_names = column_header

    # row
    for i in range(n + 1):
        row = [x for x in d[i]]
        row.insert(0, i) # row header
        pt.add_row(row)
    print(pt)

#-----------------------------------------------------------------------------
if __name__ == '__main__':
    input_data()
    process()
    show_table()
    output()