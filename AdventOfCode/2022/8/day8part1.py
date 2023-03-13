eg = "example"
inp = "input"
filename = eg
f = open(filename, "r")
contents = f.read().split("\n")
size = len(contents[0])

def toArr(old):
    newArr = []
    newSubArr = []
    for r in old:
        for c in r:
            newSubArr.append(int(c))
        newArr.append(newSubArr)
        newSubArr = []
    return newArr

arr = toArr(contents)

visible = 0#(size - 1) * 4

for x in range(1, size - 1):
    for y in range(1, size - 1):
        obstructed = False

        # left
        for i in range(0, x):
            if arr[x][i] >= arr[x][y]:
                obstructed = True
                break
        if not obstructed:
            visible += 1
            continue

        # right
        for i in range(x+1, size):
            if arr[x][i] >= arr[x][y]:
                obstructed = True
                break
        if not obstructed:
            visible += 1
            continue

        # top
        for j in range(0, y):
            if arr[j][y] >= arr[x][y]:
                obstructed = True
                break
        if not obstructed:
            visible += 1
            continue

        # bottom
        for j in range(y+1, size):
            if arr[j][y] >= arr[x][y]:
                obstructed = True
                break
        if not obstructed:
            visible += 1
            continue

        # any items that are printed here are incorrectly marked
        if x == 1 and y == 1\
            or x == 2 and y == 1\
            or x == 1 and y == 2\
            or x == 3 and y == 2\
            or x == 2 and y == 3:
            print("X:", x, "Y:", y)


print(visible)