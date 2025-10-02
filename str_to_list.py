
def str_to_list(input_str):
    stack = []
    for i in input_str:
        if i == "[":
            stack.append([])
        elif i == "]":
            if len(stack) != 1:
                a = stack.pop()
                stack[-1].append(a)
        elif i == ",":
            continue
        else:
            stack[-1].append(int(i))
    return stack[0]

""" In this question, you will implement a custom function str_to_list() that converts 
a string representation of a nested list composed of digits (numbers 0-9) to a python list. """


# Here's one of the long strings for easy copying/testing:
# '[[1,2],0,1,[1,[2,[],3],4,5],7,[8,2],9]'
#print(str_to_list('[[1,2],0,1,[1,[2,[],3],4,5],7,[8,2],9]'))

