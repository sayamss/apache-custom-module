# Custom Module for Apache Server

## Tech Stack
* apache 2.4

# Steps to Create Custom Module for Apache Server

## Install Configure The Apache Web Server [link](http://httpd.apache.org/docs/current/install.html)

## Create the Module File
* Make gci.c file(File with Code is in the directory)

## Compile the file
* In the directory where gci.c is located
* Run ***apxs -iac gci.c***

## Add config file and Load the module

* Create ***gci.conf*** and ***gci.load*** file in ***/etc/apache2/mods-available*** folder
* In ***gci.load*** file, Add ***LoadModule gci_module /usr/lib/apache2/modules/gci.so***
* In ***gci.conf*** file, Add ***<Location /gci> SetHandler gci </Location/>***

## Enable the module

* Run ***sudo a2enmod gci*** 
* Restart apache server using ***systemctl restart apache2***

## Urls
* Visit ***localhost*** for landing page
* Visit ***localhost/gci*** for the Module Page

