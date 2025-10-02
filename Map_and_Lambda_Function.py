cube = lambda x: x**3

def fibonacci_helper(n):
    if n == 1:
        return 0
    elif n == 2 or n == 3:
        return 1
    else:
        return fibonacci_helper(n-2) + fibonacci_helper(n-1)

def fibonacci(n):
    lst = []
    for i in range(1,n+1):
        lst.append(fibonacci_helper(i))
    return lst
        

if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))