if __name__ == '__main__':
    
    # take second element for sort
    def takeSecond(elem):
        return elem[1]
    
    lst = []
    num = 0
    for _ in range(int(input())):
        name = input()
        score = float(input())
        lst.append((name,score))
        num += 1
    lst.sort(key=takeSecond,reverse=True)
    mini = 9999
    for i in range(num):
        if lst[i][1] < mini:
            second = mini
            mini = lst[i][1]
    lst_name = []
    number = 0
    for i in range(num):
        if lst[i][1] == second:
            lst_name.append(lst[i][0])
            number +=1
    lst_name.sort()
    for i in range(number):
        print(lst_name[i])