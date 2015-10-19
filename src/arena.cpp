#include "nevil/arena.hpp"

nevil::arena::arena() {}

nevil::arena::arena(int world_size_x, int world_size_y, const Enki::Color &arena_color)
{
  _trial_world = new Enki::World(world_size_x, world_size_y, arena_color);
  // TODO: Setup your arena with objects
  const double OBJECT_SIZE_X = 6;
  const double OBJECT_SIZE_Y = 0.1;
  const double OBJECT_HEIGHT = 7;
  const double INITIAL_DEGREE = 0;

  //switch A
  _add_object(new nevil::switch_object(world_size_x / 4.0
    , world_size_y
    , OBJECT_SIZE_X
    , OBJECT_SIZE_Y
    , OBJECT_HEIGHT));

    //light A
  _add_object(new nevil::light(world_size_x / 4.0
    , 0
    , OBJECT_SIZE_X
    , OBJECT_SIZE_Y
    , OBJECT_HEIGHT));
  
  //switch B
  _add_object(new nevil::switch_object(world_size_x * (3 / 4.0)
    , world_size_y
    , OBJECT_SIZE_X
    , OBJECT_SIZE_Y
    , OBJECT_HEIGHT));
  
  //light B
  _add_object(new nevil::light(world_size_x * (3 / 4.0)
    , 0
    , OBJECT_SIZE_X
    , OBJECT_SIZE_Y
    , OBJECT_HEIGHT));
  
  //Wall in the middle of the field
  _add_object(new nevil::wall(world_size_x / 2.0
    , world_size_y / 2.0
    , 0.01
    , world_size_y
    , OBJECT_HEIGHT));

  //--robots--
  // Create a robot named A
  _add_robot(new nevil::robot(world_size_x / 4.0
    , world_size_y / 2.0
    , 0
    , "A"
    , Enki::Color(0.0, 0.0, 0.5)));

  // Create a robot named B
  _add_robot(new nevil::robot(world_size_x * (3 / 4.0)
    , world_size_y / 2.0
    , 0
    , "B"
    , Enki::Color(0.0, 0.5, 0.0)));
}

nevil::arena::~arena()
{
  delete _trial_world;
}

void nevil::arena::tick()
{
  // step of 50 ms
  _trial_world->step(1.0/30,1);
}

void nevil::arena::reset()
{
  for (auto r : _robot_vector)
    r->reset_position();

  for (auto o : _object_vector)
    o->turn_off();
}

Enki::World *nevil::arena::get_world()
{
  return _trial_world;
}

void nevil::arena::_add_robot(nevil::robot *r)
{
  _robot_vector.push_back(r);
  _trial_world->addObject(r);
}

void nevil::arena::_add_object(nevil::object *o)
{
  _object_vector.push_back(o);
  _trial_world->addObject(o);
}

bool nevil::arena::update()
{
  for (auto r : _robot_vector)
  {
    if(r->is_at_switch())
    {
      std::cout << "Is at switch" << std::endl;
      // Turn on the lights
      _object_vector[1]->turn_on();
      _object_vector[3]->turn_on();

      // Only turn on the switch on your side
      if (r->get_name() == "A")
        _object_vector[0]->turn_on();
      else
        _object_vector[2]->turn_on();
    }
  }

  // Updating the robots
  for (auto r : _robot_vector)
    r->update(_object_vector);

  tick();
  return true;
}