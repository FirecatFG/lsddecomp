#include "common.h"
#include "StageGrid.h"

#define LENGTH_DIMENSIONS_TABLE 14

StageGridDimensions STAGE_GRID_DIMENSIONS[LENGTH_DIMENSIONS_TABLE] = {
    {1,5,true},     //Apartment
    {3,2,false},    //Pit
    {6,6,false},    //Kyoto
    {16,16,false},  //Natural
    {6,5,false},    //Happy
    {5,6,false},    //Violence
    {1,6,true},     //Tower
    {5,1,false},    //Palace
    {1,3,false},    //Flesh
    {1,2,false},    //Clockwork
    {3,1,false},    //Hallway
    {4,3,false},    //Heaven
    {4,5,false},    //Void
    {2,2,false}     //Park
};

struct simplePair STG00_CHUNK_MOODS[] = {
    { 0,-3},
    { 1, 1},
    {-1, 1},
    { 0, 0},
    {-5,-7},
};
struct simplePair STG01_CHUNK_MOODS[] = {
    { 7, 1},{ 1, 2},{ 8,-6},
    { 9, 0},{ 0,-9},{-8,-6},
};
struct simplePair STG02_CHUNK_MOODS[] = {
    { 0, 9},{ 1, 5},{ 2, 5},{ 2, 4},{ 2, 3},{ 3, 3},
    { 3, 2},{ 4, 2},{ 4, 1},{ 3, 1},{ 3, 0},{ 2, 0},
    { 2,-1},{ 1,-1},{ 1,-2},{ 1,-4},{ 9, 0},{ 1,-5},
    { 0,-5},{-1,-5},{-1,-4},{-1,-2},{-1,-1},{-2,-1},
    {-2, 0},{-3, 0},{-3, 1},{-4, 1},{-4, 2},{-3, 2},
    {-3, 3},{-2, 3},{-2, 4},{-2, 5},{-1, 5},{ 1, 3},
};
struct simplePair STG03_CHUNK_MOODS[] = {
    { 9, 0},{ 9, 0},{ 6, 7},{ 6, 6},{ 9, 0},{ 9, 0},{ 7, 6},{ 9, 0},
    { 9, 0},{ 9, 0},{ 7, 5},{ 9, 0},{ 8, 5},{ 9, 5},{ 9, 0},{ 9, 0},
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 4},{ 9, 3},{ 9, 2},{ 9, 1},{ 9, 0},
    { 9,-1},{ 9, 0},{ 9,-2},{ 9,-3},{ 9,-4},{ 9,-5},{ 8,-5},{ 7,-5},
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},{ 7,-6},{ 6,-6},{ 6,-7},
    {-6,-7},{-6,-6},{ 9, 0},{-7,-6},{-7,-5},{-8,-5},{-9,-5},{ 9, 0},
    { 9, 0},{ 9, 0},{ 9, 0},{-9,-4},{-9,-3},{-9,-2},{-9,-1},{-9, 0},
    {-9, 1},{-9, 2},{-9, 3},{-9, 4},{-9, 5},{-8, 5},{-7, 5},{-7, 6},
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},{-6, 6},{-6, 7},{-1, 7},{ 0, 7},
    { 1, 7},{ 1, 6},{ 2, 6},{ 3, 6},{ 4, 6},{ 5, 6},{ 5, 5},{ 9, 0},
    { 9, 0},{ 5, 4},{ 6, 4},{ 7, 4},{ 8, 4},{ 8, 3},{ 8, 2},{ 8, 1},
    { 8, 0},{ 8,-1},{ 8,-2},{ 8,-3},{ 8,-4},{ 7,-4},{ 6,-4},{ 9, 0},
    { 9, 0},{ 5,-4},{ 5,-5},{ 5,-6},{ 4,-6},{ 3,-6},{ 2,-6},{ 1,-6},
    {-1,-6},{-2,-6},{-3,-6},{-4,-6},{-5,-6},{ 9, 0},{-5,-5},{ 9, 0},
    { 9, 0},{ 9, 0},{-5,-4},{-6,-4},{-7,-4},{-8,-4},{-8,-3},{-8,-2},
    {-8,-1},{-8, 0},{-8, 1},{-8, 2},{-8, 3},{-8, 4},{-7, 4},{ 9, 0},
    { 9, 0},{-6, 4},{-5, 4},{-5, 5},{-5, 6},{-4, 6},{-3, 6},{ 9, 0},
    {-2, 6},{-1, 6},{ 3, 5},{ 4, 5},{ 4, 4},{ 4, 3},{ 5, 3},{ 9, 0},
    { 9, 0},{ 9, 0},{ 6, 3},{ 9, 0},{ 7, 3},{ 7, 2},{ 7,-1},{ 7,-2},
    { 7,-3},{ 6,-3},{ 5,-3},{ 4,-4},{ 4,-5},{ 3,-5},{ 9, 0},{ 9, 0},
    { 9, 0},{ 2,-5},{-2,-5},{-3,-5},{-4,-5},{-4,-4},{ 9, 0},{-5,-3},
    {-6,-3},{-7,-3},{-7,-2},{-7,-1},{-7, 2},{ 9, 0},{ 9, 0},{ 9, 0},
    { 9, 0},{-7, 3},{-6, 3},{-5, 3},{-4, 3},{-4, 4},{-4, 5},{-3, 5},
    { 0, 5},{ 3, 4},{ 5, 2},{ 6, 2},{ 6, 1},{ 6, 0},{ 6,-1},{ 9, 0},
    { 9, 0},{ 6,-2},{ 5,-2},{ 4,-2},{ 3,-2},{ 3,-3},{ 3,-4},{ 2,-4},
    {-2,-4},{-3,-4},{-3,-3},{ 9, 0},{-3,-2},{-4,-2},{-5,-2},{ 9, 0},
    { 9, 0},{ 9, 0},{-6,-2},{-6,-1},{-6, 0},{-6, 1},{-6, 2},{-5, 2},
    {-3, 4},{-1, 4},{ 0, 4},{ 1, 4},{ 5, 1},{ 5, 0},{ 5,-1},{ 9, 0},
    { 9, 0},{ 4,-1},{ 3,-1},{ 2,-2},{ 2,-3},{ 1,-3},{-1,-3},{-2,-3},
    {-2,-2},{-3,-1},{-4,-1},{-5,-1},{-5, 0},{-5, 1},{ 9, 0},{ 9, 0},
    { 9, 0},{ 9, 0},{ 4, 0},{-4, 0},{ 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},{ 0, 0},{ 0, 0},{ 9, 0},
};
struct simplePair STG04_CHUNK_MOODS[] = {
    { 5, 9},{ 5, 8},{ 7, 7},{ 4, 7},{ 3, 7},{ 9, 0},
    { 2, 7},{-2, 7},{-3, 7},{-4, 7},{-5, 7},{-5, 8},
    {-5, 9},{-4, 9},{-3, 9},{-2, 9},{-1, 9},{ 9, 0},
    { 1, 9},{ 2, 9},{ 3, 9},{ 4, 9},{ 4, 8},{ 3, 8},
    { 2, 8},{ 1, 8},{ 0, 8},{-1, 8},{-2, 8},{ 9, 0},
};
struct simplePair STG05_CHUNK_MOODS[] = {
    { 3,-7},{ 3,-8},{ 4,-8},{ 5,-8},{ 5,-9},
    { 9, 0},{ 4,-9},{ 3,-9},{ 2,-9},{ 1,-9},
    {-1,-8},{-1,-9},{-2,-9},{-3,-9},{-4,-9},
    { 9, 0},{-5,-9},{-5,-8},{-4,-8},{-3,-8},
    { 9, 0},{-3,-7},{-2,-7},{-1,-7},{ 0,-7},
    { 1,-7},{ 2,-7},{ 2,-8},{ 1,-8},{ 0,-8},
};
struct simplePair STG06_CHUNK_MOODS[] = {
    { 0,-4},
    { 0,-2},
    { 0,-1},
    { 0, 1},
    { 0, 2},
    { 1, 2},
};
struct simplePair STG07_CHUNK_MOODS[] = {
    { 2, 2},{ 2, 1},{ 1, 0},{-1, 0},{-2, 1},
};
struct simplePair STG08_CHUNK_MOODS[] = {
    { 7, 0},
    {-7, 0},
    {-7, 1},
};
struct simplePair STG09_CHUNK_MOODS[] = {
    { 0,-6},
    {-2,-8},
};
struct simplePair STG10_CHUNK_MOODS[] = {
    { 5,-7},{ 4,-7},{-4,-7},
};
struct simplePair STG11_CHUNK_MOODS[] = {
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},
    { 9, 0},{-4, 8},{-3, 8},{ 9, 0},
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},
};
struct simplePair STG12_CHUNK_MOODS[] = {
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},
    { 9, 0},{ 6, 5},{ 6,-5},{ 9, 0},
    {-6,-5},{-6, 5},{ 0, 6},{ 9, 0},
    { 9, 0},{ 4,-3},{-4,-3},{ 9, 0},
    { 9, 0},{ 9, 0},{ 9, 0},{ 9, 0},
};
struct simplePair STG13_CHUNK_MOODS[] = {
    {-1, 3},{ 9, 0},
    {-1, 2},{-2, 2},
};

