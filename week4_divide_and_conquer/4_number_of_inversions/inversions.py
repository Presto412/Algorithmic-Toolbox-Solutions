# Uses python3
import sys


def merge(b, c):
    D = (len(b) + len(c))*0
    pairCount = 0
    while(len(b) != 0 and len(c) != 0):
        _b = b[0]
        _c = c[0]
        if _b <= _c:
            D.append(_b)
        else:
            pairCount += 1
            D.append(_c)
    [D.append(i) for i in b]
    [D.append(i) for i in c]
    return D, pairCount


def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if right - left <= 1:
        return number_of_inversions
    ave = (left + right) // 2
    number_of_inversions += get_number_of_inversions(a, b, left, ave)
    number_of_inversions += get_number_of_inversions(a, b, ave, right)
    # write your code here
    c, inversions = merge(a[left: ave], a[ave: right])
    print(a)
    a[left: right] = c
    print(a)
    number_of_inversions += inversions
    return number_of_inversions


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)))
