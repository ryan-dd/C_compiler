# C Compiler

A barebones C compiler. 

Currently I have started the tokenizer, we will get to some assembly eventually.

## Building 

You can use conan to install Google Test for the test suite. You can also install Google Test locally and run CMake standalone.

[Installing Conan](https://docs.conan.io/2/installation.html)

```
conan install . -of build 

cmake -S . -B build --preset conan-release

cmake --build build
```

## Run Tests

After building:

```
cd build
ctest
```

