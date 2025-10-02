
def kthNumber(lst,number):
    for i in range(number):
        mini = 9999999
        for j in range(len(lst)):
            if lst[j] < mini:
                mini = lst[j]
                index = j
        lst.pop(index)
    return mini

#print(kthNumber([14, 5, 3, 7, -9, 0, 1, 3, 4, -3, -11, 6, 9, -1, -3, -12], 12))
