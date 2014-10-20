class Node(object): 

	def __init__(self, key): 

		self.key = key 
		self.left = None 
		self.right = None 
		self.height = 0 

	def __str__(self):

		return str(self.key)

class AVLTree(object): 

	def __init__(self): 

		self.root = None

	def find(self, key): 

		if self.root is None: 
			return None 
		else: 
			return self._find(key, self.root)

	def _find(self, key, node): 

		if node is None: 
			return None 
		elif key<node.key: 
			return self._find(key, self.left) 
		elif key>node.key: 
			return self._find(key, self.right) 
		else: 
			return node

	def findMin(self): 

		if self.root is None: 
			return None 
		else: 
			return self._findMin(self.root)

	def _findMin(self, node): 

		if node.left: 
			return self._findMin(node.left) 
		else: 
			return node

	def findMax(self): 

		if self.root is None: 
			return None 
		else: 
			return self._findMax(self.root)

	def _findMax(self, node): 

		if node.right: 
			return self._findMax(node.right) 
		else: 
			return node

	def height(self, node): 

		if node is None: 
			return -1 
		else: 
			return node.height

	def singleLeftRotate(self, node): 

		k1 = node.left 
		node.left = k1.right 
		k1.right = node 

		node.height = max(self.height(node.right), self.height(node.left))+1 
		k1.height = max(self.height(k1.left), node.height)+1 

		return k1

	def singleRightRotate(self, node): 

		k1 = node.right 
		node.right = k1.left 
		k1.left = node 

		node.height = max(self.height(node.right), self.height(node.left))+1 
		k1.height = max(self.height(k1.right), node.height)+1 

		return k1

	def doubleLeftRotate(self, node): 

		node.left = self.singleRightRotate(node.left) 
		return self.singleLeftRotate(node)

	def doubleRightRotate(self, node):

		node.right = self.singleLeftRotate(node.right) 
		return self.singleRightRotate(node)

	def insert(self, key): 
		
		if not self.root: 
			self.root = Node(key) 
		else: 
			self.root = self._insert(key, self.root)

	def _insert(self, key, node): 
		
		if node is None: 
			node = Node(key) 

		elif key<node.key: 

			node.left = self._insert(key, node.left) 

			if (self.height(node.left)-self.height(node.right)) == 2: 
				if key<node.left.key: 
					node = self.singleLeftRotate(node) 
				else: 
					node = self.doubleLeftRotate(node) 
		elif key>node.key: 

			node.right = self._insert(key, node.right) 

			if (self.height(node.right)-self.height(node.left)) == 2: 
				if key<node.right.key: 
					node = self.doubleRightRotate(node) 
				else: 
					node = self.singleRightRotate(node) 
		
		node.height = max(self.height(node.right), self.height(node.left))+1 
		
		return node

	def printTree(self):

		self._printTree(self.root)

	def _printTree(self, node):

		if not node: return
		self._printTree(node.left)
		print node
		self._printTree(node.right)

if __name__ == '__main__':

	with open('data10000')as f:
		data = f.readlines()[0].split()
	data = [long(i) for i in data]

	T  =  AVLTree()
	for i in data:
		T.insert(i)

	T.printTree()
	print T.height(T.root)