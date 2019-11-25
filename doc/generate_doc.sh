#!/bin/bash
mkdir -p doxy
doxygen Doxyfile
cd doxy/latex
make
cd ../..
cp doxy/latex/refman.pdf doc.pdf