#!/usr/bin/env python3
from charts import *
import psycopg2

# Incase you want to make visualizations directly from the logs in the database use this function
# This function get all rows of desired column from DB, pass "*" to get entire table
def fetchFromDB(column):
    conn = psycopg2.connect(database = "sammy", user = "sammy", password = "123456", host = "127.0.0.1", port = "5432")
    print ("Opened database successfully")
    cur = conn.cursor()
    cur.execute("SELECT t.* FROM (SELECT " + column + ", row_number() OVER(ORDER BY id ASC) AS row FROM LOGS) t WHERE t.row % 500 = 0")
    rows = cur.fetchall()
    print ("Operation done successfully")
    conn.close()

# Read the extracted information
f = open("results/data/histograms.txt")

# Read the bitrate lines
line = f.readline()
sizesForBitRate = line.split()
line = f.readline()
labelsForBitRate = line.split()
labelsForBitRate = [str(int(i)*100000 + 50000) for i in labelsForBitRate]
#Save the chart for the corresponding data
piChartFunc(labelsForBitRate,sizesForBitRate,"bitRate")

# Read the http status lines
line = f.readline()
sizesForHTTPStatus = line.split()
line = f.readline()
labelsForHTTPStatus = line.split()
#Save the chart for the corresponding data
piChartFunc(labelsForHTTPStatus,sizesForHTTPStatus,"httpStatus")

# Read the http status lines
line = f.readline()
sizesForBrowserType = line.split()
sizesForBrowserType = [float(i)/float(max(sizesForBrowserType)) for i in sizesForBrowserType]
labelsForBrowserType = []
line = f.readline()
while line:
    labelsForBrowserType.append(line)
    line = f.readline()

#Save the chart for the corresponding data
barChartFunc(labelsForBrowserType,sizesForBrowserType,"browserType","Browser Types","Agent Types","Normalized Usage Percentage")

f.close()
