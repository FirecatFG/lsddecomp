#ifndef CLASS_DREAMSYS
#define CLASS_DREAMSYS

#include "common.h"

//.sbss values
s8 (*gpNavChallengesComplete)[30];
s32 *gpDinamicLinkPenalty;
s32 D_8008ACBC;
s32 D_8008ACC0;
s32 D_8008ACC4;
s32 D_8008ACC8;

typedef struct CinematicCall{
	s16 bank;
	s16 entry;
} CinematicCall;

typedef struct {
	MoodGraphPoint lastMood;
	// 2 bytes unused
	struct sumAxis{
		s32 dynamic;
		s32 upper;
	} sumMoods;
	s32 amountMoods;
} MoodGraphContributor;

typedef struct PlayerSpawnPoint {
	struct MapChunk {
		u8 col;
		u8 row;
	} chunk;
	struct MapTile {
		u8 col;
		u8 row;
	} tile;
	struct RelativePos {
		s16 x;
		s16 y;
		s16 z;
	} position;
} PlayerSpawnPoint;

typedef struct {
	s32 stageID;
	PlayerSpawnPoint position;
	struct Angle{
		s16 angle;
		s16 one;
	} pitch; //Does not do what you think it does
	struct Angle heading;
	struct Angle roll; //Ditto
	s16 timeLimit;
	s32 unknown_value_0x1c;
	s32 day;
} FlashbackEntry;

typedef struct DreamSys {
	struct vtable_DreamSys *vt;
	s8 unknown_values_0x4[32];

	s32 dreamTimer;
	s8 unknown_values_0x28[28];

	s32 unknwon_int_0x44;
	s8 unknown_values_0x48[32];

	bool isFlashbackSession;
	s8 unknown_values_0x6c[200];

	s32 dreamTimeLimit;
	s8 unknown_values_0x138[12];

	MoodGraphContributor areaMoods;
	MoodGraphContributor entityMoods;
	s32 currentStage;
	CinematicCall nextCinematic;
	PlayerSpawnPoint linkCoordinates;
	// 2 bytes unused
	s32 unknown_sdata_0x178;
	s32 currentYear;
	s32 currentDay;
	s32 totalFlasbackUnlockScore;
	s32 navigationFlasbackUnlockScore;
	s32 instanceFlasbackUnlockScore;
	MoodGraphPoint moodPreviousDays[365];
	// 2 bytes unused
	s32 amountFlashbacksAvailable;
	FlashbackEntry storedFlasbacks[10];

	s8 unknown_values_0x5d8[8];

	s8 navChallengesArray[30];
	// 2 bytes unused
	s32 amountDynamicLinksDone;
	s8 unknown_values_0x604[116];

	bool screenShakeOn;
	s32 unknown_word_0x67c;
	s32 unknown_word_0x680;
	s8 unknown_values_0x684[500];

	s32 unk_0x878;
	s32 currentFlashbackIndex;
	s8 unknown_values_0x880[12];

	s32 storedDay;
} DreamSys;

