// This is start of the header guard.  helperFunctions_H can be any unique name.  By convention, we use the name of the header file.
#ifndef helperFunctions_H
#define helperFunctions_H

// This is the content of the .h file, which is where the declarations go
struct log_t {
  int totalNumOfLines;
  std::string line;

  std::string userIP;
  std::string eventTime;
  std::string requestMethod;
  std::string contentAddress;
  std::string contentID;
  long double contentBitRate;
  std::string contentType;
  int httpStatus;
  int totalNumOfBytes;
  std::string userAgent;
  std::string cacheStatus;

  std::set<std::string> userIPVector;
  std::multimap<std::string,int> userIPMM;
  std::multimap<char,int> httpStatusMM;
  std::multimap<std::string,int> userAgentMM;
  std::set<std::string> userAgentVector;
  std::multimap<int,int> contentBitRateMM;
  std::set<int> contentBitRateVector;
  std::set<std::string> contentIDVector;
  std::multimap<std::string,int> contentIDMM;
  float totalNumOfBytesOverall;
};

extern struct log_t current_log;        // Extern one struct to use in all .cpp files

void decode();                          // function prototype
void push(int i);                       // function prototype
void display();                         // function prototype

// This is the end of the header guard
#endif
