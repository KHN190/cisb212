class Qsort:

	'''Quick Sort'''

	def __init__(self, data):

		self.data = list(data)
		self.cnt = 0

	def Sort(self):

		self.data = self._qsort(self.data)

	def _qsort(self, q):

		if len(q)<=1:
			return q

		less, greater, pivots = [], [], []

		# select pivot
		pivot = q[len(q)/2]

		for i in q:
			
			if i<pivot:
				less.append(i)
			if i>pivot:
				greater.append(i)
			# compare time increases
			if i!=pivot:
				self.cnt += 1

		pivots.append(pivot)

		return self._qsort(less)+pivots+self._qsort(greater)

	def Print(self):

		for i in self.data:
			print i
		print 'compare:', self.cnt

if __name__ == '__main__':

	import random
	data = random.sample(range(1000), 100)

	Q = Qsort(data)
	Q.Sort()

	Q.Print()