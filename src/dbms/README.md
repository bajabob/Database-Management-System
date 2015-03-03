DBMS - Team #6
==============
Team Members:
* Rafael (Raf) Salas
* Robert (Bob) Timm
* Nicolette (Nikki) Schreier
* Michael Turner

How to compile the DBMS WITHOUT the parser
==========================================
Copy the template makefile needed: ```cp template.noparser.makefile makefile```

Copy the template main executable: ```cp template.main.cpp main.cpp```

Build: ```make```

If you get any errors, you may need to remove some parser header files from the copied ```main.cpp```

How to compile the DBMS WITH the parser
==========================================
Note: Must be built on ```unix.cs.tamu.edu```
Copy the template makefile needed: ```cp template.parser.makefile makefile```
Copy the template main executable: ```cp template.main.cpp main.cpp```
Build: ```make```

How to compile the static lib with testlib.cpp
==============================================
Note: Must be built on ```unix.cs.tamu.edu```
```testlib.cpp``` Is the source file used to verify our DBMS works
Copy the template makefile needed: ```cp template.lib.makefile makefile```
Build the lib: ```make```
Compile the test file with the lib: ```g++ testlib.cpp dbms.a -o testlib```
Run the test program: ```./testlib```
