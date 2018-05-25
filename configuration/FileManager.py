import os

class _FileManager:

	@property
	def currentDir(self):
		return os.getcwd()

	def dirs(self, path='.', prefix=''):
		result = []
		for root, dirs, files in os.walk(path):
			if root.startswith(".\\") and not root[2:].startswith('.git'):
				result.append(prefix + root[2:].replace('\\', '/'))
		return result
	
FileManager = _FileManager();	
