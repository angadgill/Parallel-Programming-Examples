#Source Code copied from examples in https://pymotw.com/2/threading/
import threading

def worker():
    """thread worker function"""
    print ('Worker')
    return

threads = []
for i in range(5):
    t = threading.Thread(target=worker)
    threads.append(t)
    t.start()