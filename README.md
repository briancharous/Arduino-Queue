Arduino-Queue
=============

A queue for Arduino implemented in C based on a circular array. This is a queue for bytes, but could be easily modified to handle other datatypes. 

Usage
------
Since this queue is implemented in C and not C++, using it is slightly different for people who are used to more "standard" arduino libraries. 

To use it, first `#include "Queue.h`

Then, allocate a queue and initialize it

	Queue *q = (Queue *)malloc(sizeof(Queue)); 
	alloc(q, 20);

You now have a `Queue` named `q` of size 20 ready to go. 

To enqueue a byte, simply call `enqueue()` on your queue and byte
	
	for (int i=0; i<20; i++) {
		enqueue(q, i);
	}  
	
To dequeue bytes, call `dequeue()` on the queue. For example

	while(q->size > 0) {
    	b = dequeue(q);
    	Serial.println(b);
    }
will remove everything off the queue and print it. 

When you're done with the queue, call `cleanup(q)`.