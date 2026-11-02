#include "center.h"
#include "movement.h"
#include <bn_sprite_items_ship.h>

bn::fixed_point Center::position() {
    return _sprite.position();
}

void Center::update() {
    dPadMoveSprite(_sprite, _speed);
};

bn::fixed Center::mass() {
    return _mass;
}

/**
 * Get the sprite.
 */
bn::sprite_ptr Center::get_sprite() {
    return _sprite;
};

//Creates a constructor of the Center class
Center::Center(bn::fixed_point starting_position, bn::fixed mass, bn::fixed speed) : 
            _sprite(bn::sprite_items::ship.create_sprite(starting_position)),
            _mass(mass),
            _speed(speed) {
}