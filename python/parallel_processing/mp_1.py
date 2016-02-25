#Source Code copied ffrom https://docs.python.org/2/library/multiprocessing.html for practice purposefrom

from multiprocessing import Pool

def f(x):
    return x*x

if __name__ == '__main__':
    p = Pool(5)
    print(p.map(f, [1, 2, 3]))