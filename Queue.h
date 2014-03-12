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

#include <Arduino.h>

#ifdef __cplusplus
 extern "C" {
#endif

struct Queue {
	byte *array;
	int memorySize;
	int size;
	int head;
	int tail;
	int full;
};

typedef struct Queue Queue;

void alloc(Queue *queue, int memorySize);
void cleanup(Queue *queue);
int enqueue(Queue *queue, byte value);
byte dequeue(Queue *queue);
int full(Queue *queue);
#ifdef __cplusplus
}
#endif