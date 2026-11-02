#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>
#include <bn_keypad.h>
#include "orbiter.h"
#include "hitbox.h"
#include "mothership.h"
#include <bn_rect.h>
#include <bn_log.h>
// A scaling factor by which to reduce the force applied when orbiting
// Important for numerical stability
static constexpr bn::fixed FORCE_SCALE = 10;

// Maximum number of orbiters allowed on the screen
static constexpr int MAX_ORBITERS = 30;

// Default starting posiiton and velocity for Orbiter
static constexpr bn::fixed_point ORBITER_START_POSIITON = {0, 0};
static constexpr bn::fixed_point ORBITER_START_VELOCITY = {0, 5};

static constexpr bn::size ORBITER_SIZE = {16, 16};

int main() {
    bn::core::init();

    Center center = Center({30, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};
    Mothership mothership1 = Mothership({60, 60});
    // Mothership mothership2 = Mothership({0, 60});
    // Mothership mothership3 = Mothership({10, 40});
    
    while(true) {
        // Add an orbiter when A is pressed if there's room
        if(bn::keypad::a_pressed()) {
            if(orbiters.size() < MAX_ORBITERS) {
                orbiters.push_back(Orbiter(ORBITER_START_POSIITON, ORBITER_START_VELOCITY, center));
            }
        }

        // Remove an orbiter when B is pressed if there's at least one
        if (bn::keypad::b_pressed()) {
            if(orbiters.size() > 0) {
                orbiters.pop_back();
            }
        }

        center.update();
        for(Orbiter& orbiter : orbiters) {
            orbiter.set_hitbox(create_orbiter_hitbox(orbiter, ORBITER_SIZE));
            orbiter.update(FORCE_SCALE);
        }

        

        bn::core::update();
    }
}