# Nginx Log Server Monitoring
A sample program to parse and visualize important figures from nginx logs. [Here is a demo](http://www.cansolak.com/nginx-log-server-monitoring/results/report/report.html).

Project implemented as two separate parts.
1) Read, parse, process and append the each log to the DB. This part is implemented in C++.
2) Fetch the relevant information from DB and generate HTML report with related figures and visualizations. This part is implemented in Python.

## Usage
-Install dependencies with `sh install.sh`

-Run the program with `sh run.sh`

System Used in development:

* Ubuntu 16.04 LTS
* GCC/G++ 7.1.0
* Python 3.6.5

Dependencies:
* PostgreSQL-9.6,
* PostgreSQL-contrib-9.6,
* Libpqxx 4.0.1+dfsg3
* Psycopg2
* Matplotlib

## File Structure

```
├── data
├── lib
│   ├── libpqxx-4.0.1+dfsg3
│   └── matplotlib
├── results
│   ├── data
│   ├── images
│   └── report
└── src
    ├── cc
    └── py

```

## Further Ideas:
-Bulk insert implementation for the commitToDB function to have better performance in populating a database.

-Trying to use getchar_unlocked() for a better reading performance, in case we do not care thread safety.

-Trying to use a read buffer for a better general performance

-Reading files in parallel :)


## References

* [PostgreSQL tutorial of Digital Ocean](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-postgresql-on-ubuntu-16-04)
* [C/C++ adaptor tutorial of Tutorials Point](https://www.tutorialspoint.com/postgresql/postgresql_c_cpp.htm)
* [Python adaptor tutorial of Tutorials Point](https://www.tutorialspoint.com/postgresql/postgresql_python.htm)
* [One Page Wonder Bootstrap Template](https://github.com/BlackrockDigital/startbootstrap-one-page-wonder)

## Copyright

All data and logo used to demonstrate sample report is provided by [Er Stream CDN Company](http://www.erstream.com/).
