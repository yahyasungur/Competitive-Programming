if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    maks = -99999
    for i in range(n):
        if arr[i] > maks:
            second = maks
            maks = arr[i]
    print(second)