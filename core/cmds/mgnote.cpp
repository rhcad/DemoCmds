// mgnote.cpp
// Created by Zhang Yungui on 14-12-8.
// License: LGPL, https://github.com/rhcad

#include "mgnote.h"
#include "mgshape_.h"
#include "mgshapes.h"

MG_IMPLEMENT_CREATE(MgNote)

MgNote::MgNote() : _textoff(0.f, 5.f)
{
}

MgNote::~MgNote()
{
}

int MgNote::_getPointCount() const
{
    return 1;
}

Point2d MgNote::_getPoint(int) const
{
    return _point;
}

void MgNote::_setPoint(int, const Point2d& pt)
{
    _point = pt;
}

void MgNote::_copy(const MgNote& src)
{
    _point = src._point;
    _textoff = src._textoff;
    _text = src._text;
    __super::_copy(src);
}

bool MgNote::_equals(const MgNote& src) const
{
    return (_point == src._point && _textoff == src._textoff
            && _text == src._text && __super::_equals(src));
}

void MgNote::_update()
{
    _extent.set(_getHandlePoint(1), 4.f, 0.f);
    __super::_update();
}

void MgNote::_transform(const Matrix2d& mat)
{
    _point *= mat;
    _textoff *= mat;
    __super::_transform(mat);
}

void MgNote::_clear()
{
    _point = Point2d::kOrigin();
    _textoff = Vector2d::kIdentity();
    _text.clear();
    __super::_clear();
}

float MgNote::_hitTest(const Point2d& pt, float tol, MgHitResult& res) const
{
    float dist = pt.distanceTo(_point);
    if (dist < tol) {
        res.nearpt = _point;
        res.segment = 0;
    }
    float d2 = pt.distanceTo(_getHandlePoint(1));
    if (d2 < tol && d2 < dist) {
        dist = d2;
        res.nearpt = _getHandlePoint(1);
        res.segment = 1;
    }
    return dist < tol ? dist : _FLT_MAX;
}

bool MgNote::_hitTestBox(const Box2d& rect) const
{
    return rect.contains(_point) || rect.contains(_getHandlePoint(1));
}

Point2d MgNote::_getHandlePoint(int index) const
{
    return index > 0 ? _point + _textoff : _point;
}

bool MgNote::_setHandlePoint(int index, const Point2d& pt, float tol)
{
    if (index > 0) {
        _textoff = pt - _point;
        return true;
    }
    return __super::_setHandlePoint(index, pt, tol);
}

bool MgNote::_isHandleFixed(int index) const
{
    return index == 0;
}

int MgNote::_getHandleType(int index) const
{
    return index > 0 ? kMgHandleNoSnap : kMgHandleVertex;
}

bool MgNote::_save(MgStorage* s) const
{
    s->writeFloat("x", _point.x);
    s->writeFloat("y", _point.y);
    s->writeFloat("dx", _textoff.x);
    s->writeFloat("dy", _textoff.y);
    s->writeString("text", _text.c_str());
    return __super::_save(s);
}

bool MgNote::_load(MgShapeFactory* factory, MgStorage* s)
{
    bool ret = __super::_load(factory, s);
    
    _point.set(s->readFloat("x", _point.x), s->readFloat("y", _point.y));
    _textoff.set(s->readFloat("dx", _textoff.x), s->readFloat("dy", _textoff.y));
    
    int len = s->readString("text");
    _text.resize(len);
    if (len > 0 && ret) {
        ret = s->readString("text", &_text[0], len) == len;
    }
    
    return ret;
}

bool MgNote::_draw(int mode, GiGraphics& gs, const GiContext& ctx, int segment) const
{
    return gs.drawTextAt(ctx.getLineARGB(), _text.empty() ? "?" : _text.c_str(),
                         _getHandlePoint(1), 4.f,
                         GiGraphics::kAlignCenter|GiGraphics::kAlignVCenter) > 0;
}

const MgShape* MgNote::findNote(const MgShapes* shapes, const char* text)
{
    if (text && *text) {
        MgShapeIterator it(shapes);
        
        while (const MgShape* sp = it.getNext()) {
            if (sp->shapec()->isKindOf(Type())) {
                if (((const MgNote*)sp->shapec())->_text == text) {
                    return sp;
                }
            }
        }
    }
    
    return NULL;
}
