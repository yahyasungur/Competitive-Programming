import re

def fun(s):
    # return True if s is a valid email, else return False
    et_index = s.find("@")
    dot_index = s.find(".")
    if et_index == 0 or dot_index == 0:
        return False

    elif re.match("^[A-Za-z0-9_-]*$", s[:et_index]):
        if re.match("^[A-Za-z0-9]*$", s[et_index+1:dot_index]):
            if len(s[dot_index+1:]) <= 3:
                return True
        
    else:
        return False

def filter_mail(emails):
    return list(filter(fun, emails))

if __name__ == '__main__':
    n = int(input())
    emails = []
    for _ in range(n):
        emails.append(input())

filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(filtered_emails)