def substr_position(str1,str2):
    lst = []
    check = 0
    for i in range(len(str1)):
        for j in range(len(str2)):
            if j+i >= len(str1):
                break
            if str1[i+j] == str2[j]:
                check += 1
        if check == len(str2):
            lst.append(i)
        check = 0
    return lst

#print(substr_position("bacbacbacbbab","bac"))