#include "adjlist.hpp"
#include <chrono>
#include <thread>
#include <iostream>


adjlist<Meme*> queue;



void goBench(int id) {

}


void start(int numThreads) {
  using std::chrono::duration_cast;
  using std::chrono::nanoseconds;

  typedef std::chrono::high_resolution_clock clock;
  auto start = clock::now();

  std::vector<std::thread*> threads;
  
  for(int i=0;i<numThreads;i++) {
    threads.push_back(new std::thread(&goBench, i));
  }

}
