# Uses python3
import math
import random
import time
import sys


def solution(x, y):
    points = list(zip(x, y))
    points_x_sorted = sorted(points, key=lambda obj: obj[0])
    points_y_sorted = sorted(points, key=lambda obj: obj[1])
    d = minimum_points_distance(points_x_sorted, points_y_sorted)
    return d


def minimum_points_distance(points_x_sorted, points_y_sorted):
    ln_ax = len(points_x_sorted)
    if ln_ax <= 3:
        return brute(points_x_sorted)
    mid = ln_ax // 2
    points_x_sorted_left = points_x_sorted[:mid]
    points_x_sorted_right = points_x_sorted[mid:]
    points_x_sorted_set = set(points_x_sorted_left)
    points_y_sorted_left = list()
    points_y_sorted_right = list()
    for point in points_y_sorted:
        if point in points_x_sorted_set:
            points_y_sorted_left.append(point)
        else:
            points_y_sorted_right.append(point)
    d1 = minimum_points_distance(points_x_sorted_left, points_y_sorted_left)
    d2 = minimum_points_distance(points_x_sorted_right, points_y_sorted_right)
    d = min(d1, d2)
    d3 = closest_split_pair(points_x_sorted, points_y_sorted, d)
    return min(d3, d)


def brute(points_x_sorted):
    mi = calc_dist(points_x_sorted[0], points_x_sorted[1])
    ln_ax = len(points_x_sorted)
    if ln_ax == 2:
        return mi
    for i in range(ln_ax - 1):
        for j in range(i + 1, ln_ax):
            if i != 0 or j != 1:
                d = calc_dist(points_x_sorted[i], points_x_sorted[j])
                if d < mi:
                    mi = d
    return mi


def calc_dist(point1, point2):
    return math.sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)


def closest_split_pair(points_x_sorted, points_y_sorted, delta):
    ln_x = len(points_x_sorted)
    mx_x = points_x_sorted[ln_x // 2][0]
    s_y = [x for x in points_y_sorted if mx_x - delta <= x[0] <= mx_x + delta]
    best = delta
    ln_y = len(s_y)
    for i in range(ln_y - 1):
        for j in range(i + 1, min(i + 7, ln_y)):
            p, q = s_y[i], s_y[j]
            if q[1] - p[1] > best:
                break
            dst = calc_dist(p, q)
            if dst < best:
                best = dst
    return best


def test_case(length: int = 10000):
    lst1 = [random.randint(-10 ** 9, 10 ** 9) for i in range(length)]
    lst2 = [random.randint(-10 ** 9, 10 ** 9) for i in range(length)]
    return lst1, lst2


if __name__ == '__main__':
    # input = sys.stdin.read()
    # data = list(map(int, input.split()))
    # n = data[0]
    # x = data[1::2]
    # y = data[2::2]
    x, y = test_case()
    start = time.time()
    print("{0:.9f}".format(solution(x, y)))
    print(time.time() - start)
