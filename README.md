## Modern C++ wrapper around the Microsoft Portable Executable file format without any CRT dependencies and dynamic allocations

This is a W.I.P. library to interact with Microsoft PE files (.exe, .dll, .sys) in a modern C++ way.

It depends on no CRT, nor allocates any memory.

Code to traverse tables (IAT, EAT, Relocs, etc...) is being abstracted by iterators to provide developers with a clean abstracted interface to base their work on.

## Examples

More samples can be found in the main.cpp file.