struct vtable_DreamSys{
	u32 unknown_int;
	void *extfunc_17eb0;
	void *Constructor;
	u32 unknown_functions_0xc[13];
	void *func_800588EC;
	u32 unknown_functions_0x44[2];
	void *func_58968;
	u32 unknown_functions_0x50[18];
	void *TimerTick;
	u32 unknown_functions_0x9c[17];
	void *LinkWall;
	u32 unknown_functions_0xe4[8];
	s32 (*GetSetDreamTimeLimit)(DreamSys *this, s32 time);
	u32 unknown_functions_0x104[36];
	void (*InitNewGame)(DreamSys *this);
	void (*GetSetScreenShake)(DreamSys *this, bool *value);
	void *func_8005A2E4;
	s32 (*AdvanceDay)(DreamSys *this);
	void *func_8005A33C;
	void *func_8005A344;
	void *func_8005A350;
	s32 (*StartDay)(DreamSys *this);
	s32 (*EndDay)(DreamSys *this, s32 arg1);
	CinematicCall (*GetCinematic)(DreamSys *this);
	void (*InitSpawnLoc)(DreamSys *this);
	void (*DynamicLink)(DreamSys *this);
	bool (*StaticWallLink)(DreamSys *this, PlayerSpawnPoint *currentPos);
	bool (*LoadNextFlashback)(DreamSys *this, bool unknown);
	u32 unknown_functions_0x1d0[5];
	void *ProcessChunkChange;
	void (*InstanceEffectsOnPlayer)(DreamSys *this, void *entity, int effect);
	void (*GetPreviousDayMood)(DreamSys *this, MoodGraphPoint *target, bool unknown);
	void (*InitMoodContibutors)(DreamSys *this, MoodGraphPoint *special);
	void (*LogChunkMood)(DreamSys *this, PlayerSpawnPoint *currentPos);
	void (*LogInstanceMood)(DreamSys *this,MoodGraphPoint *source);
	void (*UpdateDreamChart)(DreamSys *this, MoodGraphPoint *ret);
	s32 (*GetDreamColor)(DreamSys *this);
	void (*ClearMoodGraph)(DreamSys *this, MoodGraphContributor *contributor);
	void (*LogMood)(DreamSys* this, MoodGraphContributor* layer, MoodGraphPoint* mood);
	void (*GetMoodAverage)(DreamSys *this, MoodGraphContributor *layer, MoodGraphPoint *ret);
	void (*CalcUnlockScore)(DreamSys *this);
	void *GameManager__AddFlashback;
	void *GameManager__FlashbackSaving;
};

typedef enum DreamColors{
	DREAM_COLOR_BLACK, DREAM_COLOR_BLUE,
	DREAM_COLOR_GREEN, DREAM_COLOR_CYAN,
	DREAM_COLOR_RED, DREAM_COLOR_PINK,
	DREAM_COLOR_YELLOW, DREAM_COLOR_WHITE,
}DreamColors;

typedef struct StageSpawn{
	struct MapChunk chunk;
	struct MapTile tile;
	s8 adjustment;
	s8 extra;
}StageSpawn;

typedef struct StaticLinkTrigger{
	struct MapChunk chunk;
	union TriggerTile{
		struct MapTile axis;
		s16 value;
	} tile;
	s8 stage;
	s8 spawnpointIndex;
}StaticLinkTrigger;

//Jumptable holding all of DreamSys "virtual" methods
extern struct vtable_DreamSys DREAMSYS_METHODS;

extern s16 STAGE_TIME_LIMITS[];

extern struct RelativePos SPAWN_POS_ADJUST[];

extern StageSpawn* STAGE_SPAWNPOINTS[];
extern s8 LEN_STAGE_SPAWNPOINTS[];

extern StageSpawn* STAGE_PERMALINK_SPAWNS[];
extern StaticLinkTrigger* STAGE_PERMALINK_TRIGGERS[];
extern s8 LEN_STAGE_PERMALINK_TRIGGERS[];

extern s16 SPECIAL_DAYS[];

extern s8 SPECIAL_COLORS[];

/* This function might be called when the player hits a wall?
It tries to do an static link first, then a dynamic one */
void DreamSys__WallLink(DreamSys *this, void* unk_class_86aa0, int arg2);

/// @brief Sets the overall time limit for the dream and returns its previous value.
/// @param value The new time limit, in seconds. Negative values are stored as-is.
/// @return The previous time limit, in seconds, or -1.
s32 DreamSys__GetSetDreamTimeLimit(DreamSys *this, s32 value);

/// @brief (Re)initializes playthrough-relevant data, like day number, flashabcks, etc.
void DreamSys__InitNewGame(DreamSys *this);

