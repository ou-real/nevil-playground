#ifndef _NEVIL_ARENA_ROBOT_HPP_
#define _NEVIL_ARENA_ROBOT_HPP_

#include <string>
#include <vector>
#include <enki/robots/e-puck/EPuck.h>
#include "nevil/objects/object.hpp"

namespace nevil
{
  class robot: public Enki::EPuck
  {
  public:
    robot();
    robot(double x, double y, double angle, const std::string &robot_name, const Enki::Color &color, double max_speed=12.8);
    virtual ~robot();

    bool update(const std::vector<object *> &objects);
    void reset_position();
    bool is_at_switch() const;
    bool is_at_light() const;
    std::string get_name() const;

    static const int SENSOR_NUM = 18;

    void _set_wheels_speed(double left, double right);
    double _clamp(double val, double min, double max);
    const std::vector<double> _get_sensor_inputs();

    std::string _robot_name;
    Enki::Point _initial_position;
    double _initial_angle;
    double _max_speed;
  };
}

#endif // _NEVIL_ARENA_ROBOT_HPP_