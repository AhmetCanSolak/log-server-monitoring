// This code snippet written for helper functions needed for log parsing
#include <bits/stdc++.h>
#include "helperFunctions.h"

float bytesToGB = 1073741824;         // Number of Bytes per Gigabyte.
//float bytesToGB = 1000000000;       // Use either of them according to your reference

log_t current_log;                    // Compiler would link all current_log references to here.

/* This function is just a helper function for decode() function.
   It check whether a string consist only digits or not. */
bool has_only_digits(const std::string s){
  return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

/* This function is where get information from our models and structures
   and write them down into files in results/data/ . */
void display() {

  std::ofstream file_writer;
  file_writer.open ("results/data/histograms.txt");

  // BitRate histogram
  std::multimap<int,int> mymm2 = current_log.contentBitRateMM;
  for (auto ch:current_log.contentBitRateVector){
    if(mymm2.count(ch) > 0){
      file_writer << mymm2.count(ch) * (100.0 / current_log.totalNumOfLines) << " ";
    }
  }
  file_writer << "\n";
  for (auto ch:current_log.contentBitRateVector){
    if(mymm2.count(ch) > 0){
      file_writer << ch << " ";
    }
  }
  file_writer << "\n";

  // HTTP status histogram
  std::multimap<char,int> mymm = current_log.httpStatusMM;
  int possible_status[] = {200,201,202,203,204,205,206,/*207,226,*/
                           300,301,302,304,305,/*307,308,*/
                           400,401,402,403,404,405,406,407,408,409,/*410,411,412,413,414,415,416,417,*/418/* I'm a Teapot :D */,/*420,422,423,424,425,426,428,429,431,444,449,450,451,499,*/
                           500,501,502,503,504,505/*,506,507,508,509,510,511,598,599*/};
  for (auto ch:possible_status){
    if(mymm.count(ch) > 0){
      file_writer << mymm.count(ch) * (100.0 / current_log.totalNumOfLines) << " ";
    }
  }
  file_writer << "\n";
  for (auto ch:possible_status){
    if(mymm.count(ch) > 0){
      file_writer << ch << " ";
    }
  }
  file_writer << "\n";

  // Browser type histogram
  std::multimap<std::string,int> mymm1 = current_log.userAgentMM;
  for (auto ch:current_log.userAgentVector){
    if(mymm1.count(ch) * (100.0 / current_log.totalNumOfLines) > 1){
      file_writer << mymm1.count(ch) * (100.0 / current_log.totalNumOfLines) << " ";
    }
  }
  file_writer << "\n";
  for (auto ch:current_log.userAgentVector){
    if(mymm1.count(ch) * (100.0 / current_log.totalNumOfLines) > 1){
      file_writer << ch << "\n";
    }
  }
    file_writer.close();
    file_writer.open ("results/data/numeric_values.txt");

    file_writer << current_log.userIPVector.size() << "\n";
    file_writer << current_log.contentIDVector.size() << "\n";
    file_writer << current_log.totalNumOfBytesOverall << "\n";

    // UserIP mode
    int max = 0;
    std::string mostViewer="";
    std::multimap<std::string,int> mymm4 = current_log.userIPMM;
    for (auto ch:current_log.userIPVector){
      if(mymm4.count(ch) > max){
        mostViewer = ch;
      }
    }
    file_writer << mostViewer << "\n";

    // UserIP mode
    max = 0;
    std::string mostViewed="";
    std::multimap<std::string,int> mymm5 = current_log.contentIDMM;
    for (auto ch:current_log.contentIDVector){
      if(mymm5.count(ch) > max){
        mostViewed = ch;
      }
    }
    file_writer << mostViewed << "\n";
    file_writer.close();
}

/* This function is where we create required structures and models to
   get desired information details. Each group of structures seperated
   with a single blank line. */
void push(int i) {

  current_log.userIPVector.insert(current_log.userIP);
  current_log.contentIDVector.insert(current_log.contentID);

  current_log.totalNumOfBytesOverall += ( (float)current_log.totalNumOfBytes / bytesToGB );

  current_log.userIPMM.insert(std::pair<std::string,int>(current_log.userIP,i));
  current_log.contentIDMM.insert(std::pair<std::string,int>(current_log.contentID,i));

  current_log.contentBitRateVector.insert((int)floor(current_log.contentBitRate/ 100000));
  current_log.contentBitRateMM.insert(std::pair<int,int>(floor(current_log.contentBitRate/ 100000),i));

  if (current_log.userAgent != "-") {
    std::string userAgent = current_log.userAgent.substr(0,current_log.userAgent.find_first_of("/")+1);
    current_log.userAgentVector.insert(userAgent);
    current_log.userAgentMM.insert(std::pair<std::string,int>(userAgent,i));
  } else {
    current_log.userAgentVector.insert(current_log.userAgent);
    current_log.userAgentMM.insert(std::pair<std::string,int>(current_log.userAgent,i));
  }

  current_log.httpStatusMM.insert(std::pair<int,int>(current_log.httpStatus,i));
}

/* This function is where each line parsed into given parameters.
   Implementation might be seem a bit complicated at first.
   To understand this what this function does first observe that
   each line first passed into a stringstream then divided into parts
   by some specific markers choosen according to sample log. */
void decode() {
  std::stringstream ss(current_log.line);
  std::string contentBitRate,httpStatus,totalNumOfBytes,thrash;

  getline(ss, current_log.userIP, ' '); getline(ss, thrash, '[');
  getline(ss, current_log.eventTime, ']'); getline(ss, thrash, '\"');
  getline(ss, current_log.requestMethod, ' ');
  getline(ss, current_log.contentAddress, ' '); getline(ss, thrash, ' ');
    std::stringstream contAddr(current_log.contentAddress); getline(contAddr, thrash, '/'); getline(contAddr, thrash, '/'); getline(contAddr, thrash, '/');
    getline(contAddr, current_log.contentID, '.'); getline(contAddr, thrash, '(');
    getline(contAddr, contentBitRate, ')'); current_log.contentBitRate = (has_only_digits(contentBitRate) && contentBitRate != "") ? (std::stoi( contentBitRate )) : 0; getline(contAddr, thrash, '(');
    getline(contAddr, current_log.contentType, '=');
  getline(ss, httpStatus, ' '); current_log.httpStatus = std::stoi( httpStatus );
  getline(ss, totalNumOfBytes, ' '); current_log.totalNumOfBytes = std::stoi( totalNumOfBytes ); getline(ss, thrash, '-'); getline(ss, thrash, '\"'); getline(ss, thrash, '\"');
  getline(ss, current_log.userAgent, '\"'); getline(ss, thrash, '-'); getline(ss, thrash, '-'); getline(ss, thrash, '=');
  getline(ss, current_log.cacheStatus);
}
