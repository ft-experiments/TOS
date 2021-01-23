#!/bin/bash
rm -f -r *.o
make
qemu-system-x86_64 -kernel kernel -gdb tcp::1234
