#! /bin/bash
#Breaks apart absolute pathnames & separate the lowest level dir

s/\([/][A-Za-z].*\)[/]\([A-Za-z].*\)/\1 \2/

# end of script
