#include "game_config.hxx"

Game_config::Game_config()
        : scene_dims(692, 720),
          frog_dims(42, 42),
          hop_dist(46, 45),
          start(346, 632),
          lifetime(60),
          hop_time(7.0 / 60),
          car_dims(65, 20),
          row_velocities{-10, 10, 10, -10, -10, 0, -10, 10, 10, -10, 10},
          coaster_rows{4, 2, 4, 4, 3, 0, 3, 4, 3, 3, 3},
          kill_zone(0, 0, 692, 356),
          reset_wait_time(45.0 / 60),
          short_log_dims({50,20}),
          medium_log_dims({125,20}),
          long_log_dims({200, 20}),
          three_turtle_dims({125,20}),
          turtle_sumberged_time(10),
          turtle_submerging_time(7),
          turtle_sumbersed_for(3),
          two_turtle_dims({80,20})
{ }

bool
Game_config::in_scene(Game_config::Position const pos) const
{
    return pos.x >= 0 && pos.x <= scene_dims.width &&
           pos.y >= 0 && pos.y <= scene_dims.height;
}

bool
Game_config::in_scene(Game_config::Rectangle const rect) const
{
    return in_scene(rect.top_left()) && in_scene(rect.bottom_left()) &&
           in_scene(rect.top_right()) && in_scene(rect.bottom_right());
}

int
Game_config::row_velocity(int const row) const
{
    return row_velocities.at(row);
}

bool
Game_config::in_object_scene(Position const pos) const
{
    return pos.x >= -150 && pos.x - 300 <= scene_dims.width &&
           pos.y >= 0 && pos.y <= scene_dims.height;
}


