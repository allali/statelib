State Library         {#mainpage}
=============

About
-----
C implementation of a basic state design pattern

Each state of the machine is associated to a function. The function must take a void * and return an int. The return value is use for transition between state (functions).

Author
------
Julien Allali (allali.julien@gmail.com)

Compilation
-----------
compilation of the project is done using cmake.

First create a build directory:
> mkdir build
then run cmake from this directory:
> cd build
> cmake ..
and compile with make:
> make
> make doc
optionaly, you can install the library using 
> make install
the install directory can be specified when calling cmake:
> cmake -DCMAKE_INSTALL_PREFIX:PATH=$HOME/usr

Example
-------
You will find examples into the demos directory

API
---
see [the documentation here](@ref state.h)