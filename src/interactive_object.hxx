#pragma once

#include <ge211.hxx>

#include "game_config.hxx"

/// Interactive objects within the game
class Interactive_object
{
    //
    // TYPE ALIASES
    //

    /// A direction is always {1, 0}, {-1, 0}, {0, 1}, or {0, -1}.
    /// It has not been made an enum class because using dims simplifies
    /// many operations
    using Direction = ge211::Dims<int>;
    using Dimesion = ge211::Dims<int>;
    using Position = ge211::Posn<int>;
    using Rectangle = ge211::Rect<int>;

    //
    // PUBLIC MEMBER FUNCTIONS
    //

    enum object_type {lilypad, occupied_lilypad, short_log, medium_log,
            long_log, turtle, submerged_turtle, car};

    /// Default constructor
    explicit Interactive_object(Game_config const&, object_type, int, Position);

    /// Moves the object
    void move(int , Game_config const&);

    /// Moves the object in time one frame
    void move_to(Game_config const&);

private:

    /// The objects hit box
    Rectangle body_;

    /// Object Type
    object_type type_;

    /// Specifies which row the object is int
    int row_;

    /// The direction and speed of movement per second;
    int velocity_;

    /// Determines if the interactive object has the ability to kill
    bool hostile_;



};