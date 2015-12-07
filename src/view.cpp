#include "nevil/view.hpp"

// nevil::view::view(QWidget *parent)
//   : Enki::ViewerWidget(new Enki::World(), parent)
// {}

nevil::view::view(nevil::arena &arena, QWidget *parent)
  : Enki::ViewerWidget(arena.get_world(), parent)
  , _arena(std::move(arena))
  , _robot_index(0)
{
  pos.setX(-world->w * 1.1);
  pos.setY(-world->h * 0.5);
  altitude = world->h * 0.6;
  pitch = M_PI/5;
  yaw = -M_PI;
  startTimer(0);
}

void nevil::view::timerEvent(QTimerEvent *event)
{
  if(!_arena.update())
    QApplication::quit();

  updateGL();
}

void nevil::view::keyPressEvent(QKeyEvent *event)
{

  // Robot selection keys
  if (event->key() == Qt::Key_1)
  {
    _robot_index = 0;
    std::cout << "Robot " << _robot_index + 1 << " selected" << std::endl << std::flush;
  }

  // If there are more than one robot
  /*  
  else if (event->key() == Qt::Key_2)
  {
    _robot_index = 1;
    std::cout << "Robot 2 selected" << std::endl << std::flush;
  }
  */

  // Diagnostics keys
  auto r = _arena._robots[_robot_index];
  if (event->key() == Qt::Key_P)
  {
    std::cout  << "Camera values:"<< std::endl;
    print_array(r->camera.image, 60);
    std::cout << "Neural Net inputs:" << std::endl;
    std::cout << r->_get_camera_inputs(_arena._objects) << std::endl << std::flush;
  }

  else if (event->key() == Qt::Key_R)
    _arena.reset();

  // Movement keys
  if (event->key() == Qt::Key_Up && event->modifiers() & Qt::ShiftModifier)
    r->angle += 0.1;

  else if (event->key() == Qt::Key_Down && event->modifiers() & Qt::ShiftModifier)
    r->angle -= 0.1;

  else if (event->key() == Qt::Key_Up)
    r->pos.x -= 1;

  else if(event->key() == Qt::Key_Down)
    r->pos.x += 1;

  else if (event->key() == Qt::Key_Left)
    r->pos.y -= 1;

  else if(event->key() == Qt::Key_Right)
    r->pos.y += 1;

}

void nevil::view::sceneCompletedHook()
{
  glColor3d(0,0,0);
  renderText(10, 15, tr("Press p to print camera values."));
  renderText(10, 35, tr("Press r reset the positions."));
  renderText(10, 55, tr("Use arrow keys to drive the robots"));
  renderText(10, 75, tr("Use shift + up/down arrow keys to change robot's angle"));

  renderText(10, height()-50, tr("Rotate camera by moving mouse while pressing ctrl/cmd+left mouse button"));
  renderText(10, height()-30, tr("Move camera on x/y by moving mouse while pressing ctrl/cmd+shift+left mouse button"));
  renderText(10, height()-10, tr("Move camera on z by moving mouse while pressing ctrl/cmd+shift+right mouse button"));
}