/// @brief Sets whether the camera should shake when the player walks.
/// @param value If True, the screen will shake when the player walks.
/// @return To &value, the previous value of ScreenShakeOn  
void DreamSys__GetSetScreenShake(DreamSys *this, bool *value);

/// @brief Moves the currentDay counter foward one day, looping over on new years.
/// @return Integer between 0 and 364, of the new currentDay value.
s32 DreamSys__AdvanceDay(DreamSys *this);

/// @brief Checks what kind of dream comes next, and executes the appropiate start-of-dream actions.
/// @return ID of the Stage to spawn on. Or -1 if the dream is Special (i.e. non-interactive).
s32 DreamSys__StartDay(DreamSys *this);

/// @brief Executes various end-of-dream actions.
s32 DreamSys__EndDay(DreamSys *this, s32 arg1);

/// @brief Gets the indicies of the Cinematic to be played next, if any. 
/// @return CinematicCall with the currently stored indicies. An Entry value of -1 means no cinematic.
CinematicCall DreamSys__GetCinematic(DreamSys *this);

/// @brief Sets the next spawnpoint to be the intial spawn appropiate for the last day's graph. 
void DreamSys__InitSpawnLoc(DreamSys *this);

/// @brief Handles either dynamic or instance links, based on the value of DreamSys.currentStage
void DreamSys__DynamicLink(DreamSys *this);

/// @brief Test whether a given position in the current stage is a static wall link
/// @param currentPos The player's current position on the stage
/// @return True if a valid link was found, False otherwise
bool DreamSys__StaticWallLink(DreamSys *this, PlayerSpawnPoint *currentPos);

/// @brief Loads the next flashback on a flashback session
/// @return False if it is the end of the flashback session, True otherwise
bool DreamSys__LoadNextFlashback(DreamSys *this, bool unknown);

// Called during some links, but no idea what it actually does
bool ExecuteLink(DreamSys *system, s32 stage, s32 unk1, s32 unk2);

//DreamSys__ProcessChunkChange(DreamSys *this,);

/// @brief Processes the instance actions that directly affect this class, like instance linking and flashback logging.
/// @param entity Pointer to the instance?
/// @param effect Index of the effect to handle.
void DreamSys__InstanceEffectsOnJournal(DreamSys *this, void *entity, s32 effect);

void DreamSys__GetPreviousDayMood(DreamSys *this, MoodGraphPoint *target, bool unknown);

/// @brief (Re)initializes both Mood Contributors in preparation for the start of the day. 
/// @param special If not NULL, both graphs will be initialized with this point logged in. 
void DreamSys__InitMoodContibutors(DreamSys *this, MoodGraphPoint *special);

/// @brief Logs the mood effect of the chunk at the given position.
/// @param currentPos The player's current position on the stage
void DreamSys__LogChunkMood(DreamSys *this, PlayerSpawnPoint *currentPos);

/// @brief Logs the given mood point as an instance mood.
/// @param source Pointer to the mood to get logged.
void DreamSys__LogInstanceMood(DreamSys *this,MoodGraphPoint *source);

/// @brief Calculates the current Overall Mood of the dream based on data from the contributors.
/// @param ret Pointer where the final graph point will be written to. 
void DreamSys__UpdateDreamChart(DreamSys *this, MoodGraphPoint *ret);

/// @brief Gets the color value associated with the current dream mood 
/// @return Enum value of the current mood's color
DreamColors DreamSys__GetDreamColor(DreamSys *this);

/// @brief Calculates the DreamColor for a given mood
/// @param mood The graph point to get a color from
/// @return Enum value of the calculated color
DreamColors CalcDreamColor(MoodGraphPoint *mood);

/// @brief Resets all the values stored in a contributor back to zero.
/// @param contributor MoodGraphContributor to be cleared.
void DreamSys__ClearMoodGraph(DreamSys *this, MoodGraphContributor *contributor);

