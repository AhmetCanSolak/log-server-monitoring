#!/bin/bash

# Install libpqxx-4.0.1
cd ~/lib
wget https://launchpad.net/ubuntu/+archive/primary/+files/libpqxx_4.0.1+dfsg3.orig.tar.gz
tar -zxvf libpqxx_4.0.1+dfsg3.orig.tar.gz
cd libpqxx-4.0.1+dfsg3.orig
./configure
make
make install
service postgresql restart
# Install matplotlib
cd ~/lib/
git clone git://github.com/matplotlib/matplotlib.git
cd matplotlib
sudo python setup.py install
sudo apt-get build-dep python-matplotlib #Get all dependencies
# Install psycopg2
cd
sudo pip3 install psycopg2
