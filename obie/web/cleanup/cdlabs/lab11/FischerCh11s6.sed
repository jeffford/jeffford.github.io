#! /bin/bash
# This file removes comments from C files when they are over multiple lines. 
# Written by Rebecca Fischer ( with MUCH help from others )
/\/\*/!b 
:a
/\*\//!{
 N
 ba
}
s:/\*.*\*/::
