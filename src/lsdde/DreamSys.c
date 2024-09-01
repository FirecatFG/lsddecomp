#include "common.h"

#include "MEMORY.H"
#include "RAND.H"

#include "DreamSys.h"

#include "StageGrid.h"

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80058774);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__DreamSys);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__func_588ec);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__func_58968);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80058A94);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80058B08);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80058C58);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__TimerTick);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80058E8C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80058F18);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__WallLink);

void func_800590E0(void) {
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800590E8);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059148);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800591B4);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059310);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005931C);

s32 DreamSys__GetSetDreamTimeLimit(DreamSys* this, s32 value) {
    const s32 TARGET_FPS = 15;

    s32 newLimit;
    s32 oldLimit;
    u32 oldLimitUnsigned;

    newLimit = value;
    if (newLimit >= 0) {
        newLimit *= TARGET_FPS;
    }
    
    oldLimit = this->dreamTimeLimit;
    oldLimitUnsigned = oldLimit;
    this->dreamTimeLimit = newLimit;

    if (oldLimit >= 0) {
        oldLimit = oldLimitUnsigned / TARGET_FPS;
    }
    return oldLimit;
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059360);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005937C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059384);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005938C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059394);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800593D8);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005942C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005950C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059590);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059598);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800595A0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800595A8);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059610);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005966C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800596E8);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800597C0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059814);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_800598E8);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059A1C);

void func_80059A48(void) {
}

void func_80059A50(void) {
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059A58);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059AEC);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059B50);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059BD4);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059BE0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059D1C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059E3C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_80059E98);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A050);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A0B0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A134);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A168);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A184);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A1A4);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A1B0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A1EC);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A1F4);

//https://decomp.me/scratch/jW6xM
INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__InitNewGame);
/*void GameManager__InitNewGame(GameManager* this) {
    
    this->currentYear = 0;
    this->currentDay = 0;
    this->totalFlasbackUnlockScore = 0;
    this->navigationFlasbackUnlockScore = 0;
    this->instanceFlasbackUnlockScore = 0;
    this->amountFlashbacksAvailable = 0;
    //this->unknown_values_0x5d8[7] = 0;
    //this->unknown_values_0x5d8[0] = 0;
    this->screenShakeOn = 1;
    this->unknown_word_0x67c = 0;
    this->unknown_word_0x680 = 0;
    this->unknown_sdata_0x178 = D_8008ABE0;
    InitNavChallengesArray((s8 (*)[0x1E]) this->navChallengesArray, &this->amountDynamicLinksDone);
    memset((u8* ) this->unknown_values_0x684, 0U, 0x1F4);
}*/

void DreamSys__GetSetScreenShake(DreamSys *this, bool *value) {
    bool oldValue;

    oldValue = this->screenShakeOn;
    this->screenShakeOn = *value;
    *value = oldValue;
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A2E4);

s32 DreamSys__AdvanceDay(DreamSys *this) {
    s32 nextDay = this->currentDay + 1;
    this->currentDay = nextDay;
    if (nextDay > 364) {
        this->currentDay = 0;
        this->currentYear ++;
    }
    return this->currentDay;
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A33C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A344);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A350);

s32 DreamSys__StartDay(DreamSys *this) {
    MoodGraphPoint *specialMood;
    s32 startStage;

    this->currentFlashbackIndex = 0;
    this->dreamTimer = 0;
    this->storedDay = this->currentDay;

    if (this->isFlashbackSession) {

        this->vt->LoadNextFlashback(this, 1);

    } else {

        specialMood = IsDaySpecial(&this->nextCinematic, this->currentDay + 1);
        this->vt->InitMoodContibutors(this, specialMood);
        if (specialMood != NULL) {
            return -1;
        }
        this->vt->InitSpawnLoc(this);

    }

    startStage = this->currentStage;
    return startStage;
}

s32 DreamSys__EndDay(DreamSys *this, s32 arg1) {

    this->currentDay = this->storedDay;

    if ((this->isFlashbackSession == false) && (arg1 == 0)) {

            this->vt->CalcUnlockScore(this);
            this->vt->UpdateDreamChart(this, &this->moodPreviousDays[this->currentDay]);
            this->vt->AdvanceDay(this);

    } else if (arg1 == 2) {

            this->vt->InitNewGame(this);
            this->unk_0x878 = 1;
        
    }
    return this->isFlashbackSession;
}

CinematicCall DreamSys__GetCinematic(DreamSys *this) {
    return this->nextCinematic;
}

