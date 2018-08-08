import os
import sys
import platform
import subprocess

class Arguments:
    def has(flag_name):
        for arg in sys.argv:
            if arg == flag_name:
                return True
        return False

    def get(index):
        return sys.argv[index]

    def count():
        return len(sys.argv)

class Shell:

    def run(commands = [], *args):
        child = subprocess.Popen(commands, stdout=subprocess.PIPE)
        while child.poll() is None:
            output_line = child.stdout.readline()
            if (output_line):
                print(output_line.decode("utf-8")[:-1])
        code = child.returncode
        if (code):
            os.sys.exit(code)

    def get(commands = [], *args):
        child = subprocess.Popen(commands, stdout=subprocess.PIPE)
        result = ""
        while child.poll() is None:
            output_line = child.stdout.readline()
            if (output_line):
                result += output_line.decode("utf-8")[:-1]
        code = child.returncode
        if (code):
            os.sys.exit(code)
        return result


class Status:

    system = platform.system()

    def check(package):
        return package in Status.pipList

    def compiler():
        if Status.system == 'Windows':
            return 'Visual Studio 15 2017 Win64'
        if Status.system == 'Darwin':
            return 'Xcode'
        return 'Unix Makefiles'

class Setup:

    def setupConan():
        os.system('conan remote add bincraftes      https://api.bintray.com/conan/bincrafters/public-conan')
        os.system('conan remote add pocoproject     https://api.bintray.com/conan/pocoproject/conan')
        os.system('conan remote add conan-community https://api.bintray.com/conan/conan-community/conan')

