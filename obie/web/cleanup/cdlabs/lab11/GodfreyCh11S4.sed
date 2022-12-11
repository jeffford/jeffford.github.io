#! /bin/bash
#Breaks apart absolute pathnames & separates the lowest level dir

s/\([/][A-Za-z].*\)[/]\([A-Za-z].*\)/\1 \2/

#end script 
