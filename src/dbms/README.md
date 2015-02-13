DBMS - Team #6
==============
Team Members:
* Rafael (Raf) Salas
* Robert (Bob) Timm
* Nicolette (Nikki) Schreier
* Michael Turner

How to run
==========
* In a terminal window, type "make" to compile the test application. 
* Then type "./main" to run the test program.
* The test program currently has three parts: 
* A table with errors.
* A table with no errors that successfully saves to disk.
* A table that loads the saved table from disk and manipulates it further by adding more data.

Sample Output
=============

```$ ./main

Relation: error_table
----------------------------

Attributes: 5
Attribute 'id'
 - kind             :1
 - length           :8
 - defualt_value    :
 - index            :1
 - is_auto_increment:1
 - auto_increment   :6
Attribute 'username'
 - kind             :0
 - length           :8
 - defualt_value    :
 - index            :2
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'name_last'
 - kind             :0
 - length           :25
 - defualt_value    :
 - index            :0
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'name_first'
 - kind             :0
 - length           :25
 - defualt_value    :
 - index            :0
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'id'
 - kind             :1
 - length           :8
 - defualt_value    :
 - index            :1
 - is_auto_increment:1
 - auto_increment   :6
----------------------------

Tuples: 6
       0        0          Robert            Timm    bob27 
       1        1             Raf           Salas    raf28 
       2        2       Nicolette        Schreier  nikki22 
       3        3         Michael          Turner   mike20 
       4        4            12th             Man    bob27 
       5        5          Bowtie          Loftin this-is- 
----------------------------

3 Errors 
-- Error   [Code: 3]: Duplicate attribute name specified, 'id' already exists. 
-- Error   [Code: 3]: Relation already contains a unique value 'bob27' in 'username'. 
-- Warning [Code: 0]: Data:'this-is-too-long' is being truncated because it is too long for the defined attribute 'username(8)' 




Relation: error_free_table
----------------------------

Attributes: 4
Attribute 'id'
 - kind             :1
 - length           :8
 - defualt_value    :
 - index            :1
 - is_auto_increment:1
 - auto_increment   :4
Attribute 'username'
 - kind             :0
 - length           :8
 - defualt_value    :
 - index            :2
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'name_last'
 - kind             :0
 - length           :25
 - defualt_value    :NO_NAME
 - index            :0
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'name_first'
 - kind             :0
 - length           :25
 - defualt_value    :NO_NAME
 - index            :0
 - is_auto_increment:0
 - auto_increment   :0
----------------------------

Tuples: 4
       0         NO_NAME            Timm    bob27 
       1         NO_NAME           Salas    raf28 
       2       Nicolette         NO_NAME  nikki22 
       3         Michael          Turner   mike20 
----------------------------

0 Errors 

Saving 'error_free_table.db' to disk...


Loading 'error_free_table.db'...
 - Found on disk, loading...

Relation: error_free_table
----------------------------

Attributes: 4
Attribute 'id'
 - kind             :1
 - length           :8
 - defualt_value    :
 - index            :1
 - is_auto_increment:1
 - auto_increment   :5
Attribute 'username'
 - kind             :0
 - length           :8
 - defualt_value    :
 - index            :2
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'name_last'
 - kind             :0
 - length           :25
 - defualt_value    :NO_NAME
 - index            :0
 - is_auto_increment:0
 - auto_increment   :0
Attribute 'name_first'
 - kind             :0
 - length           :25
 - defualt_value    :NO_NAME
 - index            :0
 - is_auto_increment:0
 - auto_increment   :0
----------------------------

Tuples: 5
       0         NO_NAME            Timm    bob27 
       1         NO_NAME           Salas    raf28 
       2       Nicolette         NO_NAME  nikki22 
       3         Michael          Turner   mike20 
       4            BTHO         Alabama newguy55 
----------------------------

0 Errors ```