void DreamSys__InitSpawnLoc(DreamSys *this) {
    MoodGraphPoint mood;
    s32 timeLimit;

    this->vt->GetPreviousDayMood(this, &mood, 1);

    this->currentStage = GenerateInitialSpawn(
        &this->linkCoordinates, 
        &timeLimit,
        &mood, 
        this->currentDay
    );
    timeLimit = this->vt->GetSetDreamTimeLimit(this, timeLimit);
    this->unknwon_int_0x44 = 0xB;
}

void DreamSys__DynamicLink(DreamSys *this) {
    s32 stage;
    
    if (this->unknwon_int_0x44 == 0) {
        stage = GetRandomSpawnFromStage(&this->linkCoordinates, this->currentStage, this->dreamTimer);
        ExecuteLink(this, stage, 0xC, 1);
    }
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__StaticWallLink);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__LoadNextFlashback);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A700);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A7A0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A82C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", ExecuteLink);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005A9CC);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005AB2C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005AC24);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005AD68);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005AE40);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005AF64);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005AFD0);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__ProcessChunkChange);

//TODO Define Entities
INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__InstanceEffectsOnJournal);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__GetPreviousDayMood);

void DreamSys__InitMoodContibutors(DreamSys *this, MoodGraphPoint *special) {
    MoodGraphContributor *areaMoods;
    MoodGraphContributor *entityMoods;

    areaMoods = &this->areaMoods;
    entityMoods = &this->entityMoods;

    this->vt->ClearMoodGraph(this, areaMoods);
    this->vt->ClearMoodGraph(this, entityMoods);

    if (special != NULL) {
        this->vt->LogMood(this, areaMoods, special);
        this->vt->LogMood(this, entityMoods, special);
    }
}

void DreamSys__LogChunkMood(DreamSys *this, PlayerSpawnPoint *currentPos) {
    MoodGraphPoint* mood;

    mood = GetMoodFromStageChunk(this->currentStage, (StageChunk *) &currentPos->chunk);

    this->vt->LogMood(this, &this->areaMoods, mood);
}

void DreamSys__LogInstanceMood(DreamSys *this, MoodGraphPoint *source) {
    this->vt->LogMood(this, &this->entityMoods, source);
}

void DreamSys__UpdateDreamChart(DreamSys *this, MoodGraphPoint *ret) {
    MoodGraphPoint areaPoint;
    MoodGraphPoint entityPoint;

    this->vt->GetMoodAverage(this, &this->areaMoods, &areaPoint);
    this->vt->GetMoodAverage(this, &this->entityMoods, &entityPoint);
    if (this->entityMoods.amountMoods == 0) {
        entityPoint.value = areaPoint.value;
    }
    ret->axis.dynamic = (s8) ((s32) (areaPoint.axis.dynamic + entityPoint.axis.dynamic) / 2);
    ret->axis.upper = (s8) ((s32) (areaPoint.axis.upper + entityPoint.axis.upper) / 2);
}

DreamColors DreamSys__GetDreamColor(DreamSys *this) {
    MoodGraphPoint currentMood;

    this->vt->UpdateDreamChart(this, &currentMood);
    return CalcDreamColor(&currentMood);
}

//https://decomp.me/scratch/KwyZr
INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", CalcDreamColor);
/*enum DreamColors CalcDreamColor(MoodGraphPoint *mood) {
    s8 colorPoint[2];
    s32 i;

    colorPoint[0] = mood->axis.dynamic;
    colorPoint[1] = mood->axis.upper;
    for (i = 0; i < 2; i++) {
        if (colorPoint[i] >= 4) {
            colorPoint[i] = 2;
        } else if (colorPoint[i] < -3) {
            colorPoint[i] = 0;
        } else {
            colorPoint[i] = 1;
        }
    }
    return (enum DreamColors) D_80087E14[colorPoint[0]][colorPoint[1]];
}*/


void DreamSys__ClearMoodGraph(DreamSys *this, MoodGraphContributor *contributor) {
    contributor->lastMood.value = 0;
    contributor->sumMoods.upper = 0;
    contributor->sumMoods.dynamic = 0;
    contributor->amountMoods = 0;
}

void DreamSys__LogMood(DreamSys* this, MoodGraphContributor* layer, MoodGraphPoint* mood) {
    layer->lastMood.value = mood->value;
    layer->sumMoods.dynamic += mood->axis.dynamic;
    layer->sumMoods.upper += mood->axis.upper;
    layer->amountMoods += 1;
}

void DreamSys__GetMoodAverage(DreamSys* this, MoodGraphContributor* layer, MoodGraphPoint* ret) {
    s32 amountMoods;

    amountMoods = layer->amountMoods;
    if (amountMoods != 0) {
        ret->axis.dynamic = CalcMoodAxis(
		    (s32) layer->lastMood.axis.dynamic, 
		    layer->sumMoods.dynamic, 
		    layer->amountMoods
	    );
        ret->axis.upper = CalcMoodAxis(
		    (s32) layer->lastMood.axis.upper,
		    layer->sumMoods.upper, 
		    layer->amountMoods
	    );
        return;
    }
    ret->value = layer->lastMood.value;
    return;
}

