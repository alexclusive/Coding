def part1(contents:list[str]):
	cycles = []

	cycle = 0
	x = 1
	for line in contents:
		command = line.split(" ")
		cycle += 1
		if cycle == 20 or (cycle - 20) % 40 == 0:
			print(cycle)
			cycles.append(cycle * x)

		if command[0][0] == "a":
			cycle += 1
			if cycle == 20 or (cycle - 20) % 40 == 0:
				print(cycle)
				cycles.append(cycle * x)
			x += int(command[-1])

	print(sum(cycles))

def main():
	eg1 = "example"
	eg2 = "example2"
	inp = "input"
	filename = inp
	f = open(filename, "r")
	contents = f.read().split("\n")
	part1(contents)

main()