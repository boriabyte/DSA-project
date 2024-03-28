#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>
#include <chrono>

//either 0 or 1 function
int rand50() {

	return rand() & 1;
}

int rand75() {

	return rand50() | rand50();
}

