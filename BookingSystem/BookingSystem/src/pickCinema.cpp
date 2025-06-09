#include "../include/pickCinema.h"



void pickCinema::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Where would you like to watch a movie?\n";
    getCities();


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
}

void pickCinema::actionHandler(PageHandler& pages) {


}

