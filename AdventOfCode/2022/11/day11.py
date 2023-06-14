class Monkey:
	ID = 0
	items = []											# items held to be inspected (worry levels stored)
	operation = lambda a : a * 1						# operation to do on inspection
	test = lambda a : True if a % 2 == 0 else False		# test to see worry level
	true = 0											# which monkey ID to pass to if test True
	false = 0											# which monkey ID to pass to if test False
	inspections = 0

	def __init__(self, id):
		self.ID = id
	
	def setItems(self, newItems:list[int]):
		self.items = newItems

	def setOperation(self, newOp):
		self.operation = newOp

	def setTest(self, newTest):
		self.test = newTest

	def setTrue(self, ifTrue):
		self.true = ifTrue

	def setFalse(self, ifFalse):
		self.false = ifFalse

	def inspect(self, idx, part1=False):
		self.items[idx] = int(self.operation(self.items[idx]))
		if part1:
			self.items[idx] = int(self.items[idx] // 3)
		self.inspections += 1

	def check(self, idx) -> int:
		if self.test(self.items[idx]):
			return self.true
		else:
			return self.false
		
class Group:
	monkeys:list[Monkey] = []

	def doRound(self, part1=False):
		for monkey in self.monkeys:
			while len(monkey.items) > 0:
				monkey.inspect(0, part1)
				sendTo = monkey.check(0)
				item = monkey.items.pop(0) # remove from this monkey
				self.monkeys[sendTo].items.append(item) # send to next

	def print(self):
		for monkey in self.monkeys:
			print("Monkey " + str(monkey.ID) + ", inspected " + str(monkey.inspections) + " holds " + str(monkey.items))

	def getMonkeyBusiness(self):
		top = 0
		second = 0
		for monkey in self.monkeys:
			if monkey.inspections > self.monkeys[top].inspections:
				second = top
				top = monkey.ID
			elif monkey.inspections > self.monkeys[second].inspections:
				second = monkey.ID
		topInspections = self.monkeys[top].inspections
		secondInspections = self.monkeys[second].inspections
		business = topInspections * secondInspections
		# print("Top (" + str(top) + "): " + str(topInspections))
		# print("Second (" + str(second) + "): " + str(secondInspections))
		# print("Business:", business)
		return business

	def __init__(self, contents:list[str]):
		currentMonkey = Monkey(0)
		for fullLine in contents:
			# remove ':', ',' and begining whitespace, then split on ' '
			line = fullLine.replace(':', '').replace(',', '').lstrip().split(' ')

			if line[0] == "Monkey":
				currentMonkey = Monkey(int(line[1]))

			elif line[0] == "Starting":
				items = []
				for i in range(2, len(line)):
					items.append(int(line[i]))
				currentMonkey.setItems(items)

			elif line[0] == "Operation":
				op = lambda a : a
				if line[5] == "old":
					if line[4] == '*':
						op = lambda a : a * a
					elif line[4] == '+':
						op = lambda a : a + a
				else:
					b = int(line[5])
					if line[4] == '*':
						op = lambda a, b=b : a * b
					elif line[4] == '+':
						op = lambda a, b=b : a + b
				currentMonkey.setOperation(op)

			elif line[0] == "Test":
				if line[1] == "divisible":
					div = int(line[3])
					currentMonkey.setTest(lambda a, d=div : True if a % d == 0 else False)
					
			elif line[0] == "If":
				if line[1] == "true":
					currentMonkey.setTrue(int(line[-1]))
				if line[1] == "false":
					currentMonkey.setFalse(int(line[-1]))
					self.monkeys.append(currentMonkey)	

# def part1(group:Group):
# 	for _ in range(20):
# 		group.doRound(True)
# 	group.print()
# 	business = group.getMonkeyBusiness()
# 	print("Part 1:", business)

# def part2(group:Group):
# 	for i in range(10000):
# 		print("Round " + str(i) + " " + str())
# 		group.doRound(False)
# 	group.print()
# 	business = group.getMonkeyBusiness()
# 	print("Part 2:", business)

def getBusiness(group:Group, rounds:int, part1=False) -> int:
	for i in range(rounds):
		print("Round " + str(i) + " " + str((i/rounds)*100) + "%")
		group.doRound(part1)
	group.print()
	return group.getMonkeyBusiness()

def main():
	eg1 = "example"
	eg2 = "example2"
	inp = "input"
	filename = inp
	f = open(filename, "r")
	contents = f.read().split("\n")
	
	monkeyGroup = Group(contents)
	# print("Part 1:", getBusiness(monkeyGroup, 20, True))
	print("Part 2:", getBusiness(monkeyGroup, 10000))
	# part1(monkeyGroup)
	# part2(monkeyGroup)

main()