all: pthread_mutex 

pthread_mutex:
	g++ pthread_mutex_example.cpp -pthread -o pthread_mutex_example.o -Wno-int-to-void-pointer-cast