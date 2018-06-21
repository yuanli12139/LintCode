#!/usr/bin/python3

'''
7. Serialize and Deserialize Binary Tree
Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7

Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.


Author: Yuan Li
Date: 6/20/2018 
Difficulty: Medium
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm 
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    """
    def serialize(self, root):
        # write your code here
        if root == None:
            return "{}"
            
        encoded = []
        queue = [root]
        lastNodeId = 0
        while queue:
            for i in range(len(queue)):
                node = queue.pop(0)
                
                if node:
                    encoded.append(node.val)
                    lastNodeId = len(encoded) - 1
                else:
                    encoded.append('#')
                    continue
                
                if node.left:
                    queue.append(node.left)
                else:
                    queue.append(None)
                    
                if node.right:
                    queue.append(node.right)
                else:
                    queue.append(None)
                
        encoded = encoded[:lastNodeId+1]
        
        # convert to string
        serialized = ''
        for s in encoded:
            serialized += str(s) + ','
        serialized = serialized[:-1]    

        return serialized
                
    """
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in 
    "serialize" method.
    """
    def deserialize(self, data):
        # write your code here
        if data == "{}":
            return None
            
        decoded = data.split(',')
        
        root = TreeNode(int(decoded[0]))
        queue = [root]
        qi = 0
        isLeft = True
        for i in range(1, len(decoded)):
            s = decoded[i]
            
            if s != '#':
                node = TreeNode(int(s))
                
                if isLeft:
                    queue[qi].left = node
                    queue.append(queue[qi].left)
                
                else:
                    queue[qi].right = node
                    queue.append(queue[qi].right)
                    
            if not isLeft:
                qi += 1
                
            isLeft ^= 1
            
        return root
