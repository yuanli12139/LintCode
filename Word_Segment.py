'''
The symbols can only have 1 or 2 letters,
e.g.: {s, si, h, he, li, p, be}

For example:

symbols = {'c', 'h', 'p', 's', 'si', 'y', 'al', 'ag', 'ar', 
        'w', 'x', 'u', 'b', 'br', 'am', 'fl', 'o', 'th'}
"physics" -> p, h, y, si, c, s, return True
"zip" -> cannot be segmented, return False


Author: Yuan Li
Date: 12/8/2018 
'''

# DFS
class WordSegment:
  def findSegment(self, s, symbols):
    if not s or not symbols:
      return False
  
    return self.dfs(s, "", symbols) 
  
  def dfs(self, s, seg, symbols):
    print(seg)

    if len(seg) == len(s):
      return seg == s 

    idx = len(seg)
    for i in range(1, 3):
      if idx + i > len(s) or s[idx:idx+i] not in symbols:
        continue

      if self.dfs(s, seg + s[idx:idx+i], symbols):
        return True

    return False


# DP
class WordSegment:
  def findSegment(self, s, symbols):
    if not s or not symbols:
      return False
    
    dp = [False] * 2  
    dp[0] = s[0] in symbols
    dp[1] = (dp[0] and s[1] in symbols) or s[:2] in symbols

    for i in range(2, len(s)):
      dp[i%2] = (dp[(i-1)%2] and s[i] in symbols) or (dp[(i-2)%2] and s[i-1: i+1] in symbols)

    return dp[(len(s)-1)%2]


#if __name__ == '__main__':
#  symbols = {'c', 'h', 'p', 's', 'si', 'y', 'al', 'ag', 'ar', \ 
#             'w', 'x', 'u', 'b', 'br', 'am', 'fl', 'o', 'th'}
#             
#  print(WordBreak().findSegment("physics", symbols))

