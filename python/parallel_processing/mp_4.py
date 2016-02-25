#Source Code copied ffrom https://docs.python.org/2/library/multiprocessing.html for practice purposefrom
from multiprocessing import Process
import os

def f(name):
    print ('hello', name)

if __name__ == '__main__':
	
	for i in range(0,4):
		p = Process(target=f, args=('bob',))
		p.start()   
		p.join()