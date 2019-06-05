# Uses python3
import sys


def fast_count_segments(starts, ends, points):
    allpts = []
    for i in starts:
        allpts.append((i, 'l'))
    for i in range(0, len(points)):
        allpts.append((points[i], 'p', i))
    for i in ends:
        allpts.append((i, 'r'))
    allpts = sorted(allpts, key=lambda point: point[0])
    cnt = [0] * len(points)
    segment = 0
    for i in allpts:
        if i[1] == 'l':
            segment += 1
        elif i[1] == 'r':
            segment -= 1
        else:
            cnt[i[2]] = segment
    # write your code here
    return cnt


def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    # use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
