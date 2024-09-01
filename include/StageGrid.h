#ifndef STAGE_GRID
#define STAGE_GRID

#include "common.h"

typedef struct StageGridDimensions{
    s16 columns;
    s16 rows;
    bool isVertical;
}StageGridDimensions;

typedef struct StageChunk{
    s8 column;
    s8 row;
}StageChunk;

struct simplePair{
    s8 x; s8 y;
};

extern StageGridDimensions STAGE_GRID_DIMENSIONS[];

extern MoodGraphPoint* STAGE_CHUNK_MOODS[];

extern StageGridDimensions *GetStageGridDimensionsTable(s32 *unknown);

extern StageGridDimensions *GetStageGridDimensions(s32 index);

/// @brief Gets the stage and chunk associated with a given point on the mood graph.
/// @param ret Pointer where the found chunk will be written to
/// @param mood The mood point to be checked
/// @return Stage index the found chunk belongs to
extern s32 GetStageChunkFromMood(StageChunk *ret, MoodGraphPoint *mood);

/// @brief Gets the mood contribution associated with a given stage and chunk.
/// @param stage The stage index the chunk belongs to.
/// @param chunk The chunk coordinates to be checked
/// @return Mood graph point of the given chunk's mood
extern MoodGraphPoint *GetMoodFromStageChunk(s32 stage, StageChunk *chunk);

#endif