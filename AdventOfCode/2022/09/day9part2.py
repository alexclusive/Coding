eg1 = "example" # 6x5
eg2 = "example2"
inp = "input" # 305x233
filename = inp
f = open(filename, "r")
contents = f.read().split("\n")

visited:set = set()
rope = [[0,0] for _ in range(10)]

def addTail():
	tail = (rope[-1][0], rope[-1][1])
	visited.add(tail)

'''
(2, 2):(1, 1)
(2, 1):(1, 1)
(2, 0):(1, 0)
(2, -1):(1, -1)
(2, -2):(1, -1)

(-2, 2):(-1, 1)
(-2, 1):(-1, 1)
(-2, 0):(-1, 0)
(-2, -1):(-1, -1)
(-2, -2):(-1, -1)

(1, 2):(1, 1)
(1, -2):(1, -1)

(-1, -2):(-1,-1)
(-1, 2):(-1, 1)

(0, -2):(0, -1)
(0, 2):(0, 1)
'''
def update_knot(pos:int) -> list[int]:
	vert = rope[pos-1][0] - rope[pos][0]
	hori = rope[pos-1][1] - rope[pos][1]

	add_up = 0
	add_right = 0

	if abs(vert) == 2:
		add_up = vert / 2
		if abs(hori) == 1:
			add_right = hori
		if abs(hori) == 2:
			add_right = hori / 2
	elif abs(vert) == 1:
		if abs(hori) == 2:
			add_up = vert
			add_right = hori / 2
	elif vert == 0 and abs(hori) == 2:
		add_right = hori / 2

	add_up = int(add_up)
	add_right = int(add_right)

	# print(str((vert, hori)) + ":" + str((add_up, add_right)))

	rope[pos][0] += add_up
	rope[pos][1] += add_right

def move_knots(vertical:bool, dist:int):
	rope[0][vertical] += dist # move head
	for i in range(1, len(rope)):
		update_knot(i)

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

print(visited)
print(len(visited))