class Node:

	def __init__(self, key):

		self.next = None
		self.key = key

class Insertion:

	def __init__(self):

		self.list = None
		self.cnt = 0

	def put(self, key):

		if not self.list:

			self.list = Node(key)
			return

		self.list = self._put(self.list, key)

	def _put(self, node, key):

		# count moves
		self.cnt += 1

		if not node.key:
			
			node.key = key
			return self.list

		if not node.next or node.next.key>key:

			new = Node(key)
			new.next = node.next
			node.next = new

		else:
			self._put(node.next, key)

		return self.list


	def Print(self):

		self._Print(self.list)

	def _Print(self, node):

		if not node:
			print 'moves:', self.cnt
			return
			
		print node.key
		self._Print(node.next)

	def Find(self, key):

		return self._Find(self.list, key)

	def _Find(self, node, key):

		if not node:
			return False

		while node.key<key:
			
			if not node.next:
				return False
			node = node.next

		if node.key == key:
			return True

		if node.key>key:
			return False

import random

if __name__ == '__main__':
	
	L = Insertion()

	data = random.sample(range(1000), 100)

	for i in data:
		L.put(i)

	L.Print()