/// @brief "Logs" a given Mood Effect on the given Contributor.
/// @param layer The contributor that will recieve the mood.
/// @param mood The mood contribution to be logged.
void DreamSys__LogMood(DreamSys* this, MoodGraphContributor* layer, MoodGraphPoint* mood);

/// @brief Calculates the average point of a given Contributor.
/// @param layer The MoodGraphContributor to be calculated.
/// @param ret Pointer where this contributor's average point will be written to.
/// @return To &ret, MoodPoint between (-9,-9) and (9,9).
void DreamSys__GetMoodAverage(DreamSys* this, MoodGraphContributor* layer, MoodGraphPoint* ret);

/// @brief Turns the values of a given mood contributor axis into an useable average
/// @param lank The mood contribution that happened last, which recieves a boost in the code
/// @param sum The cumulative value from all mood contributions
/// @param amount The amount of mood contributions adquired
/// @return Normalized integer between -9 and 9
s32 CalcMoodAxis(s32 lank, s32 sum, s32 amount);

/// @brief Recalculates the total progress towards unlocking the flashback feature
void DreamSys__CalcUnlockScore(DreamSys *this);

/// @brief Saves a "Flashback Spawnpoint" into the player's flashback session.
/// @param stage Stage index of the flashback
/// @param pos Coordinates of the player in the stage
/// @param angles Array of angles, used to make the player face the correct way
/// @param unknown 
/// @param time Time limit of the flashback
/// @param day Day number of the flashback 
void DreamSys__AddFlashback(DreamSys *this, s32 stage, PlayerSpawnPoint* pos, s32 *angles, s32 unknown, s32 time, s32 day);

/// @brief Called by the Grey Man to "erase" your flashback log
void DreamSys__ResetFlashbackList(DreamSys *this);

/// @brief Gets the jumptable of "Virtual methods" assigned to the DreamSys class.
/// @return Pointer to vtable_DreamSys
struct vtable_DreamSys *Get_vtable_DreamSys(void);



/// @brief Initializes the values that will be used by CalcNavigationScore.
/// @param arrayMem Pointer to the array of challenges completed
/// @param linkCounter Pointer to an integer counting up the dynamic/instance links
void InitNavChallengesArray(s8 (*arrayMem)[30], s32 *linkCounter);

/// @brief Calculates a score based on amount of Navigation Challenges achieved
/// @return Integer between 0 and 50,000,000
s32 CalcNavigationScore(void);

/// @brief Gets the stage, spawn point, and time limit of a given point in the graph.
/// @param target Pointer where the spawnpoint found will be written 
/// @param timeLimit Pointer where the time limit will be written to 
/// @param mood The mood that will be used for the calculation
/// @param day Unused?
/// @return The stage index of the initial spawn.
s32 GenerateInitialSpawn(PlayerSpawnPoint *target, s32 *timeLimit, MoodGraphPoint *mood, s32 day);

/// @brief Obtains a random Spawnpoint on, or away from, a given stage.
/// @param target Pointer where the new spawn will be written to
/// @param stg The current stage (or target stage, if negative)
/// @return Stage the spawn belongs to
s32 GetRandomSpawnFromStage(PlayerSpawnPoint *target, s32 stg, s32 unused);
/* This function has two modes of operation, depending on the signage of stg.
   If stg is positive or zero, it behaves as a fully dynamic link *away* from a given stage.
   If stg is negative, it behaves as a "semi-static" link *on* a given stage. (This is the kind of link normally used by instances)
   Regardless of mode, this spawn will count towards the "Dynamic link penalty" of the flashback unlock score.*/

/// @brief Checks whether a given day is Special, and loads a random cinematic if it is. 
/// @param cinematic The CinematicCall that will be written to if a match is found.
/// @param day The day number to check against (1-indexed).
/// @return The pointer to this dream's graph contribution, or NULL if the dream is *not* Special.
MoodGraphPoint *IsDaySpecial(CinematicCall *cinematic, int day);

#endif