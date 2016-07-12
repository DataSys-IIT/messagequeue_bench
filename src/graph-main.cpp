#include <iostream>
#include "graph.hpp"

int main(int argc, char *argv[])
{
  if(argc == 3)
    start(atoi(argv[1]), atoi(argv[2]));
  else {
    std::cout << "Wrong Arguments\n";
  }
}
