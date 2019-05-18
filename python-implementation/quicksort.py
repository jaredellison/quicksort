unsorted = [5, 2, 3, 4, 1]

def quick_sort(values):
    if len(values) <= 1:
        return values

    pivot = values[0]
    left = []
    right = []

    for i in range(1, len(values)):
        if values[i] < pivot:
            left.append(values[i])
        else:
            right.append(values[i])

    left = quick_sort(left)
    right = quick_sort(right)

    return left + [ pivot ] + right

print('Expect [1,2,3,4,5]:', quick_sort(unsorted))