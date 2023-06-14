eg = "example" # 6x5
inp = "input" # 305x233
filename = inp
f = open(filename, "r")
contents = f.read().split("\n")

visited:set = set()

def addTail():
	visited.add((tail[0], tail[1]))

# start at bottom left
head = [0,0]
tail = [0,0]

addTail()

def pull():
	return abs(tail[0] - head[0]) > 1 or abs(tail[1] - head[1]) > 1

def diag(vertical=False):
	if vertical:
		pos = 0
	else:
		pos = 1

	if head[pos] > tail[pos]:
		tail[pos] += 1
	elif head[pos] < tail[pos]:
		tail[pos] -= 1

for line in contents:
	line = line.split(" ")
	direction = line[0]
	steps = int(line[1])
	
	if direction == "U":
		for step in range(steps):
			head[1] += 1 # move head up

			if pull():
				diag(vertical=True)
				tail[1] += 1
				addTail()

	elif direction == "D":
		for step in range(steps):
			head[1] -= 1 # move head down
			
			if pull():
				diag(vertical=True)
				tail[1] -= 1
				addTail()

	elif direction == "L":
		for step in range(steps):
			head[0] -= 1 # move head left

			if pull():
				diag(vertical=False)
				tail[0] -= 1
				addTail()

	elif direction == "R":
		for step in range(steps):
			head[0] += 1 # move head left

			if pull():
				diag(vertical=False)
				tail[0] += 1
				addTail()

# print(visited)
print(len(visited))