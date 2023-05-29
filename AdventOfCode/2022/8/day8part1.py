eg = "example"
inp = "input"
test = "test"
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

visible = (size - 1) * 4

for i in range(1, size-1): # rows (553)
	for j in range(1, size-1): # columns (551)
		tree = arr[i][j]
		is_visible = True

		"""
		1,1 visible top, left
		1,2 visible top, right
		2,1 visible right
		2,3 visible right
		3,2 visible bottom, left
		"""

		# top
		for x in range(0, i):
			if arr[x][j] >= tree:
				is_visible = False

		# bottom
		if not is_visible:
			is_visible = True
			for x in range(i+1, size):
				if arr[x][j] >= tree:
					is_visible = False

		# left
		if not is_visible:
			is_visible = True
			for x in range(0, j):
				if arr[i][x] >= tree:
					is_visible = False

		# right
		if not is_visible:
			is_visible = True
			for x in range(j+1, size):
				if arr[i][x] >= tree:
					is_visible = False

		if is_visible:
			print("visible")
			visible += 1

		# if not (i == 1 and j == 2\
		# 	or i == 2 and j == 1\
		# 	or i == 2 and j == 3):
		# 	continue

print(visible)