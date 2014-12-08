// cmds.cpp
#include "cmds.h"
#include "cmdsubject.h"
#include "mgspfactory.h"
#include "HitTestCmd.h"
#include "mgshapet.h"
#include "VGDimCmd.h"
#include "VGDimExample.h"
#include "mgnote.h"

class DemoCmdsObserver : public CmdObserverDefault
{
public:
    DemoCmdsObserver() {}
};

static DemoCmdsObserver _observer;

int DemoCmdsImpl::registerCmds(long mgView)
{
    MgView* view = MgView::fromHandle(mgView);
    view->getCmdSubject()->registerObserver(&_observer);

    MgShapeT<VGDimExample>::registerCreator(view->getShapeFactory());
    MgShapeT<MgNote>::registerCreator(view->getShapeFactory());
    
    int n = 0;
    
    n += mgRegisterCommand<HitTestCmd>(view);
    n += mgRegisterCommand<VGDimCmd>(view);
    
    return n;
}

int DemoCmdsImpl::getDimensions(long, float*, char*, int)
{
    return 0;
}
