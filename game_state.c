#include "game_state.h"

void arena360_match_reset(Arena360MatchState *match, uint8_t player_count)
{
    if (match == 0) {
        return;
    }

    if (player_count > ARENA360_MAX_PLAYERS) {
        player_count = ARENA360_MAX_PLAYERS;
    }

    match->player_count = player_count;
    match->match_active = false;

    for (uint8_t i = 0; i < ARENA360_MAX_PLAYERS; ++i) {
        Arena360PlayerState *player = &match->players[i];
        player->x = 0.0f;
        player->y = 0.0f;
        player->velocity_x = 0.0f;
        player->velocity_y = 0.0f;
        player->damage_percent = 0.0f;
        player->stocks = 3;
        player->active = (i < player_count);
        player->grounded = false;
    }
}
