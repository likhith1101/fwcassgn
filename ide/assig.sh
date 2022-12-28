#!/bin/bash
cd /home/likhith/ass1/ide
pio run
pio run -t upload


cd /home/likhith/ass1/ide
pdflatex assignment1.tex
xdg-open assignment1.pdf

