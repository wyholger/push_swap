#!/bin/bash
ARG=`./gen.py 500`;
echo $ARG
./push_swap $ARG > resps;
< resps ./checker_linux $ARG;
< resps wc -l;



