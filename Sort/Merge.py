class MergeSort:

	'''Top-down MergeSort'''

	def __init__(self, data):

		self.data = list(data)

	def Sort(self):

		self.data = self._MergeSort(self.data)

	def _MergeSort(self, data):

		# undividable
		if len(data)<=1:
			return data

		n = len(data)/2
		# left
		left = [x for x in data[:n]]
		left = self._MergeSort(left)
		# right
		right = [x for x in data[n:]]
		right = self._MergeSort(right)

		return self._Merge(left, right)

	def _Merge(self, left, right):

		res = []

		while len(left) or len(right):

			# both not empty
			if len(left) and len(right):
		
				if left[0]<=right[0]:
					res.append(left[0])
					left = left[1:]
				else:
					res.append(right[0])
					right = right[1:]

			# right is empty
			elif len(left):
				res.append(left[0])
				left = left[1:]
			# left is empty
			elif len(right):
				res.append(right[0])
				right = right[1:]

		return res

	def Print(self):

		for i in self.data:
			print i

if __name__ == '__main__':
	
	import random
	data = random.sample(range(1000), 100)

	M = MergeSort(data)
	M.Sort()

	M.Print()