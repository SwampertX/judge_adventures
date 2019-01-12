t = int(input())
list_count = 0
while t!=0:
	list_count += 1;
	d = {}
	for i in range(t):
		s = [x.lower() for x in input().split(' ')]
		animal = s[-1]
		if animal not in d:
			d[animal]=1
		else:
			d[animal] += 1
	print(f"List {list_count}:")
	for i in sorted(d.keys()):
		print(f"{i} | {d[i]}")
	t = int(input())