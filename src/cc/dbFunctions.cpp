// This code snippet written for DB operation functions
#include <bits/stdc++.h>
#include <pqxx/pqxx>
#include "dbFunctions.h"

void createTable() {

  std::string sql;

     try {
        pqxx::connection C("dbname = sammy user = sammy password = 123456 \
        hostaddr = 127.0.0.1 port = 5432");
        if (C.is_open()) {
           std::cout << "Opened database successfully: " << C.dbname() << "\n";
        } else {
           std::cout << "Can't open database" << "\n";
        }

        /* Create SQL statement */
        sql = "CREATE TABLE LOGS(" \
        "ID INT       PRIMARY KEY     NOT NULL,"  \
        "USERIP               TEXT    NOT NULL,"  \
        "EVENTTIME            TEXT    NOT NULL,"  \
        "REQUESTMETHOD        TEXT    NOT NULL,"  \
        "CONTENTADDRESS       TEXT    NOT NULL,"  \
        "CONTENTID            TEXT    NOT NULL,"  \
        "CONTENTBITRATE       TEXT    NOT NULL,"  \
        "CONTENTTYPE          TEXT    NOT NULL,"  \
        "HTTPSTATUS           INT     NOT NULL,"  \
        "TOTALNUMOFBYTES      INT     NOT NULL,"  \
        "USERAGENT            TEXT    NOT NULL,"  \
        "CACHESTATUS          TEXT    NOT NULL);";

        /* Create a transactional object. */
        pqxx::work W(C);

        /* Execute SQL query */
        W.exec( sql );
        W.commit();
        std::cout << "Table created successfully" << "\n";
        C.disconnect ();
     } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
     }

}
void commitToDB(int i) {

  std::string sql;

     try {
        pqxx::connection C("dbname = sammy user = sammy password = 123456 \
        hostaddr = 127.0.0.1 port = 5432");
        if (C.is_open()) {
           std::cout << "Opened database successfully: " << C.dbname() << "\n";
        } else {
           std::cout << "Can't open database" << "\n";
        }

        /* Create a stringstream to create SQL sentence easier. */
        std::stringstream sstm;
        sstm << i;
        std::string result = sstm.str();
        sstm.str(std::string());
        /* Create SQL statement */
        sstm << "INSERT INTO LOGS (ID,USERIP,EVENTTIME,REQUESTMETHOD,CONTENTADDRESS,CONTENTID"
             << ",CONTENTBITRATE,CONTENTTYPE,HTTPSTATUS,TOTALNUMOFBYTES,USERAGENT,CACHESTATUS) "
             << "VALUES (" << result  << ", \'" << current_log.userIP << "\', \'" << current_log.eventTime << "\', \'"
             << current_log.requestMethod << "\', \'" << current_log.contentAddress << "\', \'" << current_log.contentID << "\', "
             << current_log.contentBitRate << ", \'" << current_log.contentType << "\', " << current_log.httpStatus << ", "
             << current_log.totalNumOfBytes << ", \'" << current_log.userAgent << "\', \'" << current_log.cacheStatus << "\' );";

        sql = sstm.str();

        /* Create a transactional object. */
        pqxx::work W(C);

        /* Execute SQL query */
        W.exec( sql );
        W.commit();
        std::cout << "Records created successfully" << "\n";
        C.disconnect ();
     } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
     }

}

void dropTableFromDB() {

  std::string sql;

     try {
        pqxx::connection C("dbname = sammy user = sammy password = 123456 \
        hostaddr = 127.0.0.1 port = 5432");
        if (C.is_open()) {
           std::cout << "Opened database successfully: " << C.dbname() << "\n";
        } else {
           std::cout << "Can't open database" << "\n";
        }

        /* Create SQL statement */
        sql = "DROP TABLE LOGS;";

        /* Create a transactional object. */
        pqxx::work W(C);

        /* Execute SQL query */
        W.exec( sql );
        W.commit();
        std::cout << "Table dropped successfully" << "\n";
        C.disconnect ();
     } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
     }

}
