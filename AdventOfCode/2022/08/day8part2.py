eg = "example"
inp = "input"
filename = inp
f = open(filename, "r")
contents = f.read().split("\n")
size = len(contents[0])

def to_arr(old):
	new_arr = []
	for r in old:
		new_sub_arr = []
		for c in r:
			new_sub_arr.append(int(c))
		new_arr.append(new_sub_arr)
	return new_arr

arr = to_arr(contents)
max_score = 0

# don't bother checking the edges, they count as 0 and would nullify scenic score
for i in range(1, size-1):
	for j in range(1, size-1):
		top = 0
		bottom = 0
		left = 0
		right = 0

		tree = arr[i][j]

		# top
		for x in range(i-1, -1, -1):
			top += 1
			if arr[x][j] >= tree:
				break

		# bottom
		for x in range(i+1, size):
			bottom += 1
			if arr[x][j] >= tree:
				break

		# left
		for x in range(j-1, -1, -1):
			left += 1
			if arr[i][x] >= tree:
				break

		# right
		for x in range(j+1, size):
			right += 1
			if arr[i][x] >= tree:
				break
		
		score = top * bottom * left * right
		if score > max_score:
			max_score = score

print(max_score)