#!/bin/sh
#
# generate PDF for gurudoc file

FILE=$1

mkgdl $FILE.txt
gsl3 -quiet -tpl:latex_simple -gdl:$FILE gurudoc

# twice, so TOC is correctly built
pdflatex --interaction batchmode $FILE.tex
pdflatex --interaction batchmode $FILE.tex

# clean-up intermediary files
rm $FILE.aux $FILE.gdl $FILE.log $FILE.tex $FILE.toc
