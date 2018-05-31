import os
import platform
import subprocess

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

    pipList = Shell.get(['pip', 'freeze'])
    system = platform.system()

    def check(package):
        return package in Status.pipList

    def conanIsSetUp():
        remotes = Shell.get(['conan', 'remote', 'list'])
        return  (
            'conan-center' in remotes and
            'bincraftes' in remotes and
            'conan_community' in remotes
        )

    def compiler():
        if Status.system == 'Windows':
            return 'Visual Studio 15 2017 Win64'
        if Status.system == 'Darwin':
            return 'Xcode'


class Setup:

    def checkAndInstall(package):
        if Status.check(package):
            return
        Setup.install(package)

    def setupConan():
        os.system('conan remote add bincraftes      https://api.bintray.com/conan/bincrafters/public-conan')
        os.system('conan remote add pocoproject     https://api.bintray.com/conan/pocoproject/conan')
        os.system('conan remote add conan-community https://api.bintray.com/conan/conan-community/conan')

    def install(package):
        Shell.run(['pip', 'install', package])

    def runConan():
        Shell.run(['conan', 'install', '-g', 'cmake_multi', '.','--build=outdated', '--install-folder=build', '-s', 'build_type=Debug'])
        Shell.run(['conan', 'install', '-g', 'cmake_multi', '.','--build=outdated', '--install-folder=build', '-s', 'build_type=Release'])


    def reset():
        Shell.run(['pip', 'uninstall', 'conan', '--y'])
        Shell.run(['pip', 'uninstall', 'cmake', '--y'])
