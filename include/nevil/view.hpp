#ifndef _NAME_GUI_VIEW_HPP_
#define _NAME_GUI_VIEW_HPP_

#include <iostream>
#include <QKeyEvent>
#include <QtGui>
#include <enki/viewer/Viewer.h>
#include "nevil/arena.hpp"
#include "nevil/print.hpp"

namespace nevil
{
  class view : public Enki::ViewerWidget
  {
  public:
    view(nevil::arena *arena, QWidget *parent = 0);
    ~view();

    virtual void timerEvent(QTimerEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void sceneCompletedHook();

    nevil::arena *_arena;
    int _index;
  };
}

#endif // _NAME_GUI_VIEW_HPP_