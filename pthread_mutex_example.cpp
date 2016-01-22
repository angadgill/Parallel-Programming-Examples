/*
This file shows a trivial example for using a mutex lock.
 
Author: Angad Gill
*/

// Import requird libraries
#include <iostream>
#include <pthread.h>

// Set namespace so don't have to type "std::" with "cout"
using namespace std;

// Declare lobal mutex variable. This should not be a pointer!
pthread_mutex_t mymutex;

// Declaration of a function which has 'void *' argument and returns 'void *'
void * hello(void * index);

// Main function
int main()
{
	// Initialize thread and mutex variables
	cout << "This file shows a trivial example for using a mutex lock." << endl;
	int NUM_THREADS = 5;
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&mymutex, NULL);
	int i;

	// Create threads	
	for (i=0; i<NUM_THREADS; i++){
		pthread_create(&threads[i], NULL, hello, (void *)i);
	}

	// Wait for threads to finish processing and "join" the main thread
	for (i=0; i<NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
		
	}

	// Destroy the mutex before exiting the main function
	pthread_mutex_destroy(&mymutex);
	return 0;
}

// Implementation of the hello function
void * hello(void * index)
{
	// Argument needs to be typecasted to 'int *'
	int * i = (int *) index;

	// Acquire lock
	pthread_mutex_lock(&mymutex);
	// Do something
	cout << "Hey, my index is " << i << endl;
	// Release lock
	pthread_mutex_unlock(&mymutex);

	// Even though this funtion returns a 'void *', 
	// add 'return 0' here as a fail safe
	return 0;
}
