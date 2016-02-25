#Source Code copied ffrom https://docs.python.org/2/library/multiprocessing.html for practice purposefrom

from multiprocessing import Process

def f(name):
    print ('hello', name)

if __name__ == '__main__':
    p = Process(target=f, args=('bob',))
    p.start()
    p.join()