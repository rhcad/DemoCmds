#!/bin/sh
# Type './build.sh' to generate C# classes.

if [ ! -f ../../vgcore/README.md ] ; then
    git clone https://github.com/rhcad/vgcore ../../vgcore
fi
cd democmds; sh build.sh; cd ..
