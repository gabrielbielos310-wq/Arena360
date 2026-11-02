#ifndef ARENA360_GAME_STATE_H
#define ARENA360_GAME_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define ARENA360_MAX_PLAYERS 4u

typedef struct {
    float x;
    float y;
    float velocity_x;
    float velocity_y;
    float damage_percent;
    uint8_t stocks;
    bool active;
    bool grounded;
} Arena360PlayerState;

typedef struct {
    Arena360PlayerState players[ARENA360_MAX_PLAYERS];
    uint8_t player_count;
    bool match_active;
} Arena360MatchState;

void arena360_match_reset(Arena360MatchState *match, uint8_t player_count);

#endif
