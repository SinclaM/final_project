#pragma once

#include "model.hxx"

class View
{
public:

    //
    // TYPE ALIASES
    //

    using Direction = ge211::Dims<int>;
    using Dimensions = ge211::Dims<int>;
    using Position = ge211::Posn<int>;
    using Rectangle = ge211::Rect<int>;
    using Image = ge211::Image_sprite;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    /// Communicate desired window size to controller
    Dimensions initial_window_dimensions() const;

    /// Communicate desired window name to controller
    std::string initial_window_title() const;

private:
    //
    // PRIVATE HELPERS
    //

    /// Add the appropriate frog sprite
    void draw_frog(ge211::Sprite_set& set);

    void draw_coasters(ge211::Sprite_set& set);

    //
    // PRIVATE DATA MEMBERS
    //
    Model const& model_;

    /// The sprites for the frog
    Image const frog_up_sprite;
    Image const frog_right_sprite;
    Image const frog_down_sprite;
    Image const frog_left_sprite;
    Image const frog_dead_sprite;

    /// Background
    Image const background;

    /// Sprites for the cars
    Image const racecar_1_sprite;
    Image const tractor_sprite;
    Image const pink_car_sprite;
    Image const racecar_2_sprite;
    Image const truck_sprite;

    /// Logs
    Image const small_log_sprite;
    Image const medium_log_sprite;
    Image const long_log_sprite;

    /// Turtles
    Image const two_turtles_sprite;
    Image const three_turtles_sprite;
    Image const two_turtles_diving_sprite;
    Image const three_turtles_diving_sprite;
};
