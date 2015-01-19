// VGDimExample.h
// Created by Zhang Yungui on 14-11-19.
// License: LGPL, https://github.com/rhcad
//

#ifndef __TOUCHVG__VGDimExample__
#define __TOUCHVG__VGDimExample__

#include "mgline.h"
#include "mgshape.h"

//! Example shape class with text.
class VGDimExample : public MgLine
{
    MG_DECLARE_CREATE(VGDimExample, MgLine, 41)
public:
    
protected:
    bool _save(MgStorage* s) const;
    bool _load(MgShapeFactory* factory, MgStorage* s);
    int _getHandleCount() const { return 2; }
    bool _draw(int mode, GiGraphics& gs, const GiContext& ctx, int segment) const;
};

#endif // __TOUCHVG__VGDimExample__
