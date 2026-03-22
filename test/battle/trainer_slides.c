#include "global.h"
#include "test/battle.h"
#include "battle_setup.h"

// SINGLES TESTS START
AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Before First Turn")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_BEFORE_FIRST_TURN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("Trainer A: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Player Lands First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT);
        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_LASER_FOCUS); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the player lands their first critical hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Enemy Lands First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponent);
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the enemy lands their first critical hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Player Lands First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE);
        ASSUME((GetMoveType(MOVE_VINE_WHIP)) == GetSpeciesType(SPECIES_BULBASAUR, 0));
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP); }
    } SCENE {
        MESSAGE("Bulbasaur used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, player);
        MESSAGE("Trainer A: Player lands their first STAB move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Player Lands First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_BITE); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Trainer A: This message plays after the player lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Player Lands First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponent,1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the player KOs one enemy mon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Enemy Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ENEMY_MON_UNAFFECTED);
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        MESSAGE("It doesn't affect the opposing Glalie…");
        MESSAGE("Trainer A: Player attacked enemy with ineffective move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_LAST_SWITCHIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponent,1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the enemy switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        MESSAGE("Trainer A: Enemy last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { Attack(999); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(1); Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_FALSE_SWIPE); }
    } SCENE {
        MESSAGE("Trainer A: Enemy last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_MEGA_EVOLUTION);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LOPUNNY) { Item(ITEM_LOPUNNITE); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the enemy activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("The opposing Lopunny has Mega Evolved into Mega Lopunny!");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_Z_MOVE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the enemy activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponent);
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Dynamax")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the enemy activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponent);
    }
}

#if MAX_MON_ITEMS > 1
SINGLE_BATTLE_TEST("Trainer Slide: Mega Evolution (Multi)")
{
    gBattleTestRunnerState->data.recordedBattle.opponentA = TRAINER_SLIDE_MEGA_EVOLUTION;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LOPUNNY) {Items(ITEM_ORAN_BERRY, ITEM_LOPUNNITE); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("This message plays before the enemy activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("The opposing Lopunny has Mega Evolved into Mega Lopunny!");
    }
}

SINGLE_BATTLE_TEST("Trainer Slide: Z Move (Multi)")
{
    gBattleTestRunnerState->data.recordedBattle.opponentA = TRAINER_SLIDE_Z_MOVE;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Items(ITEM_ORAN_BERRY, ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        MESSAGE("This message plays before the enemy activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponent);
    }
}
#endif
