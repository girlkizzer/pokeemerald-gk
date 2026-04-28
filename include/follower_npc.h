#ifndef GUARD_FOLLOWER_NPC_H
#define GUARD_FOLLOWER_NPC_H

#include "constants/follower_npc.h"

#define MOVEMENT_INVALID 0xFE

struct FollowerNPCSpriteGraphics
{
    u16 normalId;
    u16 machBikeId;
    u16 acroBikeId;
    u16 surfId;
    u16 underwaterId;
<<<<<<< HEAD
    bool8 hasRunningFrames;
=======
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
};

enum FollowerNPCDataTypes
{
    FNPC_DATA_IN_PROGRESS,
    FNPC_DATA_WARP_END,
    FNPC_DATA_SURF_BLOB,
    FNPC_DATA_COME_OUT_DOOR,
<<<<<<< HEAD
    FNPC_DATA_FORCED_MOVEMENT,
    FNPC_DATA_OBJ_ID,
    FNPC_DATA_CURRENT_SPRITE,
    FNPC_DATA_DELAYED_STATE,
=======
    FNPC_DATA_OBJ_ID,
    FNPC_DATA_CURRENT_SPRITE,
    FNPC_DATA_DELAYED_STATE,
    FNPC_DATA_MAP_ID,
    FNPC_DATA_MAP_NUM,
    FNPC_DATA_MAP_GROUP,
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
    FNPC_DATA_EVENT_FLAG,
    FNPC_DATA_GFX_ID,
    FNPC_DATA_FOLLOWER_FLAGS,
    FNPC_DATA_BATTLE_PARTNER
};

enum FollowerNPCSpriteTypes
{
    FOLLOWER_NPC_SPRITE_INDEX_NORMAL,
    FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE,
    FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE,
    FOLLOWER_NPC_SPRITE_INDEX_SURF,
    FOLLOWER_NPC_SPRITE_INDEX_UNDERWATER,
};

enum FollowerNPCDoorStairsStates
{
    FNPC_DOOR_NONE,
<<<<<<< HEAD
    FNPC_DOOR_NEEDS_TO_EXIT,
    FNPC_DOOR_NO_POS_SET
=======
    FNPC_DOOR_NEEDS_TO_EXIT
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
};

enum FollowerNPCWarpEndStates
{
    FNPC_WARP_NONE,
    FNPC_WARP_REAPPEAR
};

enum FollowerNPCSurfBlobStates
{
    FNPC_SURF_BLOB_NONE,
    FNPC_SURF_BLOB_NEW,
    FNPC_SURF_BLOB_RECREATE,
    FNPC_SURF_BLOB_DESTROY
};

<<<<<<< HEAD
enum FollowerNPCOutOfDoorTaskStates
{
=======
enum FollowerNPCOutOfDoorTaskStates{
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
    OPEN_DOOR,
    NPC_WALK_OUT,
    CLOSE_DOOR,
    UNFREEZE_OBJECTS,
    REALLOW_MOVEMENT
};

<<<<<<< HEAD
enum FollowerNPCHandleEscalatorFinishTaskStates
{
=======
enum FollowerNPCHandleEscalatorFinishTaskStates{
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
    MOVE_TO_PLAYER_POS,
    WAIT_FOR_PLAYER_MOVE,
    SHOW_FOLLOWER_DOWN,
    MOVE_FOLLOWER_DOWN,
    SHOW_FOLLOWER_UP,
    MOVE_FOLLOWER_UP,
    MOVEMENT_FINISH
};

<<<<<<< HEAD
enum FollowerNPCForcedMovementStates
{
    FNPC_FORCED_NONE,
    FNPC_FORCED_FOLLOW,
    FNPC_FORCED_STAY
};

#define FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES    0x1

#define FNPC_NONE   0
#define FNPC_ALWAYS 2

=======
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
void SetFollowerNPCData(enum FollowerNPCDataTypes type, u32 value);
const u8 *GetFollowerNPCScriptPointer(void);
u32 GetFollowerNPCData(enum FollowerNPCDataTypes type);
void ClearFollowerNPCData(void);

<<<<<<< HEAD
void CreateFollowerNPC(u32 gfx, u32 followerFlags, const u8 *scriptPtr);
void DestroyFollowerNPC(void);
u32 DetermineFollowerNPCState(struct ObjectEvent *follower, u32 state, enum Direction direction);
=======
u32 DetermineFollowerNPCState(struct ObjectEvent *follower, u32 state, u32 direction);
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
void SetFollowerNPCSprite(u32 spriteIndex);

bool32 PlayerHasFollowerNPC(void);
void NPCFollow(struct ObjectEvent *npc, u32 state, bool32 ignoreScriptActive);
void CreateFollowerNPCAvatar(void);
void FollowerNPC_HandleSprite(void);
<<<<<<< HEAD
enum Direction DetermineFollowerNPCDirection(struct ObjectEvent *player, struct ObjectEvent *follower);
=======
u32 DetermineFollowerNPCDirection(struct ObjectEvent *player, struct ObjectEvent *follower);
>>>>>>> 8aad1c5c6dbcfa927a014708348fad476425ab43
u32 GetFollowerNPCObjectId(void);
bool32 CheckFollowerNPCFlag(u32 flag);
bool32 FollowerNPC_IsCollisionExempt(struct ObjectEvent *obstacle, struct ObjectEvent *collider);
void HideNPCFollower(void);
void FollowerNPC_WarpSetEnd(void);

bool32 FollowerNPCCanBike(void);
void FollowerNPC_HandleBike(void);

void FollowerNPC_FollowerToWater(void);
void FollowerNPC_SetIndicatorToRecreateSurfBlob(void);
void FollowerNPC_BindToSurfBlobOnReloadScreen(void);
void PrepareFollowerNPCDismountSurf(void);

bool32 FollowerNPCComingThroughDoor(void);
void FollowerNPC_SetIndicatorToComeOutDoor(void);

void EscalatorMoveFollowerNPC(u32 movementType);
void EscalatorMoveFollowerNPCFinish(void);

void FollowerNPCWalkIntoPlayerForLeaveMap(void);
void FollowerNPCHideForLeaveMap(struct ObjectEvent *follower);
void FollowerNPCReappearAfterLeaveMap(struct ObjectEvent *follower, struct ObjectEvent *player);
void FollowerNPCFaceAfterLeaveMap(void);

bool32 FollowerNPCIsBattlePartner(void);
bool32 IsNPCFollowerWildBattle(void);
void PrepareForFollowerNPCBattle(void);
void RestorePartyAfterFollowerNPCBattle(void);
void FollowerNPC_TryRemoveFollowerOnWhiteOut(void);

void Task_MoveNPCFollowerAfterForcedMovement(u8 taskId);
void Task_HideNPCFollowerAfterMovementFinish(u8 taskId);

#endif // GUARD_FOLLOWER_NPC_H
