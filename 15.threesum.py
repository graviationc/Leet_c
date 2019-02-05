nums = [-1, 0, 1, 2, -1, -4]
def threeSum(nums):
    res=[]
    hash_nums={}
    for i in nums:
        hash_nums[i] = hash_nums.get(i,0) + 1 # get() 函数返回指定键的值，如果值不在字典中返回默认值。
    posnum=[i for i in hash_nums  if i>0 ]
    negnum=[i for i in hash_nums  if i<0 ]
    if hash_nums.get(0,0)>=3:
        res.append([0,0,0]) # 3 个 0 情况
    if negnum==[] or posnum==[]:
        print(res,"here")  #结果不存在
    for i,x in enumerate(posnum):
        if hash_nums[x]>=2 and -2*x in hash_nums:
            res.append([x,x,-2*x]) # 3个数中有两个相等,正数
        for y in posnum[i+1:]:
            if -(x+y) in hash_nums:
                res.append([x,y,-x-y]) #3个数都不相等，2正1负
    for i,x in enumerate(negnum):
        if hash_nums[x]>=2 and -2*x in hash_nums:
            res.append([x,x,-2*x])  # 3个数中有两个相等,负数
        for y in negnum[i+1:]:
            if -(x+y) in hash_nums:
                res.append([x,y,-x-y]) #3个数都不相等，1正2负
    if 0 in hash_nums:
        for x in posnum:
            if -x in hash_nums:
                res.append([x,0,-x])# 1 个 0 情况
    return res
