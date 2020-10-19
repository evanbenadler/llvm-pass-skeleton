# llvm-pass-skeleton

A trivial LLVM pass which removes all printf calls from a program.

The provided gcd.c program returns the gcd as the error code, so correctness
can be verified by running `echo $?`.

Build:

    $ cd llvm-pass-skeleton
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ cd ..

Run:

    $ clang -Xclang -load -Xclang build/skeleton/libSkeletonPass.* something.c
