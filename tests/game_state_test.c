#include "game_state.h"

#include <stdio.h>

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "%s:%d: check failed: %s\n", __FILE__, __LINE__, #condition); \
        return 1; \
    } \
} while (0)

static int check_reset(uint8_t requested, uint8_t expected)
{
    Arena360MatchState match = {0};
    match.player_count = 99;
    match.match_active = true;
    for (unsigned i = 0; i < ARENA360_MAX_PLAYERS; ++i) {
        match.players[i] = (Arena360PlayerState) {
            .x = 1.0f, .y = -1.0f, .velocity_x = 2.0f, .velocity_y = -2.0f,
            .damage_percent = 100.0f, .stocks = 0, .active = true, .grounded = true
        };
    }

    arena360_match_reset(&match, requested);
    CHECK(match.player_count == expected);
    CHECK(!match.match_active);
    for (unsigned i = 0; i < ARENA360_MAX_PLAYERS; ++i) {
        const Arena360PlayerState *player = &match.players[i];
        CHECK(player->x == 0.0f);
        CHECK(player->y == 0.0f);
        CHECK(player->velocity_x == 0.0f);
        CHECK(player->velocity_y == 0.0f);
        CHECK(player->damage_percent == 0.0f);
        CHECK(player->stocks == 3);
        CHECK(player->active == (i < expected));
        CHECK(!player->grounded);
    }
    return 0;
}

int main(void)
{
    arena360_match_reset(NULL, 4);
    CHECK(check_reset(0, 0) == 0);
    CHECK(check_reset(1, 1) == 0);
    CHECK(check_reset(2, 2) == 0);
    CHECK(check_reset(3, 3) == 0);
    CHECK(check_reset(4, 4) == 0);
    CHECK(check_reset(5, 4) == 0);
    CHECK(check_reset(UINT8_MAX, 4) == 0);
    return 0;
}
