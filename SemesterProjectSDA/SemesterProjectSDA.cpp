
/*You are a video game developer at your favorite studio and have been tasked with creating the layout of the map in a game you’ve been
working on, using names and IDs for each location.They are fed to you by another developer tasked with this,
who decided that the best way to do this would be using a simple linked list.

Obviously, all these locations of the level have certain names and number IDs assigned to them. They must be considered when designing the map.
The only condition that you’ve been told is that the sections “Inner Chamber” and “Outer Chamber” must be the first and respectively the last locations
you need to consider.

Thinking about it, you’ve decided that the best way to go about this is to assign these types of data in a tree (chain) manner
in the system memory so that they can be accessed faster. Coincidentally, where they are assigned relative to their parent (either left or right)
will also be their “real-time” locations in the game, relative to the first location when entering the level (i.e., “Inner Chamber”).
Luckily, you don’t have any further criteria after which you need to guide yourself in terms of the position of these locations,
so they are all arbitrary.

(IDs are to be randomly generated using the randomisation functions. Keep in mind that “Inner Chamber” and “Outer Chamber” must be the first
and respectively last entries as they are the first and respectively last locations in the map.)
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>			
#include <chrono>							//time related library used for seeding randomisation functions
#include "structPrint.h"					//necessary stuctures and the print function 
#include "auxArrays.h"						//auxiliary arrays used for randomisation
#include "rand.h"							//custom-made random generation function: either 1 (%75) or 0 (25%)

void createList(int ID, std::string& location) {

	LIST *ptr = new LIST;
	ptr->locIDList = ID;
	ptr->locNameList = location;
	ptr->next = NULL;

	if (head == NULL) {
		head = ptr;
		tail = ptr;
	}
	else {
		tail->next = ptr;
		tail = ptr;
	}
}

//insertion function
void insertIntoList() {

	int index = 0;

	//for loop for making sure inner_chamber and outer_chamber are last into list
	for (index = 0; index < 10; index++) {

		if (index == 0){
			int locIDList = 0;
			std::string locNameList = "Inner_Chamber";
			createList(locIDList, locNameList);
		}
		else if (index > 0 && index < 9) {

			int locIDList = 0;
			std::string locNameList = { 0 };

			locIDList = numIDs[myNums[index - 1]];
			locNameList = locationNames[myNums[index - 1]];
			createList(locIDList, locNameList);
		}
		else if (index == 9) {
			int locIDList = 1000;
			std::string locNameList = "Outer_Chamber";
			createList(locIDList, locNameList);
		}
	}
}

//print function
void printList() {

	std::cout << "Data has been fed into tray." << std::endl;
	std::cout << std::endl;
	std::cout << "Final list configuration: " << std::endl;
	std::cout << std::endl;

	LIST* temp = head;

	while (temp) {

		std::cout << temp->locIDList << " " << temp->locNameList << std::endl;
		temp = temp->next;
	}

	std::cout << std::endl;

}

//create tree/chain function
void createTree(int ID, std::string& location) {

	TREE* ptr = new TREE;
	ptr->locIDTree = ID;
	ptr->locNameTree = location;
	ptr->right = ptr->left = NULL;

	//no tree, create a root
	if (root == NULL) {

		level++;
		root = ptr;
		aux = root;
	}
	else {

		//chance can either have 0 or 1 (25%/75% chance)
		int chance = rand75();

		//if chance = 1 put to right of parent
		if (chance == 1) {
			
			level++;
			aux->right = ptr;
			aux = aux->right;
		}

		//if chance = 0 put to left of parent
		if (chance == 0) {

			level++;
			aux->left = ptr;
			aux = aux->left;
		}
	}

	//make sure outer_chamber is last in the tree/chain
	if (level == 10) {

		aux->locIDTree = 1000;
		aux->locNameTree = "Outer_Chamber";
	}

}

//tree insertion function
void insertIntoTree() {

	LIST *temp = NULL;

	//for loop for parsing the list and assigning each node of the tree/chain the necessary parts of the strucutres
	for (temp = head; temp; temp = temp->next) 
		createTree(temp->locIDList, temp->locNameList);
}

int main() {

	//call of all functions
	std::cout << "Press 1 to run, or any key to exit.\n";

	int cmd = 0;
	std::cin >> cmd;
	std::cout << "\n";

	if (cmd == 1) {

		shuffleArrays();
		insertIntoList();
		printList();
		insertIntoTree();
		std::cout << "Final map configuration: " << std::endl;
		std::cout << std::endl;
		printTreePreorder(root);
	}
	else {

		return 0;
	}
	return 0;
}