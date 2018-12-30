#!/usr/bin/python3

'''
1070. Accounts Merge
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example
Given

[
  ["John", "johnsmith@mail.com", "john00@mail.com"],
  ["John", "johnnybravo@mail.com"],
  ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
  ["Mary", "mary@mail.com"]
]
Return

[
  ["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
  ["John", "johnnybravo@mail.com"],
  ["Mary", "mary@mail.com"]
]
Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.

You could return these lists in any order, for example the answer

[
  ['Mary', 'mary@mail.com'],
  ['John', 'johnnybravo@mail.com'],
  ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']
]
is also acceptable.

Notice
The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].


Author: Yuan Li
Date: 12/29/2018 
Difficulty: Medium
'''

class Solution:
    """
    @param accounts: List[List[str]]
    @return: return a List[List[str]]
    """
    def accountsMerge(self, accounts):
        # write your code here
        # initialize
        self.father = {}
        for i in range(len(accounts)):
            self.father[i] = i
            
        # inverse mapping
        email2ids = {}
        for i, account in enumerate(accounts):
            for email in account[1:]:
                email2ids.setdefault(email, []).append(i)
                
        # union ids
        for _, ids in email2ids.items():
            root_id = ids[0]
            for i in ids[1:]:
                self.union(i, root_id)
                
        # id -> emails
        id2emails = {}
        for i, account in enumerate(accounts):
            root_id = self.find(i)
            email_set = id2emails.get(root_id, set())
            for email in account[1:]:
                email_set.add(email)
            id2emails[root_id] = email_set
      
        # organize output
        merged_accounts = []
        for i, email_set in id2emails.items():
            usr = accounts[i][0]
            merged_accounts.append([usr] + sorted(email_set))
            
        return merged_accounts
    
    def union(self, a, b):
        self.father[self.find(a)] = self.find(b)
        
    def find(self, node):
        path = []
        while self.father[node] != node:
            path.append(node)
            node = self.father[node]
            
        for n in path:
            self.father[n] = node
        
        return node
    
    # # recursion    
    # def find(self, node):
    #     if self.father[node] == node:
    #         return node
            
    #     self.father[node] = self.find(self.father[node])
    #     return self.father[node]

