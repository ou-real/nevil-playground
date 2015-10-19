#include <QApplication>
#include "nevil/arena.hpp"
#include "nevil/view.hpp"

/**
* Main for GUI simulator
*/
int main(int argc, char *argv[])
{
  srand(time(NULL));
  QApplication app(argc, argv);  
  const int WORLD_SIZE_X = 40;
  const int WORLD_SIZE_Y = 50;
  nevil::arena *arena = new nevil::arena(WORLD_SIZE_X, WORLD_SIZE_Y);
  nevil::view viewer(arena);
  viewer.show();
  return app.exec();
}
