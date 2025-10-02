def flatten(lst):
    i = 0
    while True:
        if i >= len(lst):
            break
        if type(lst[i]) == list:
            lst[:] = lst[:i] + lst[i] + lst[i+1:]
            i = -1
        i += 1        
    return lst

#print(flatten([1,[[2],3],[[[4]]]]))