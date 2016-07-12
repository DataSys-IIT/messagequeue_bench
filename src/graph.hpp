#include "adjlist.hpp"
#include <chrono>
#include <thread>
#include <iostream>


adjlist<Meme*> queue;

int errorcount = 0;


  using std::chrono::duration_cast;
  using std::chrono::nanoseconds;
    
 
  std::chrono::time_point<std::chrono::system_clock> timestart;
void fill(int id, int count) {
  if(id==0) {
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    std::cout << "Filling single test queue\n"; 
    timestart = std::chrono::high_resolution_clock::now();
  }

  for(int x=0;x<count;x++) {
    Meme * m = new Meme();
    queue.listAt(0)->push(m);
  }
  if(id==0) {    
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
  

 
    std::cout << "Emptying single test queue\n";
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Finished in " << (double)(end-timestart).count()/1000000000.00 <<  " sec\n";

    timestart = std::chrono::high_resolution_clock::now();
    
  }

  while(queue.listAt(0)->empty()) {
    Meme * m;
    bool result = queue.listAt(0)->pop(m);
    if(!result)
      errorcount++;
  }

  if(id==0) {
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    
    typedef std::chrono::high_resolution_clock clock;
 
    auto end = clock::now();
    std::cout << "Finished in " << (double)(end-timestart).count()/1000000000.00 <<  " sec\n";
  }
}

void empty(int id) {
  
}


void start(int numThreads, int count) {
  
  std::vector<std::thread*> threads;
  queue.addRows(1);
  for(int i=0;i<numThreads;i++) {
    threads.push_back(new std::thread(&fill, i, count/numThreads));
  }
  for(int i=0;i<numThreads;i++) {
    threads[i]->join();
  }

}
