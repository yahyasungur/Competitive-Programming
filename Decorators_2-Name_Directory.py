import operator
from operator import itemgetter

def person_lister(f):
    def inner(people):
        # complete the function
        a = len(people)
        for i in range(a):
            people[i][2] = int(people[i][2])
        people.sort(key=itemgetter(2))
        lst = []
        for i in range(a):
            lst.append(f(people[i]))
        return lst
    return inner

@person_lister
def name_format(person):
    return ("Mr. " if person[3] == "M" else "Ms. ") + person[0] + " " + person[1]

if __name__ == '__main__':
    people = [input().split() for i in range(int(input()))]
    print(*name_format(people), sep='\n')