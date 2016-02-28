#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int key_value;
	int count;
	struct node *left;
	struct node *right;
}node;

node* insert(node *leaf, int key);
node* leftRotate(node *leaf);
node* rightRotate(node *leaf);
node* leafInit(node *leaf, int key);
node* rotate(node* subTree, int key);
int height(node *leaf);
int max(int num, int num1);
int getBalance(node *leaf);
void print(node *leaf, int depth);
int isPermutation(node *tree);

int main() {
	node *tree = NULL;
	int firstBalance, secondBalance;

	tree = insert(tree, 'd');
	tree = insert(tree, 'b');
	tree = insert(tree, 'c');
	firstBalance = getBalance(tree);

	tree = insert(tree, 'd');
	tree = insert(tree, 'b');
	tree = insert(tree, 'c');
	secondBalance = getBalance(tree);

	if( (firstBalance != secondBalance)
		|| (isPermutation(tree) == -1) )
		printf("Is not permutation\n");
	else printf("Is permutation\n");

	return 0;
}
node* leafInit(node *leaf, int key) {
	leaf = (node*)malloc(sizeof(node));
	if (leaf != NULL) {
		leaf->key_value = key;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->count = 1;
	}
	return leaf;
}
node* insert(node *leaf, int key){
	if (leaf == NULL) 
		leaf = leafInit(leaf, key);
	else if (key < leaf->key_value)
		leaf->left = insert(leaf->left, key);
	else if (key > leaf->key_value)
		leaf->right = insert(leaf->right, key);
	else 
		leaf->count++;

	leaf = rotate(leaf, key);

	return leaf;
}
node* rotate(node* subTree, int key) {
	node* temp;
	int balance = getBalance(subTree);
	if (balance < -1) {
		temp = subTree->left;
		if (key > temp->key_value) {
			subTree->left = rightRotate(subTree->left);
			subTree = leftRotate(subTree);
		}
	}
	else if (balance > 1) {
		temp = subTree->right;
		if (key < temp->key_value) {
			subTree->right = leftRotate(subTree->right);
			subTree = rightRotate(subTree);
		}
	}
	else if (balance < -1 && key < subTree->key_value)
		subTree = leftRotate(subTree);
	else if (balance > 1 && key > subTree->key_value)
		subTree = rightRotate(subTree);

	return subTree;
}
node* leftRotate(node *leaf) {
	node *x = leaf->left;
	node *y = x->right;

	x->right = leaf;
	leaf->left = y;

	return x;
}
node* rightRotate(node *leaf) {
	node *x = leaf->right;
	node *y = x->left;

	x->left = leaf;
	leaf->right = y;

	return x;
}
int height(node *leaf) {
	if (leaf == NULL) return 0;
	else return max(height(leaf->left), height(leaf->right)) + 1;
}
int max(int num, int num1) {
	if (num < num1) return num1;
	else return num;
}
int getBalance(node *leaf) {
	return height(leaf->right) - height(leaf->left);
}
int isPermutation(node* tree) {
	if (tree != NULL) {
		if( isPermutation(tree->right) == -1) return -1;
		if (tree->count % 2 != 0) return -1;
		if ( isPermutation(tree->left) == -1) return -1;
	}
}