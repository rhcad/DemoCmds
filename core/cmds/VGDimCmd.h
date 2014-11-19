// VGDimCmd.h
// Created by Zhang Yungui on 14-11-19.
// License: LGPL, https://github.com/touchvg
//

#ifndef __TOUCHVG__VGDimCmd__
#define __TOUCHVG__VGDimCmd__

#include "mgdrawline.h"

class VGDimCmd : public MgCmdDrawLine
{
public:
    VGDimCmd() : MgCmdDrawLine(Name()) {}
#ifndef SWIG
    static const char* Name() { return "dim_example"; }
    static MgCommand* Create() { return new VGDimCmd; }
#endif
    virtual void release() { delete this; }
    virtual bool initialize(const MgMotion* sender, MgStorage* s);
};

#endif // __TOUCHVG__VGDimCmd__
