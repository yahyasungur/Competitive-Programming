if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    aim = student_marks[query_name]
    Sum = 0
    for i in range(3):
        Sum += aim[i]
    print("{:.2f}".format(Sum/3))