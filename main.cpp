#include <iostream>
#include <string>

#include "Support/support.h"

int main() {
    std::cout
            << "To generate a labyrinth, please enter its width x height (example 7 x 3).\nThe default is 5 x 5.\nInput : ";
    std::string input;
    std::getline(std::cin, input);

    findWidthAndHeight(input);
    std::cout << "\n" << width << " x " << height << "\n";

    system("PAUSE");

    return 0;
}
