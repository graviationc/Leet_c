a=[[1,2,3],[4,5,6]]

atranspose=[]
b=[]

for ii in range(len(a[0])):
    for i in range(len(a)):
        b.append(a[i][ii])
    atranspose.append(b)
    b=[]

atranspose
