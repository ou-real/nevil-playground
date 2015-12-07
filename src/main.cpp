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
  nevil::arena _arena;
  nevil::view viewer(_arena);
  viewer.show();
  return app.exec();
}
