State Library         {#mainpage}
=============

Project homepage
----------------
[web site](http://allali.github.io/statelib/)

About
-----
C implementation of a basic state design pattern

Each state of the machine is associated to a function. The function must take a `void *` and return an `int`. The return value is use for transition between state (functions).

Author
------
Julien Allali (allali.julien@gmail.com)

Compilation
-----------
Compilation of the project is done using `cmake`.

First create a `build` directory:

```sh
mkdir build
```

then run `cmake` from this directory:

```sh
cd build
cmake ..
```

and compile with `make`:

```sh
make
make doc
```

optionaly, you can install the library using:

```sh
make install
```

the install directory can be specified when calling `cmake`:

```sh
cmake -DCMAKE_INSTALL_PREFIX:PATH=$HOME/usr
```

Example
-------
You will find examples into the `demos` directory

API
---
See [the documentation here](@ref state.h)