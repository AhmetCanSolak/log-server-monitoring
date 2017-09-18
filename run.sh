#!/bin/bash
#Run this in terminal
g++-7 -o loadLogToDB src/cc/loadLogToDB.cc src/cc/helperFunctions.cpp -march=native -lpqxx -lpq -O3
echo "End Of the Compilation..."
./loadLogToDB
echo "End Of the Execution..."
rm loadLogToDB
echo "Cleaned the C++ Binary..."
python3 src/py/visualize.py
echo "End Of the Visualization..."
python3 src/py/report.py
echo "End Of the report generation...\nGo check the results/report/report.html"
