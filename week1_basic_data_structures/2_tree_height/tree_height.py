# python3
# cd .\Data-structures-coursera\week1_basic_data_structures\2_tree_height\  

import sys
import threading
from collections import deque

class Node():

    def __init__(self):
        self.parent = None
        self.children = []

    def set_parent(self, p):
        self.parent = p
        p.children.append(self)

def construct_tree(n, parents):
    tree = [Node()]*n
    root = Node()
    for idx, parent in enumerate(parents):
        if parent >= 0:
            tree[idx].set_parent(tree[parent])
        else:
            root = tree[idx]
    return root

def compute_height(n, parents):
    if n == 1:
        return 0
    root = construct_tree(n, parents)
    height = 0
    size = 0
    q = deque()
    q.append(root)
    while(len(q)!=0):
        size = len(q)
        print("Size is: {}".format(size))
        for i in range(size):
            #print("i is: {}".format(i))
            node = q.popleft()
            print("cildren length is: {}".format(len(node.children)))
            for child in node.children:
                q.append(child)
        height += 1
    return height

def main():
    n = int(input())
    parents = list(map(int, input().split()))
    print(compute_height(n, parents))


# In Python, the default limit on recursion depth is rather low,
# so raise it here for this problem. Note that to take advantage
# of bigger stack, we have to launch the computation in a new thread.
sys.setrecursionlimit(10**7)  # max depth of recursion
threading.stack_size(2**27)   # new thread will get stack of such size
threading.Thread(target=main).start()
