# def merge(args):
#     import copy
#     def merge_lists(left, right):
#         result = []
#         while left and right:
#             which_list = (left if left[0] <= right[0] else right)
#             result.append(which_list.pop(0))
#         return result + left + right
#     lists = args
#     while len(lists) > 1:
#         left, right = copy.copy(lists.pop(0)), copy.copy(lists.pop(0))
#         result = merge_lists(left, right)
#         lists.append(result)
#     return lists.pop(0)


def calc(merged):
    count = 1
    a = merged[0]
    ans = 0
    for i in range(len(merged)-1):  
        if(merged[i+1] == a):
            i+=1
            count+=1
        elif(merged[i+1] != a):
            if(count>2):
                ans+=1
            count=1
            a = merged[i+1]
    return ans



        

arr = []
data = []
arr = map(int,raw_input().split())
for i in range(5):
    arr = map(int, raw_input().split())
    data.extend(arr)
data.sort()
print calc(data)
    
    

