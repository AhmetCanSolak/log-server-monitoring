#include <bits/stdc++.h>
#include "helperFunctions.h"
#include "dbFunctions.h"

int main(int argc, char const *argv[]) {

  // std::clock_t begin = clock();
  //Initializations
  std::ios_base::sync_with_stdio (false);
  std::cin.tie(0);

  //createTable();
  std::ifstream infile("data/sample.log");
  int i = 1; current_log.totalNumOfBytesOverall = 0;

  while(std::getline(infile, current_log.line)){
    decode();

    push(i);
    //commitToDB(i+1);
    i++;
  }
  current_log.totalNumOfLines = i;

  display();
  std::cout << "End of the database generation from logfile...\nProgram will continue with visualization script...\n";

  // std::clock_t end = clock();
  // double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  // std::cout << "Total time: " << elapsed_secs << std::endl;

  return 0;
}
