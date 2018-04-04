#include "Map.h"

int contains(HashTable* input, Key key) {
	int i;

	for (i = 0; i < input->dim; i++) {
		if (input->key[i] == key) {
			return i;
		}
	}

	return -1;
}

int addRow(HashTable* input, Key key, Value value) {

	if (contains(input, key) >= 0) {
		return -1;
	}
	input->dim++;
	input->value = (Value*)realloc(input->value, sizeof(Value)*((input->dim) + 1));
	input->key = (Key*)realloc(input->key, sizeof(Key)*((input->dim) + 1));
	input->key[input->dim - 1] = key;
	input->value[input->dim - 1] = value;

	return input->dim;
}

HashTable init() {
	HashTable result;

	result.dim = 0;
	result.key = calloc(1, sizeof(Key));
	result.value = calloc(1, sizeof(Value));

	return result;
}

Value get(HashTable* input, Key key) {
	int i;

	for (i = 0; i < input->dim; i++) {
		if (input->key[i] == key) {
			return input->value[i];
		}
	}

	return NULL;
}

int remove(HashTable* input, Key key) {
	int pos;
	if ((pos = contains(input, key)) < 0) {
		return -1;
	}
	while (pos < input->dim) {
		input->key[pos] = input->key[pos + 1];
		input->value[pos] = input->value[pos + 1];
		pos++;
	}
	input->dim--;
	input->value = (Value*)realloc(input->value, sizeof(Value)*input->dim);
	input->key = (Key*)realloc(input->key, sizeof(Key)*input->dim);

	return input->dim;
}

void print(HashTable input) {
	int i;
	for (i = 0; i < input.dim; i++) {
		printf("%d %d \n", input.key[i], input.value[i]);
	}
}
