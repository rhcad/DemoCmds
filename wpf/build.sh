#!/bin/sh
# Type './build.sh' to generate C# classes.

if [ ! -f ../../TouchVGCore/README.md ] ; then
    git clone https://github.com/touchvg/TouchVGCore ../../TouchVGCore
fi
cd democmds; sh build.sh; cd ..
