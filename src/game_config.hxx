#pragma once

#include <ge211.hxx>

struct Game_config{

    //
    // TYPE ALIASES
    //

    using Dimension = ge211::Dims<int>;
    using Position = ge211::Posn<int>;
    using Rectangle = ge211::Rect<int>;

    /// Constructor
    Game_config();

    /// Window dimensions
    Dimension scene_dims;

    /// Frog dimensions
    Dimension frog_dims;

    /// Amount frog moves per step in the x and y directions
    Dimension hop_dist;

    /// Starting position for frog
    Position start;

    /// The time a frog has to reach a home
    size_t lifetime;

    /// The minimum time between frog hops
    size_t hop_time;

    /// Car dimensions
    Dimension car_dims;

    /// Velocities of objects for each given row
    std::vector<int> row_velocities;

    /// Number of cars in each row
    std::vector<int> car_rows;




    /// Returns whether a position is a valid position on screen
    bool in_scene(Position const) const;

    /// Returns whether a rectangle fits on screen
    bool in_scene(Rectangle const) const;

    /// Returns the row velocity in pixels per 4 frames
    int row_velocity(int const) const;


    /// Returns whether or not a position is outside the object scene, which
    /// is 105 pixels off either the left or right of the actual scene dims
    bool in_object_scene(Position const) const;
};