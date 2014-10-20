class ShellSort:

	def  __init__(self, data):
		
		self.data = list(data)
		self.cnt = 0

	def _inc(self, n):

		return int(round(n/2))

	def Sort(self):
		
		n = len(self.data)
		a = self.data
		inc = self._inc(n)

		while inc>0:

			for i in range(inc, n):
				t = a[i]
				j = i
				while j>=inc and a[j-inc]>t:
					a[j] = a[j-inc]
					j -= inc
					# count moves
					self.cnt += 1
				a[j] = t

			inc = self._inc(inc)

		self.data = a

	def Print(self):

		for i in self.data:
			print i
		print 'moves:', self.cnt


if __name__ == '__main__':
	
	import random
	data = random.sample(range(1000), 100)

	S = ShellSort(data)
	S.Sort()
	S.Print()