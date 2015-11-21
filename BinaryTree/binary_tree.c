#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int num;
	struct Tree *right, *left;
} Tree;

void insert(Tree **tree, int num) {
	Tree *temp = NULL;
	if(!(*tree)) {
		if((temp = (Tree *)malloc(sizeof(Tree))) != NULL) {
			temp->right = temp->left = NULL;
			temp->num = num;
			*tree = temp;
			return;
		}
	}

	if(num < (*tree)->num)
		insert(&(*tree)->left, num);
	else if(num > (*tree)->num)
		insert(&(*tree)->right, num);

}

int search_tree(Tree *tree, int num) {
	if(tree != NULL) {
		if(num > tree->num)
			search_tree(tree->right, num);
		else if(num < tree->num)
			search_tree(tree->left, num);
		else
			return num;
	}
	else
		return -1;
}

void print_pre_order(Tree *tree) {
	if(tree != NULL) {
		printf("%d \n", tree->num);
		print_pre_order(tree->left);
		print_pre_order(tree->right);
	}
}

int height_tree(Tree *tree) {
	if (tree == NULL)
		return -1;
	else {
		int hl = height_tree(tree->left);
		int hr = height_tree(tree->right);
		if (hl < hr)
			return hr + 1;
		else
			return hl + 1;
	}
}

int main() {
	Tree *tree = NULL;
	int num, opt, result;

	do {
		printf("\n1) Insert number");
		printf("\n2) Print pro order");
		printf("\n3) Search number");
		printf("\n4) Height of tree");
		scanf("%i", &opt);

		switch(opt) {
			case 1:
				printf("\nEnter an integer");
				scanf("%i", &num);
				insert(&tree, num);
			break;

			case 2:
				print_pre_order(tree);
			break;

			case 3:
				printf("\nEnter an integer");
				scanf("%i", &num);
				result = search_tree(tree, num);

				if(result != -1)
					printf("\n Number found is: %i", result);
				else
					printf("\n Number not found");
			break;

			case 4:
				result = height_tree(tree);
				printf("\nHeight of tree is: %i", result);
			break;

			default: break;
		}

	} while(opt != 0);

}
