#ifndef _NEVIL_ARENA_ROBOT_HPP_
#define _NEVIL_ARENA_ROBOT_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <enki/robots/e-puck/EPuck.h>
#include "nevil/objects/object.hpp"
#include "nevil/objects/light.hpp"
#include "nevil/objects/switch.hpp"

namespace nevil
{
  class robot;
  typedef std::vector<robot*> robot_list;
  typedef std::unordered_map<std::string, nevil::object *> object_list;
  
  enum color_chanel
  {
    RED = 0,
    GREEN = 1,
    BLUE = 2
  };

  class robot: public Enki::EPuck
  {
  public:
    robot();
    robot(double x, double y, double angle, const std::string &name
      , const Enki::Color &color, size_t input_num = 18, double max_speed = 12.8);
    // robot(const nevil::robot &rhs);
    // robot(nevil::robot &&rhs) noexcept;
    // virtual ~robot();

    bool update(const nevil::object_list &objects);
    void reset_position();
    nevil::robot *clone() const;
    bool is_at(nevil::object *obj, nevil::object_state state,
     nevil::color_chanel chanel = RED) const;


    void _set_wheels_speed(double left, double right);
    double _clamp(double val, double min, double max);
    std::vector<double> _get_camera_inputs(const nevil::object_list &objects,
     color_chanel chanel = RED) const;

    double _initial_angle;
    Enki::Point _initial_position;
    std::string _robot_name;
    size_t _input_num;
    double _max_speed;
  };
}

#endif // _NEVIL_ARENA_ROBOT_HPP_