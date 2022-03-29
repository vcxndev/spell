#include <iostream>
#include "spell.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		return 0;
	}
	std::vector<std::string>heces = spell(argv[1]);
	
	for (unsigned int i = 0; i < heces.size(); ++i) {
		std::cout << heces[i] << "\n";
	}

	return 0;
}