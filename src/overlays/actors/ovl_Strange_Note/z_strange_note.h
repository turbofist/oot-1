#ifndef Z_STRANGE_NOTE_H
#define Z_STRANGE_NOTE_H

#include "ultra64.h"
#include "global.h"
#include "assets/objects/object_strange_note/object_strange_note.h"

struct Strange_Note;

typedef void (*Strange_NoteActionFunc)(struct Strange_Note*, PlayState*);

typedef enum {
    /* 0 */ STRANGE_NOTE_LIMB_0,
    /* 1 */ STRANGE_NOTE_LIMB_1,
    /* 2 */ STRANGE_NOTE_LIMB_2,
    /* 3 */ STRANGE_NOTE_LIMB_MAX
} StrangeNoteLimb;

typedef struct Strange_Note {
    Actor actor;
    Strange_NoteActionFunc actionFunc;
    SkelAnime skelAnime;
    AnimationHeader* animation;
    Vec3s jointTable[STRANGE_NOTE_LIMB_MAX];
    Vec3s morphTable[STRANGE_NOTE_LIMB_MAX];
    u16 timer;
} Strange_Note;

#endif
