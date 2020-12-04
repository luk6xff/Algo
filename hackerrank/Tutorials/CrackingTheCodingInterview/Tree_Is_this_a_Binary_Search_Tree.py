#https://www.hackerrank.com/challenges/ctci-is-binary-search-tree
""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

def is_bst_util(root, left_bound = -float("inf"), right_bound = float("inf")):
    if root is None:
        return True
    return (root.data > left_bound and root.data < right_bound and is_bst_util(root.left, left_bound, root.data) and is_bst_util(root.right, root.data, right_bound)) 
    return True

def check_binary_search_tree_(root):
    if root is None:
        return True
    return is_bst_util(root)