/* 
 
Arduino Queue
A library in C that implements a queue of arbitrary size based on a circular array
Copyright (c) 2013 Brian Charous

 
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
                                              "License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
 
*/

#include "Queue.h"

void alloc(Queue *queue, int memorySize) {
    // allocate the queue
	queue->memorySize = memorySize;
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
	queue->array = (byte *)malloc(memorySize * sizeof(byte));
}

void cleanup(Queue *queue) {
    // cleanup the queue and free it's memory
	free(queue->array);
	queue->memorySize = 0;
	queue->size = 0;
}

int enqueue(Queue *queue, byte value) {
    // enqueue a byte onto the queue. returns 1 if success, 0 if it couldn't add it
	if (queue->size == queue->memorySize) {
		return 0; // full
	}
	queue->array[queue->tail] = value;
	queue->tail = (queue->tail + 1) % queue->memorySize;
	queue->size++;

	return 1;
}

byte dequeue(Queue *queue) {
    // dequeue a byte off the queue
	byte *b = queue->array[queue->head];
	queue->head = (queue->head + 1) % queue->memorySize;
	queue->size--;
	return b;
}

int full(Queue *queue) {
	return queue->memorySize != queue->size;
}