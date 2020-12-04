#https://www.hackerrank.com/challenges/ctci-bubble-sort
n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
swaps_num = 0
for i in range(n):
    for j in range(n-1):
        if a[j] > a[j+1]:
            temp = a[j]
            a[j] = a[j+1]
            a[j+1] = temp
            swaps_num+=1
print("Array is sorted in %d swaps."%swaps_num)
print("First Element: %d"%a[0])
print("Last Element: %d"%a[-1])