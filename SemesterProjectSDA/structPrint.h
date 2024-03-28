#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>
#include <chrono>


//necessary structures
typedef struct tree {

	int locIDTree = 0;
	std::string locNameTree = { 0 };
	struct tree* right = NULL;
	struct tree* left = NULL;

}TREE;

typedef struct list {

	int locIDList = 0;
	std::string locNameList = { 0 };
	struct list* next = NULL;

}LIST;


//init of pointers and useful variables
TREE* root = NULL;
TREE* aux = NULL;
int level = 0;
int height = 0;

LIST* head = NULL;;
LIST* tail = NULL;

//preorder print function of tree using "manual indentation"; will improve in future; may work with setw()
void printTreePreorder(TREE* root) {

	if (root == NULL)
		return;

	if (height == 0) {

		aux = root;
		std::cout << "     " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 1 && (aux->right)) {

		aux = aux->right;
		std::cout << "                      " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 1 && (aux->left)) {

		aux = aux->left;
		std::cout << "  " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 2 && (aux->right)) {

		aux = aux->right;
		std::cout << "                      " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 2 && (aux->left)) {

		aux = aux->left;
		std::cout << "  " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 3 && (aux->right)) {

		aux = aux->right;
		std::cout << "              " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 3 && (aux->left)) {

		aux = aux->left;
		std::cout << " " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 4 && (aux->right)) {

		aux = aux->right;
		std::cout << "                           " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 4 && (aux->left)) {

		aux = aux->left;
		std::cout << "      " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 5 && (aux->right)) {

		aux = aux->right;
		std::cout << "                 " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 5 && (aux->left)) {

		aux = aux->left;
		std::cout << "     " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 6 && (aux->right)) {

		aux = aux->right;
		std::cout << "               " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 6 && (aux->left)) {

		aux = aux->left;
		std::cout << "     " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 7 && (aux->right)) {

		aux = aux->right;
		std::cout << "                               " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 7 && (aux->left)) {

		aux = aux->left;
		std::cout << "   " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 8 && (aux->right)) {

		aux = aux->right;
		std::cout << "                         " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 8 && (aux->left)) {

		aux = aux->left;
		std::cout << "             " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 9 && (aux->right)) {

		aux = aux->right;
		std::cout << "                                               " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 9 && (aux->left)) {

		aux = aux->left;
		std::cout << "     " << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 10 && (aux->right)) {

		aux = aux->right;
		std::cout << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}
	if (height == 10 && (aux->left)) {

		aux = aux->left;
		std::cout << aux->locNameTree << " " << "(" << aux->locIDTree << ")" << std::endl;
		std::cout << std::endl;
		height++;
	}

	printTreePreorder(root->left);
	printTreePreorder(root->right);

}

