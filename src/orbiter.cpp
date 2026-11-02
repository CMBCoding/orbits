#include "orbiter.h"
#include "center.h"
#include <bn_sprite_items_drone.h>
#include <bn_rect.h>

/**
 * An object that orbits around a center. Orbits using Hooke's law, as if attached by a 2D spring.
 * The stiffness of the spring in each dimension is center.mass() / FORCE_SCALE.
 */

void Orbiter::update(bn::fixed FORCE_SCALE)
{
    // A vector from the Orbiter to the Center
    bn::fixed_point delta = _center.position() - _sprite.position();

    // Scale the vector by the mass and apply a FORCE_SCALE
    // This is done in two steps instead of having a pre-scaled mass to prevent loss of
    // fixed point precision
    bn::fixed_point force = delta * _center.mass();
    force /= FORCE_SCALE;

    // Update the current velocity with the force
    _velocity += force;

    // Update the position by taking a step by the velocity vector
    _sprite.set_position(_sprite.position() + _velocity);
};

/**
 * Get the sprite.
 */
bn::sprite_ptr Orbiter::get_sprite() {
    return _sprite;
};

/**
 * Get the hitbox.
 */
bn::rect Orbiter::get_hitbox() {
    return _hitbox;
};

/**
 * Set the hitbox.
 */
void Orbiter::set_hitbox(bn::rect hitbox) {
    _hitbox = hitbox;
};

// Creates a constructor of the Orbiter class
Orbiter::Orbiter(bn::fixed_point starting_location, bn::fixed_point starting_velocity, Center &center) : _sprite(bn::sprite_items::drone.create_sprite(starting_location)),
                                                                                                         _velocity(starting_velocity),
                                                                                                         _center(center)
{
}