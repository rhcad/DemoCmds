// mgnote.h
// Created by Zhang Yungui on 14-12-8.
// License: LGPL, https://github.com/touchvg

#ifndef TOUCHVG_NOTE_SHAPE_H_
#define TOUCHVG_NOTE_SHAPE_H_

#include "mgshape.h"
#include <string>

class MgNote : public MgBaseShape
{
    MG_DECLARE_CREATE(MgNote, MgBaseShape, 35)
public:
    const char* getText() const { return _text.c_str(); }
    void setText(const char* text) { _text = text; }
    
    Vector2d getOffset() const { return _textoff; }
    void setOffset(const Vector2d& vec) { _textoff = vec; }
    
    static const MgShape* findNote(const MgShapes* shapes, const char* text);
    
protected:
    bool _isClosed() const { return false; }
    void _output(MgPath&) const {}
    bool _save(MgStorage* s) const;
    bool _load(MgShapeFactory* factory, MgStorage* s);
    bool _draw(int mode, GiGraphics& gs, const GiContext& ctx, int segment) const;
    bool _hitTestBox(const Box2d& rect) const;
    int _getHandleCount() const { return 2; }
    Point2d _getHandlePoint(int index) const;
    bool _setHandlePoint(int index, const Point2d& pt, float tol);
    bool _isHandleFixed(int index) const;
    int _getHandleType(int index) const;
    
private:
    Point2d     _point;
    Vector2d    _textoff;
    std::string _text;
};

#endif // TOUCHVG_NOTE_SHAPE_H_
