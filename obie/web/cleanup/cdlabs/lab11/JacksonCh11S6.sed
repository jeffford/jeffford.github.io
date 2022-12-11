#! /bin/bash
# file removes comments from the file

/\/\*/!b
:a
/\*\//!{
 N
 ba
}
s:/\*.*\*/::

# end of script
