#ifndef _NEVIL_ARENA_ARENA_HPP_
#define _NEVIL_ARENA_ARENA_HPP_

#include "nevil/objects/object.hpp"
#include "nevil/objects/switch.hpp"
#include "nevil/objects/light.hpp"
#include "nevil/objects/wall.hpp"
#include "nevil/robot.hpp"

namespace nevil
{
  class arena
  {
  public:
    arena();
    arena(int size_x, int size_y, const Enki::Color &arena_color=Enki::Color(0.9, 0.9, 0.9));
    virtual ~arena(); 

    void tick();
    bool update();
    void reset();

    Enki::World* get_world();

    void _add_object(nevil::object *o);
    void _add_robot(nevil::robot *r);

    Enki::World *_trial_world;
    std::vector<robot*> _robot_vector;
    std::vector<object*> _object_vector;
  };
}
#endif // _NEVIL_ARENA_ARENA_HPP_