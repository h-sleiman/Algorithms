#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int height;
	int value;
	int repeat;
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
int solution(int A[], int N);
int addSubTree(node* subTree);

int main() {
	int A[] = { -1,3,-4,5,1,-6,2,1 };
	int N = sizeof(A) / sizeof(A[0]);

	printf("equilibrium index: %d\n", equilibriumIndex(A, N));

	return 0;
}
int equilibriumIndex(int A[], int N) {
	int i, newRoot = 1;
	
	while (newRoot < N) {
		node *leftTree = NULL;
		node *rightTree = NULL;
		for (i = 0; i < N; i++) {
			if (i == newRoot) continue;
			if (i < newRoot) leftTree = insert(leftTree, A[i]);
			if (i >= newRoot) rightTree = insert(rightTree, A[i]);
		}

		if (addSubTree(leftTree) == addSubTree(rightTree)) return newRoot;
		free(leftTree);
		free(rightTree);
		newRoot++;
	}

	return 0;
}
int addSubTree(node* subTree) {
	if (subTree == NULL)
		return 0;
	else return (subTree->value * subTree->repeat) + addSubTree(subTree->left) + addSubTree(subTree->right);
}
node* leafInit(node *leaf, int key) {
	leaf = (node*)malloc(sizeof(node));
	if (leaf != NULL) {
		leaf->value = key;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->height = 1;
		leaf->repeat = 1;
	}
	return leaf;
}
node* insert(node *leaf, int key) {
	if (leaf == NULL) {
		leaf = leafInit(leaf, key);
		leaf->height = height(leaf);
	}
	else if (key < leaf->value)
		leaf->left = insert(leaf->left, key);
	else if (key > leaf->value)
		leaf->right = insert(leaf->right, key);
	else leaf->repeat++;

	leaf = rotate(leaf, key);

	return leaf;
}
node* rotate(node* subTree, int key) {
	node* temp;
	int balance = getBalance(subTree);
	if (balance < -1) {
		temp = subTree->left;
		if (key > temp->value) {
			subTree->left = rightRotate(subTree->left);
			subTree = leftRotate(subTree);
		}
	}
	else if (balance > 1) {
		temp = subTree->right;
		if (key < temp->value) {
			subTree->right = leftRotate(subTree->right);
			subTree = rightRotate(subTree);
		}
	}
	else if (balance < -1 && key < subTree->value)
		subTree = leftRotate(subTree);
	else if (balance > 1 && key > subTree->value)
		subTree = rightRotate(subTree);

	return subTree;
}

node* leftRotate(node *leaf) {
	node *x = leaf->left;
	node *y = x->right;

	x->right = leaf;
	leaf->left = y;

	x->height = height(x);
	leaf->height = height(leaf);

	return x;
}
node* rightRotate(node *leaf) {
	node *x = leaf->right;
	node *y = x->left;

	x->left = leaf;
	leaf->right = y;

	x->height = height(x);
	leaf->height = height(leaf);

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