'''
Maximum of a even number minus a odd number

Company: FICO

Date: 12/8/2018
Author: Yuan Li
'''

i = -1
max_diff = -sys.maxsize                                                                      
for j in range(0, len(arr)):
 if arr[j] % 2 == 1:
    if i >= 0:
      i = j if arr[j] < arr[i] else i
    else:
      i = j
                                                                    
 if arr[j] % 2 == 0 and i >= 0:                                                      
    max_diff = max(max_diff, arr[j] - arr[i])                                                                   
                                                                    
return max_diff

