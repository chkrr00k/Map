#pragma once
#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

//redefine this with the new types you want;
typedef int Value;
typedef int Key;

typedef struct HashTable {
	Value* value;
	Key* key;
	int dim;
} HashTable;

//check if the key is rapresented in the HashTable
// return the position or -1;
int __cdecl contains(HashTable* input, Key key);

//adds a new record to the HashTable, needs a kew and a value;
//returns the new dim of the HashTable or -1;
int __cdecl addRow(HashTable* input, Key key, Value value);

//return a new empty HashTable;
HashTable __cdecl init();

//get the value that match with the passed key or NULL if none;
Value __cdecl get(HashTable* input, Key key);

//remove the value that match with the key and returns new dim or -1;
int __cdecl remove(HashTable* input, Key key);

//print the HashTable NOTE: works just for int,int if not changed;
void __cdecl print(HashTable input);

#endif // !MAP_H
