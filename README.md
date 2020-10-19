# llvm-pass-skeleton

A trivial LLVM pass which removes printf calls from a program.

There is also a magic annotation function which disables removal for the next
printf. It needs to be placed before (but not necessarily immediately before)
the printf and within the same basic block.

The provided gcd.c file should demonstrate the effect of this pass. Note
however that normal compilation results in a linker error since the annotation
function definition does not exist.

Build:

    $ cd llvm-pass-skeleton
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ cd ..

Run:

    $ clang -Xclang -load -Xclang build/skeleton/libSkeletonPass.* something.c