MoodGraphPoint* STAGE_CHUNK_MOODS[] = {
    (MoodGraphPoint*) STG00_CHUNK_MOODS,
    (MoodGraphPoint*) STG01_CHUNK_MOODS,
    (MoodGraphPoint*) STG02_CHUNK_MOODS,
    (MoodGraphPoint*) STG03_CHUNK_MOODS,
    (MoodGraphPoint*) STG04_CHUNK_MOODS,
    (MoodGraphPoint*) STG05_CHUNK_MOODS,
    (MoodGraphPoint*) STG06_CHUNK_MOODS,
    (MoodGraphPoint*) STG07_CHUNK_MOODS,
    (MoodGraphPoint*) STG08_CHUNK_MOODS,
    (MoodGraphPoint*) STG09_CHUNK_MOODS,
    (MoodGraphPoint*) STG10_CHUNK_MOODS,
    (MoodGraphPoint*) STG11_CHUNK_MOODS,
    (MoodGraphPoint*) STG12_CHUNK_MOODS,
    (MoodGraphPoint*) STG13_CHUNK_MOODS
};

s32 func_800494B4(void) {
    return LENGTH_DIMENSIONS_TABLE;
}

StageGridDimensions *GetStageGridDimensionsTable(s32 *unknown) {
    if (unknown != NULL) {
        *unknown = LENGTH_DIMENSIONS_TABLE;
    }
    return (StageGridDimensions*) &STAGE_GRID_DIMENSIONS;
}

StageGridDimensions *GetStageGridDimensions(s32 index) {
    StageGridDimensions *table;

    table = GetStageGridDimensionsTable(NULL);

    return table + index;
}

//https://decomp.me/scratch/Avz4j
INCLUDE_ASM("asm/lsdde/nonmatchings/StageGrid", GetStageChunkFromMood);

//https://decomp.me/scratch/O2cDs
INCLUDE_ASM("asm/lsdde/nonmatchings/StageGrid", GetMoodFromStageChunk);
