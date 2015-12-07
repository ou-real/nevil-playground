#include "nevil/arena.hpp"

nevil::arena::arena(const Enki::Color &color)
{
  const double world_size_x = 40;
  const double world_size_y = 50;
  _world.reset(new Enki::World(world_size_x, world_size_y, color));
  _world->takeObjectOwnership(false);

  // switch 
  _add_object("switch", new nevil::switch_object(world_size_x / 2.0, world_size_y));

  // light
  _add_object("light", new nevil::light(world_size_x / 2.0, 0));
  
  //--robots--
  _add_robot(new nevil::robot(world_size_x / 2.0
    , world_size_y / 2.0
    , 0
    , "TestRobot"
    , Enki::Color(0.0, 0.5, 0.0)));
}

nevil::arena::arena(const nevil::arena &rhs)
{
  _world.reset(new Enki::World(rhs._world->w, rhs._world->h, rhs._world->wallsColor));
  _world->takeObjectOwnership(false);
  for (auto r : rhs._robots)
    _add_robot(r->clone());

  for (auto o : rhs._objects)
    _add_object(o.first, o.second->clone());
}

nevil::arena::arena(nevil::arena &&rhs) noexcept
  : _world(std::move(rhs._world))
  , _robots(std::move(rhs._robots))
  , _objects(std::move(rhs._objects))
{}

nevil::arena::~arena()
{
  for (auto r : _robots)
    delete r;

  for (auto o : _objects)
    delete o.second;
}

bool nevil::arena::reset()
{
  for (auto r : _robots)
    r->reset_position();

  for (auto o : _objects)
    o.second->turn_off();
  return true;
}

Enki::World *nevil::arena::get_world() const
{
  return _world.get();
}

void nevil::arena::_add_robot(nevil::robot *r)
{
  _robots.push_back(r);
  _world->addObject(r);
}

void nevil::arena::_add_object(const std::string &name, nevil::object *o)
{
  _objects[name] = o;
  _world->addObject(o);
}

bool nevil::arena::update()
{
  _world->step(1.0/30, 1);

  for (auto r : _robots)
  {
    if(r->is_at(_objects.at("switch"), OFF))
    {
      std::cout << "Is at switch" << std::endl;
      _objects.at("switch")->turn_on();
      _objects.at("light")->turn_on();
    }
  }
  // Updating the robots
  for (auto r : _robots)
    r->update(_objects);

  return true;
}

nevil::arena &nevil::arena::operator=(const nevil::arena &rhs)
{
  nevil::arena tmp(rhs);
  *this = std::move(tmp);
  return *this;
}

nevil::arena &nevil::arena::operator=(nevil::arena &&rhs) noexcept
{
  std::swap(_world, rhs._world);
  _robots = std::move(rhs._robots);
  _objects = std::move(rhs._objects);
  return *this;
}