s32 CalcMoodAxis(s32 lank, s32 sum, s32 amount) {
    s32 average;

    average = (sum / amount) + (lank / 3);
    
    if (average > 9) {
        average = -9;
    } else if (average < -9) {
        average = 9;
    }
    return average;
}

void DreamSys__CalcUnlockScore(DreamSys *this) {
    s32 instanceScore;

    this->navigationFlasbackUnlockScore = CalcNavigationScore();

    instanceScore = this->instanceFlasbackUnlockScore;
    if (instanceScore < 0) {
        this->instanceFlasbackUnlockScore = 0;
    } else if (instanceScore > 50000000) {
        this->instanceFlasbackUnlockScore = 50000000;
    }
    this->totalFlasbackUnlockScore = this->navigationFlasbackUnlockScore + this->instanceFlasbackUnlockScore;
}

//https://decomp.me/scratch/bKLHy
INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__AddFlashback);
/*void DreamSys__AddFlashback(DreamSys *this, s32 stage, PlayerSpawnPoint *pos, s32 *angles, s32 unknown, s32 time, s32 day) {
    s32 temp_v1;
    s32 var_v0;
    FlashbackEntry *flashback;

    temp_v1 = this->amountFlashbacksAvailable;
    if (temp_v1 < 0xA) {
        this->amountFlashbacksAvailable = temp_v1 + 1;
        var_v0 = temp_v1 * 9;
    } else {
        var_v0 = (this->dreamTimer % 9) * 9;
    }
    flashback = this->storedFlasbacks + (var_v0 * 4);
    flashback->stageID = stage;
    flashback->position = *pos;
    flashback->pitch = *(struct Angle*) angles[0];
    flashback->heading = *(struct Angle*) angles[1];
    flashback->roll = *(struct Angle*) angles[2];
    flashback->unknown_value_0x1c = (s16) unknown;
    flashback->timeLimit = (s16) time;
    flashback->day = day;
}*/

//TODO: Define Player Character
INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", DreamSys__FlashbackSaving);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005B8FC);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005B904);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005B990);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BA20);

struct vtable_DreamSys *Get_DreamSys_vtable(void) {
    return &DREAMSYS_METHODS;
}

void InitNavChallengesArray(s8 (*arrayMem)[30], s32 *linkCounter) {
    s32 i;

    for(i = 0; i < 30; i++) {
        (*arrayMem)[i] = 0;
    }
    gpNavChallengesComplete = arrayMem;
    *linkCounter = 0;
    gpDinamicLinkPenalty = linkCounter;
}

s32 CalcNavigationScore(void)
{
  s32 currentScore = 0;
  s8 (*array)[30] = gpNavChallengesComplete;
  s32 POINTS_PER_COMPLETION = 1000000;
  s32 i;
  for (i = 0; i < 30; i++){
    if ((*array)[i] != 0) {
      currentScore = currentScore + POINTS_PER_COMPLETION;
    }
  }
  if (currentScore >= 30000000) {
    currentScore = 50000000;
  }
  currentScore = currentScore - ((*gpDinamicLinkPenalty) * 11024);
  if (currentScore < 0) {
    currentScore = 0;
  }
  return currentScore;
}

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BB14);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", GetRandomSpawnFromStage);
/*s32 GetRandomSpawnFromStage(PlayerSpawnPoint *target, s32 stg, s32 unused) {
    StageSpawn *spawn;
    s32 newStage;

    if (stg >= 0) {
        newStage = rand() % 6;
        if (newStage == stg) {
            newStage += 1;
            if (newStage > 5) {
                newStage = 0;
            }
        }
    } else {
        newStage = -stg;
    }

    spawn = &STAGE_SPAWNPOINTS[newStage][rand() % (s32) LEN_STAGE_SPAWNPOINTS[newStage]];
    
    target->tile = spawn->tile;
    target->chunk= spawn->chunk;
    target->position = (SPAWN_POS_ADJUST[spawn->adjustment]);
    
    *gpDinamicLinkPenalty += 1;
    return newStage;
}*/

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", TestForStaticLink);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", Test4TunnelLinks);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BD3C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BE28);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BE90);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BF48);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BF68);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", Test4InstantTeleporters);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005BFC4);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", Test4StaircaseNodes);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005C02C);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", func_8005C118);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", GetStaticSpawn);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", GenerateInitialSpawn);

INCLUDE_ASM("asm/lsdde/nonmatchings/DreamSys", IsDaySpecial);
