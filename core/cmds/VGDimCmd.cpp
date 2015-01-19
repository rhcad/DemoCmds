// VGDimCmd.cpp
// Created by Zhang Yungui on 14-11-19.
// License: LGPL, https://github.com/rhcad
//

#include "VGDimCmd.h"
#include "VGDimExample.h"

bool VGDimCmd::initialize(const MgMotion* sender, MgStorage* s)
{
    return _initialize(VGDimExample::Type(), sender, s);
}
