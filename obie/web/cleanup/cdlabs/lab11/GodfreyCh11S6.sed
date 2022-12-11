#! /bin/bash
# file deletes comments from the file 

/\/\*/!b
:a
/\*\//!{
 N
 ba
}
s:/\*.*\*/::

#end script 

