#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>
#include <chrono>

//initialisation of all the necessary arrays for the randomisation process
std::vector<int> myNums = {0, 1, 2, 3, 4, 5, 6, 7};
std::string locationNames[10] = { "Graveyard","Balcony", "Basement", "Hallway", "Kitchen",
								"Stairwell", "Yard", "Secret_Room" };
std::vector<int> numIDs = { 21, 241, 198, 828, 182, 367, 675, 452 };

//shuffle function
void shuffleArrays() {

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();						//seed using a <chrono> library
	std::shuffle(myNums.begin(), myNums.end(), std::default_random_engine(seed));			//shuffle myNums array using the seed
	std::shuffle(numIDs.begin(), numIDs.end(), std::default_random_engine(seed));			//shuffle numIDs array using the seed

}

