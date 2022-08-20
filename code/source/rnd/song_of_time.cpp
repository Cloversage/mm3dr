extern "C" {
#include <3ds/types.h>
}

#include "rnd/savefile.h"

namespace rnd {
    extern "C" void SongOfTime() {
        // This function also runs once upon loading a savefile for the first time
        // Check to see if player is song of time warping
        game::SaveData& saveData = game::GetCommonData().save;
        u16 isNewFile = saveData.player.song_of_time_counter;
        if(isNewFile < 2) return;

        // Undo unwanted changes by song of time warp
        SaveFile_SetUnconditionalTempEventFlags();
    }
}