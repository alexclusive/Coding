eg1 = "example" # 6x5
eg2 = "example2"
inp = "input" # 305x233
filename = eg2
f = open(filename, "r")
contents = f.read().split("\n")

visited:set = set()
rope = [[0,0] for _ in range(10)]

def addTail():
	tail = (rope[-1][0], rope[-1][1])
	# if tail not in visited:
	# 	print(tail)
	visited.add(tail)

def pull(head:list, tail:list) -> bool:
	return abs(tail[0] - head[0]) > 1 or abs(tail[1] - head[1]) > 1

def adjust_diagonal(head:list, tail:list, vertical) -> list:
	if vertical:
		pos = 0
	else:
		pos = 1

	if head[pos] > tail[pos]:
		tail[pos] += 1
	elif head[pos] < tail[pos]:
		tail[pos] -= 1

	return tail

def move_knots(vertical:bool, dist:int):
	rope[0][vertical] += dist # move head
	for i in range(1, len(rope)):
		if pull(rope[i-1], rope[i]):
			rope[i] = adjust_diagonal(rope[i-1], rope[i], vertical)
			rope[i][1] += dist

def step_through_knots(steps, vertical, positive):
	dist = positive*2 - 1 # True -> 1, False -> -1

	for _ in range(steps):
		move_knots(vertical, dist)
		addTail()

addTail()
for line in contents:
	line = line.split(" ")
	direction = line[0]
	steps = int(line[1])

	vertical = direction == "U" or direction == "D"
	positive = direction == "U" or direction == "R"
	step_through_knots(steps, vertical, positive)
	
	# if direction == "U":
	# 	for step in range(steps):
	# 		move_knots(True, 1)
	# 		addTail()

	# elif direction == "D":
	# 	for step in range(steps):
	# 		move_knots(True, -1)
	# 		addTail()

	# elif direction == "L":
	# 	for step in range(steps):
	# 		move_knots(False, -1)
	# 		addTail()

	# elif direction == "R":
	# 	for step in range(steps):
	# 		move_knots(False, 1)
	# 		addTail()

print(visited)
print(len(visited))