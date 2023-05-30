eg = "example"
inp = "input"
filename = eg
f = open(filename, "r")
contents = f.read().split("\n")

visited:set = set()

# start at bottom left
head = (0,0)
tail = (0,0)

visited.add(tail)

for line in contents:
	line = line.split(" ")
	direction = line[0]
	steps = int(line[1])

	first_move = True
	
	if direction == "U":
		for step in range(steps):
			head[1] += 1 # move head up each step
			if not first_move:
				if head[0] > tail[0]: # head on the right
					# tail diagonal
					pass
				elif head[0] < tail[0]: # head on the left
					pass
				else:
					pass
			first_move = False
	if direction == "D":
		pass
	if direction == "L":
		pass
	if direction == "R":
		pass