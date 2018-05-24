import os
from FileManager import FileManager

class _CmakeHelper:
	def createIncludeDirsFile(self, saveTo, source = '.'):
		dirs = FileManager.dirs(source)
		file = open(saveTo, 'w+')
		for dir in dirs:
			file.write('include_directories(' + dir + ')\n')
		file.close()

CmakeHelper = _CmakeHelper();	