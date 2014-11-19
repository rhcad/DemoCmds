// VGDimExample.cpp
// Created by Zhang Yungui on 14-11-19.
// License: LGPL, https://github.com/touchvg
//

#include "VGDimExample.h"
#include "mgshape_.h"
#include <sstream>

MG_IMPLEMENT_CREATE(VGDimExample)

VGDimExample::VGDimExample()
{
}

VGDimExample::~VGDimExample()
{
}

int VGDimExample::_getPointCount() const { return __super::_getPointCount(); }
Point2d VGDimExample::_getPoint(int index) const { return __super::_getPoint(index); }
void VGDimExample::_setPoint(int index, const Point2d& pt) { __super::_setPoint(index, pt); }
void VGDimExample::_copy(const VGDimExample& src) { __super::_copy(src); }
bool VGDimExample::_equals(const VGDimExample& src) const { return __super::_equals(src); }
void VGDimExample::_update() { __super::_update(); }
void VGDimExample::_transform(const Matrix2d& mat) { __super::_transform(mat); }
void VGDimExample::_clear() { __super::_clear(); }
float VGDimExample::_hitTest(const Point2d& pt, float tol, MgHitResult& res) const {
    return __super::_hitTest(pt, tol, res); }

bool VGDimExample::_save(MgStorage* s) const
{
    //s->writeString("text", _text.c_str());
    return __super::_save(s);
}

bool VGDimExample::_load(MgShapeFactory* factory, MgStorage* s)
{
    bool ret = __super::_load(factory, s);
    /*int len = s->readString("text");
    
    _text.resize(len);
    if (len > 0 && ret) {
        ret = s->readString("text", &_text[0], len) == len;
    }*/
    
    return ret;
}

bool VGDimExample::_draw(int mode, GiGraphics& gs, const GiContext& ctx, int segment) const
{
    std::stringstream ss;
    Matrix2d m(gs.xf().modelToWorld());
    
    ss << (_getPoint(0) * m).distanceTo(_getPoint(1) * m);
    gs.drawTextAt(ctx.getLineARGB(), ss.str().c_str(), center(), 3.f, 1, angle());
    
    return gs.drawLine(&ctx, _getPoint(0), _getPoint(1));
}
