class Monkey:
	ID = 0
	items = []											# items held to be inspected (worry levels stored)
	operation = lambda a : a * 1						# operation to do on inspection
	test = lambda a : True if a % 2 == 0 else False		# test to see worry level
	true = 0											# which monkey ID to pass to if test True
	false = 0											# which monkey ID to pass to if test False
	def __init__(self, id):
		self.ID = id
	
	def setItems(self, newItems:list[int]):
		self.items = newItems

	def setOperation(self, newOp):
		self.operation = newOp

	def setTest(self, newTest):
		self.test = newTest

	def setTrueFalse(self, ifTrue, ifFalse):
		self.true = ifTrue
		self.false = ifFalse
		
class Group:
	monkeys = []
	def __init__(self, contents:list[str]):
		currentMonkey = Monkey(0)
		for fullLine in contents:
			# remove ':' and ',', remove begining whitespace, then split on ' '
			line = fullLine.replace(':', '').replace(',', '').lstrip().split(' ')

			if line[0] == "Monkey":
				currentMonkey = Monkey(int(line[1]))
			elif line[0] == "Starting":
				items = []
				for i in range(2, len(line)):
					items.append(int(line[i]))
				currentMonkey.setItems(items)
			elif line[0] == "Test":
				if line[1] == "divisible":
					div = int(line[3])
					currentMonkey.setTest(lambda a, d=div : True if a % d == 0 else False)
			elif line[0] == "Operation":
				pass
			elif line[0] == "If":
				pass
			# print(line)

def main():
	eg1 = "example"
	eg2 = "example2"
	inp = "input"
	filename = eg1
	f = open(filename, "r")
	contents = f.read().split("\n")
	
	monkeyGroup = Group(contents)

main()