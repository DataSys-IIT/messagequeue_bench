#include "adjlist.hpp"
#include <chrono>
#include <thread>
#include <iostream>


adjlist<Meme*> queue;


int errorcount = 0;


void fill(int id, int count) {
  for(int x=0;x<count;x++) {
    Meme * m = new Meme();
    queue.listAt(0)->push(m);
  }
}

void empty(int id) {
  while(queue.listAt(0)->empty()) {
    Meme * m;
    bool result = queue.listAt(0)->pop(m);
    if(!result)
      errorcount++;
  }
}


void start(int numThreads, int count) {
  using std::chrono::duration_cast;
  using std::chrono::nanoseconds;

  typedef std::chrono::high_resolution_clock clock;
  auto start = clock::now();

  std::vector<std::thread*> threads;
  
  for(int i=0;i<numThreads;i++) {
    threads.push_back(new std::thread(&fill, i, count));
  }

}
