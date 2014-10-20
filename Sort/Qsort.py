def swap(a, b):
	return b, a

class Qsort:

	'''Quick Sort'''

	def __init__(self, data):

		self.data = list(data)
		self.cnt = 0

	def Sort(self):

		#self.data = self._qsort(self.data)
		self.data = self._qsort2(self.data, 0, len(self.data)-1)

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

	def _part(self, a, left, right, i):

		m = left # initiate
		p = a[i] # assign pivot

		# move pivot to last
		a[i], a[right] = swap(a[i], a[right])

		# compare in the range
		for n in range(left, right):
			if a[n]<p:
				a[m], a[n] = swap(a[m], a[n])
				m += 1
				self.cnt += 1
		# last move of pivot
		a[m], a[right] = swap(a[m], a[right])

		return m

	def _qsort2(self, a, left, right):
		
		if left<right:

			index = self._part(a, left, right, (left+right)/2)

			a = self._qsort2(a, left, index-1)
			a = self._qsort2(a, index+1, right)

		return a

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