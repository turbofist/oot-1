/*
 * File: z_strange_note.c
 * Overlay: ovl_Strange_Note
 * Description: Custom Actor - Strange note describing some mysterious circumstances...
 */

#include "z_strange_note.h"

#define FLAGS (0)

void Strange_Note_Init(Actor* thisx, PlayState* play);
void Strange_Note_Destroy(Actor* thisx, PlayState* play);
void Strange_Note_Update(Actor* thisx, PlayState* play);
void Strange_Note_Draw(Actor* thisx, PlayState* play);
void Strange_Note_Appear(Actor* thisx, PlayState* play);

void Strange_Note_DoNothing(Strange_Note* this, PlayState* play);

ActorInit Strange_Note_InitVars = {
    ACTOR_STRANGE_NOTE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_STRANGE_NOTE,
    sizeof(Strange_Note),
    (ActorFunc)Strange_Note_Init,
    (ActorFunc)Strange_Note_Destroy,
    (ActorFunc)Strange_Note_Update,
    (ActorFunc)Strange_Note_Draw,
};

void Strange_Note_Init(Actor* thisx, PlayState* play) {
    Strange_Note* this = (Strange_Note*)thisx;
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    this->actionFunc = Strange_Note_DoNothing;
    Actor_SetScale(&this->actor, 0.01f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gStrangeNoteSkel, &gStrangeNoteIdleAnim, this->jointTable, this->morphTable, STRANGE_NOTE_LIMB_MAX);
    Animation_PlayOnce(&this->skelAnime, &gStrangeNoteIdleAnim);
    this->animation = NULL;
}

void Strange_Note_Destroy(Actor* thisx, PlayState* play) {
    Strange_Note* this = (Strange_Note*)thisx;
}

void Strange_Note_Update(Actor* thisx, PlayState* play) {
    Strange_Note* this = (Strange_Note*)thisx;
    if(this->actor.xzDistToPlayer < 20.0f){
        this->actionFunc = Strange_Note_Appear;
    }
    this->actionFunc(this, play);
}

void Strange_Note_Draw(Actor* thisx, PlayState* play) {
    Strange_Note* this = (Strange_Note*)thisx;
    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount, NULL,
                          NULL, NULL);
}

void Strange_Note_Appear(Actor* thisx, PlayState* play) {
    Strange_Note* this = (Strange_Note*)thisx;
    Animation_PlayOnce(&this->skelAnime, &gStrangeNoteSkelUnwrapAnim);
    Actor_SetScale(&this->actor, 0.01f);
}

void Strange_Note_DoNothing(Strange_Note* this, PlayState* play) {
    if(1){}
}
