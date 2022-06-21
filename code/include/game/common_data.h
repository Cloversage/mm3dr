#ifndef _GAME_COMMON_DATA_H
#define _GAME_COMMON_DATA_H

#include <array>

#include "common/types.h"
#include "common/utils.h"
#include "game/items.h"
#include "game/player.h"
#include "z3d/z3DVec.h"

namespace game {

enum class SwordType : u16 {
  NoSword = 0,
  KokiriSword = 1,
  RazorSword = 2,
  GildedSword = 3,
};

enum class ShieldType : u16 {
  NoShield = 0,
  HeroShield = 1,
  MirrorShield = 2,
};

enum class BombBag : u32 {
  NoBag = 0,
  BombBag20 = 1,
  BombBag30 = 2,
  BombBag40 = 3,
};

enum class Quiver : u32 {
  NoQuiver = 0,
  Quiver30 = 1,
  Quiver40 = 2,
  Quiver50 = 3,
};

struct PlayerData {
  char field_11C[4];
  u8 gap_120[2];
  u16 save_count_maybe;
  char16_t playerName[8];
  u16 anonymous_h;
  
  u16 health_max;
  u16 health_current;
  u8 magic_size_type;
  u8 magic;
  u16 rupee_count;
  u16 razor_sword_hp;
  u16 tatl_timer_maybe;
  u8 magic_acquired;
  s8 magic_num_upgrades;
  u8 double_defense;
  char anonymous_18;
  char anonymous_19;
  char anonymous_20;
  union OwlStatues {
    u16 raw;

    BitField<0, 1, u16> great_bay;
    BitField<1, 1, u16> zora_cape;
    BitField<2, 1, u16> snowhead;
    BitField<3, 1, u16> mountain_village;
    BitField<4, 1, u16> clock_town;
    BitField<5, 1, u16> milk_road;
    BitField<6, 1, u16> woodfall;
    BitField<7, 1, u16> southern_swamp;
    BitField<8, 1, u16> ikana_canyon;
    BitField<9, 1, u16> stone_tower;
    BitField<10, 6, u16> pad_1;
  };
  OwlStatues owl_statue_flags;
  char field_2E;
  char field_2F;
  char field_30;
  char field_31;
};
static_assert(sizeof(PlayerData) == 0x32);
static_assert(offsetof(PlayerData, magic) == 0x1F);

union FormEquipmentData {
  std::array<ItemId, 5> item_btns;
  struct {
    ItemId item_btn_b;
    ItemId item_btn_y;
    ItemId item_btn_x;
    ItemId item_btn_i;
    ItemId item_btn_ii;
  };
};

struct EquipmentData {
  FormEquipmentData data[4];
  char field_14;
  ItemId item_on_y_readonly;
  ItemId item_on_x_readonly;
  ItemId item_on_i_readonly;
  ItemId item_on_ii_readonly;
  char field_19;
  char field_1A;
  char field_1B;
  char field_1C;
  char field_1D;
  char field_1E;
  char field_1F;
  char field_20;
  char field_21;
  char field_22;
  char field_23;
  char field_24;
  char field_25;
  char field_26;
  char field_27;
  union SwordShield {
    u16 raw;

    BitField<0, 4, SwordType> sword;
    BitField<4, 8, ShieldType> shield;
  };
  SwordShield sword_shield;
};

struct InventoryData {
  // Slot 5 is first quest item.
  std::array<ItemId, 24> items;
  std::array<ItemId, 24> masks;
  std::array<ItemId, 7> bottles;
  std::array<u8, 17> item_counts;
  u8 field_48[24];
  u8 field_60[24];
  union InventoryCountRegister {
    u32 raw;

    BitField<0, 3, Quiver> quiver_upgrade;
    BitField<3, 3, BombBag> bomb_bag_upgrade;
    BitField<6, 6, u32> pad_1;
    BitField<12, 2, u32> wallet_upgrade;
    BitField<14, 3, u32> pad_2;
    BitField<17, 3, u32> stick_upgrades;
    BitField<20, 3, u32> nut_upgrade;
    BitField<23, 9, u32> pad_3;
  };
  InventoryCountRegister inventory_count_register;
  union CollectRegister {
    u32 raw;
    
    BitField<0, 1, u32> odolwas_remains;
    BitField<1, 1, u32> gohts_remains;
    BitField<2, 1, u32> gyorgs_remains;
    BitField<3, 1, u32> twinmolds_remains;
    BitField<4, 2, u32> pad_1;
    BitField<6, 1, u32> sonata_of_awakening;
    BitField<7, 1, u32> goron_lullaby;
    BitField<8, 1, u32> new_wave_bossa_nova;
    BitField<9, 1, u32> elegy_of_emptiness;
    BitField<10, 1, u32> oath_to_order;
    BitField<11, 1, u32> sarias_song;
    BitField<12, 1, u32> song_of_time;
    BitField<13, 1, u32> song_of_healing;
    BitField<14, 1, u32> eponas_song;
    BitField<15, 1, u32> song_of_soaring;
    BitField<16, 1, u32> song_of_storms;
    BitField<17, 1, u32> suns_song;
    BitField<18, 1, u32> bombers_notebook;
    BitField<19, 5, u32> pad_2;
    BitField<24, 1, u32> lullaby_intro;
    BitField<25, 3, u32> pad_3;
    BitField<28, 4, u32> heart_container_pieces;
  };
  CollectRegister collect_register;
  union DungeonItems {
    u8 raw;

    BitField<0, 1, u8> boss_key;
    BitField<1, 1, u8> compass;
    BitField<2, 1, u8> map;
    BitField<3, 5, u8> pad_1;
  };
  DungeonItems woodfall_dungeon_items;
  DungeonItems snowhead_dungeon_items;
  DungeonItems great_bay_dungeon_items;
  DungeonItems stone_tower_dungeon_items;
  u8 gap200[6];
  u8 woodfall_temple_keys;
  u8 snowhead_temple_keys;
  u8 great_bay_temple_keys;
  u8 stone_tower_temple_keys;
  u8 gap20A[5];
  u8 anonymous_39;
  u8 woodfall_fairies;
  u8 snowhead_fairies;
  u8 great_bay_fairies;
  u8 stone_tower_fairies;
  u8 gap98[60]; //        L I N K            L I N K            L I N K           
};
static_assert(sizeof(InventoryData) == 0xD4);
static_assert(offsetof(InventoryData, inventory_count_register) == 0x78);

struct SaveData {
  //Todo: rename gaps to match savefile location
  MaskId mask;
  u8 has_completed_intro;
  char unused;
  // Possible cutscene ID?
  char anonymous_0;
  bool is_night;
  /// Number of extra time units to add per game tick (0 normally; -1 with ISoT)
  /// In Majora's Mask, ISoT used to set this to -2.
  int extra_time_speed;
  /// In-game day
  int day;
  int total_day;
  int cutscene_stuff;
  /// In-game time.
  /// 0x0000 is midnight, 0x4000 is 6am, 0x8000 is noon, 0xc000 is 6pm.
  u16 time;
  u16 anonymous_3;
  u16 rupee_accumulator;
  act::Player::Form player_form;
  char anonymous_5;
  bool has_tatl;
  char anonymous_7;
  char anonymous_8;
  char anonymous_9;
  char anonymous_10;
  char anonymous_11;
  char anonymous_12;
  char anonymous_13;
  u8 boss_started_flags;
  char anonymous_15;
  char anonymous_16;
  char gap33[205];
  char anonymous_a[24]; // Possible permanent scene flags? Could be put in the gap to match 0x1C size?
  char anonymous_b;
  u8 gap_115[7];
  PlayerData player;
  EquipmentData equipment;
  InventoryData inventory;
  char field_24C;
  u8 gap249[938];
  u8 IkanaCastleCameraPan_0x08;
  u8 gap5FC[295]; //address name has been corrected to match savefile adddress
  int anonymous_44;
  u8 gap728[204];
  u8 SkullKidBackstoryCutscene_0x10;
  u8 gap7F5[178]; //also been corrected
  char anonymous_45;
  u8 gap8A9[269];
  u8 PiratesFortressExteriorCameraPan_0x04;
  u8 gap9B6[752]; //corrected
  int anonymous_46;
  u8 gapCAC[520];
  u8 MeetingTheHappyMaskMan_0x01;
  u8 gapEB5[762]; //corrected
  int anonymous_47;
  int anonymous_48;
  int anonymous_49;
  int anonymous_50;
  int anonymous_51;
  u8 gap11C4[12];
  int anonymous_52;
  int anonymous_53;
  int anonymous_54;
  int anonymous_55;
  int anonymous_56;
  int anonymous_57;
  int anonymous_58;
  u8 gap11EC[36];
  union SkulltulaRegister {
    u32 raw;

    BitField<0, 16, int> swamp_count;
    BitField<16, 16, int> ocean_count;
  };
  SkulltulaRegister skulltulas_collected;
  int anonymous_60;
  u8 gap1218[4];
  int anonymous_61; // XXX: Possible scene flags.
  int anonymous_62; // XXX: Possible scene flags.
  int anonymous_63;
  u8 gap1228[8];
  int anonymous_64;
  u8 gap1234[8];
  int anonymous_65;
  int anonymous_66;
  int anonymous_67;
  int anonymous_68;
  u8 gap1244[4];
  //Cutscene flag bundle
  /*
  u8 event_reg_maybe;
  char anonymous_69;
  char anonymous_70;
  u8 gap1253;
  */
  union CutSceneFlagsU32 {
    u32 raw;
    
    BitField<0, 1, u32> unknown0;
    BitField<1, 1, u32> TerminaField;
    BitField<2, 1, u32> Graveyard;
    BitField<3, 1, u32> RomaniRanch;
    BitField<4, 2, u32> GormanTrack;
    BitField<5, 1, u32> MountainVillage;
    BitField<6, 1, u32> GoronCity;
    BitField<7, 1, u32> Snowhead;

    BitField<8, 1, u32> SouthernSwamp;
    BitField<9, 1, u32> Woodfall;
    BitField<10, 1, u32> DekuPalace;
    BitField<11, 1, u32> GreatBayCoast;
    BitField<12, 1, u32> PiratesFortress;
    BitField<13, 1, u32> ZoraDomain;
    BitField<14, 1, u32> WaterfallRapids;
    BitField<15, 1, u32> IkanaCanyon;

    BitField<16, 1, u32> unknown16;
    BitField<17, 1, u32> StoneTower;
    BitField<18, 1, u32> StoneTowerInverted;
    BitField<19, 1, u32> EastClockTown;
    BitField<20, 1, u32> WestClockTown;
    BitField<21, 1, u32> NorthClockTown;
    BitField<22, 1, u32> WoodfallTemple;
    BitField<23, 1, u32> SnowheadTemple;

    BitField<24, 1, u32> unknown24;
    BitField<25, 1, u32> StoneTowerTemple;
    BitField<26, 1, u32> StoneTowerTempleInverted;
    BitField<27, 1, u32> unknown27;
    BitField<28, 1, u32> unknown28;
    BitField<29, 1, u32> unknown29;
    BitField<30, 1, u32> unknown30;
    BitField<31, 1, u32> unknown31;
  };
  CutSceneFlagsU32 CutSceneFlagBundle1;
  u8 gap1254[3];
  char anonymous_71;
  char anonymous_72;
  char anonymous_73;
  char anonymous_74;
  char anonymous_75;
  u8 ct_guard_allows_through_if_0x30;
  char anonymous_77;
  u8 flag_8_for_no_magic_use;
  char anonymous_78;
  char anonymous_79;
  u8 ct_deku_removed_if_c0;
  char anonymous_81;
  char anonymous_82;
  char anonymous_83;
  char anonymous_84;
  char anonymous_85;
  u8 has_great_spin_0x02;
  char anonymous_87;
  char anonymous_88;
  char anonymous_89;
  char anonymous_90;
  char anonymous_91;
  char anonymous_92;
  char anonymous_93;
  char anonymous_94;
  char anonymous_95;
  char anonymous_96;
  char anonymous_97;
  char anonymous_98;
  char anonymous_99;
  char anonymous_100_0x10_if_rock_sirloin_spawned;
  char anonymous_101;
  char anonymous_102;
  char anonymous_103;
  char anonymous_104;
  u8 gap127A[8];
  char anonymous_105;
  char anonymous_106;
  char anonymous_107;
  char anonymous_108;
  char anonymous_109;
  char anonymous_110;
  char anonymous_111;
  char anonymous_112;
  char anonymous_113;
  char skip_tatl_talking_0x04;
  char anonymous_115;
  char swamp_deku_removed_if_0x10; // Don Gero Flag Maybe
  char anonymous_117;
  char anonymous_118;
  char anonymous_119;
  char anonymous_120;
  u8 gap1292[7];
  u8 ct_deku_in_flower_0x04_if_present;
  char anonymous_122;
  u8 anju_0x10_if_obtained_small_key;
  char anonymous_124;
  char anonymous_125;
  char anonymous_126;
  char anonymous_127;
  char anonymous_128;  //Possibly more Cutscene flags
  char anonymous_129;
  char anonymous_130;
  char anonymous_131;
  char anonymous_132;
  char anonymous_133;
  char anonymous_134;
  char anonymous_135;
  char anonymous_136;
  char anonymous_137;
  char anonymous_138;
  char anonymous_139;
  char anonymous_140;
  char anonymous_141;
  u8 gap12AE[6];
  char anonymous_142;
  char anonymous_143;
  char anonymous_144;
  u8 gap12B7[3];
  char anonymous_145;
  char anonymous_146;
  u8 gap12BC[13];
  char anonymous_147;
  char anonymous_148[6];
  char anonymous_149;
  char anonymous_150;
  char anonymous_151;
  union CutSceneFlagsU8 {
    u8 raw;

    BitField<0, 1, u8> OwlStatueCutScene;
    BitField<1, 1, u8> unknown1;
    BitField<2, 1, u8> unknown2;
    BitField<3, 1, u8> unknown3;
    BitField<4, 2, u8> DekuPalaceThroneRoomCutScene;
    BitField<5, 1, u8> unknown5;
    BitField<6, 1, u8> unknown6;
    BitField<7, 1, u8> unknown7;
  };
  CutSceneFlagsU8 CutSceneFlagBundle2; //char anonymous_152_saved_once_0x10_sot_once_0x40;
  char anonymous_153;
  char anonymous_154;
  char anonymous_155;
  char anonymous_156;
  char anonymous_157;
  u8 RoadtoWoodfallCameraPan_0x08;
  u8 ct_deku_flown_in_0x80_if_visited_once; // Possible event flags? Set to 80.
  char anonymous_160;
  u8 gap12DC[20];
  //Possibly flags for locations visted or game progression counter
  //Does not affect cutscenes
  union UnknownFlags_U32 {
    u32 raw;
    
    BitField<0, 1, u32> ClockTown;
    BitField<1, 1, u32> TerminaField;
    BitField<2, 1, u32> unknown2;
    BitField<3, 1, u32> unknown3;
    BitField<4, 2, u32> unknown4;
    BitField<5, 1, u32> unknown5;
    BitField<6, 1, u32> unknown6;
    BitField<7, 1, u32> unknown7;

    BitField<8, 1, u32> unknown8;
    BitField<9, 1, u32> unknown9;
    BitField<10, 1, u32> unknown10;
    BitField<11, 1, u32> unknown11;
    BitField<12, 1, u32> unknown12;
    BitField<13, 1, u32> unknown13;
    BitField<14, 1, u32> unknown14;
    BitField<15, 1, u32> unknown15;

    BitField<16, 1, u32> unknown16;
    BitField<17, 1, u32> unknown17;
    BitField<18, 1, u32> unknown18;
    BitField<19, 1, u32> unknown19;
    BitField<20, 1, u32> unknown20;
    BitField<21, 1, u32> unknown21;
    BitField<22, 1, u32> unknown22;
    BitField<23, 1, u32> unknown23;

    BitField<24, 1, u32> unknown24;
    BitField<25, 1, u32> unknown25;
    BitField<26, 1, u32> unknown26;
    BitField<27, 1, u32> unknown27;
    BitField<28, 1, u32> unknown28;
    BitField<29, 1, u32> unknown29;
    BitField<30, 1, u32> unknown30;
    BitField<31, 1, u32> unknown31;
  };
  UnknownFlags_U32 UnknownFlagBundle; //int anonymous_161;
  int anonymous_162;
  u8 gap12F8;
  char anonymous_163;
  u8 gap12FA[128];
  char anonymous_164;
  char anonymous_165;
  char anonymous_166;
  char anonymous_167;
  char anonymous_168;
  char anonymous_169;
  char anonymous_170;
  char anonymous_171;
  char anonymous_172;
  char anonymous_173;
  char anonymous_174;
  char anonymous_175;
  char anonymous_176;
  char anonymous_177;
  char anonymous_178;
  char anonymous_179;
  u8 gap138A[5];
  char anonymous_180;
  char anonymous_181;
  char anonymous_182;
  char anonymous_183;
  char anonymous_184;
  char anonymous_185;
  char anonymous_186[3];
  u16 anonymous_187;
  u16 anonymous_188;
  u16 anonymous_189;
  u16 anonymous_190;
  u16 anonymous_191;
  u8 gap13A2[326];
  char num_ftickets_rank10;
  char anonymous_193;
  char anonymous_194;
  char used_instruments;
  char anonymous_196;
  char anonymous_197;
  u16 anonymous_198;
  u8 gap_14E8[136];
  u32 field_1570;
  u8 gap_1574[1020];
  u32 field_1970;
  u8 gap_1974[176];
  char anonymous_199;
  char anonymous_200;
  u16 anonymous_201;
  u8 gap1A30[20]; // Items?
  char anonymous_202;
  char anonymous_203;
  char anonymous_204;
  char anonymous_205;
  char anonymous_206;
  char anonymous_207;
  char anonymous_208;
  char anonymous_209;
  char anonymous_210;
  char anonymous_211;
  char anonymous_212;
  char anonymous_213;
  char anonymous_214;
  char anonymous_215;
  char anonymous_216;
  char anonymous_217;
  char anonymous_218;
  char anonymous_219;
  char anonymous_220;
  char anonymous_221;
  char anonymous_222;
  char anonymous_223;
  char anonymous_224;
  char anonymous_225;
  u8 gap1A5C[8];
  u16 anonymous_226;
  char anonymous_227[2];
  u8 gap_1A60[16];
  u32 field_1A70;
  u8 gap_1A74[12];
  u16 hash;
  u16 anonymous_229;
  int field_1A84;
};
static_assert(sizeof(SaveData) == 0x1A88);

struct CommonDataSub1 {
  int entrance;
  u16 save_entrance;
  u8 owl_save;
  u8 field_7;
  int field_8;
  u8 invert_stick;
  u8 field_D;
  u16 field_F;
  int field_10;
  //int field_14;
  u8 option_3;
  u8 option_6;
  u8 option_4;
  u8 remains;
  int total_owl_saves;
  int field_1C;
}; static_assert(sizeof(CommonDataSub1) == 0x20);

struct CommonDataSub3 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
};

struct CommonDataSub4 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
};

struct CommonDataSub5 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
};

struct CommonDataSub6 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
};

struct CommonDataSub7 {
  u64 field_0;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
};

struct CommonDataSub8 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
};

struct CommonDataSub9 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
};

struct CommonDataSub10 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
};

struct CommonDataSub11 {
  u64 field_0;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
};

struct CommonDataSub12 {
  u32 field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
};

struct RespawnData {
  z3dVec3f pos; 
  s16 yaw;
  s16 player_params;
  s16 entrance_index;
  u8 room_index;
  s8 data;
  u32 temp_swch_flags_maybe;
  u8 field_1;
  u8 btn_y_can_use_item;
  u8 btn_x_can_use_item;
  u8 btn_i_can_use_item;
  //u32 stored_mask_id_maybe;
  u32 temp_collect_flags_maybe;
};
static_assert(sizeof(RespawnData) == 0x20);

enum class UsableButton : u8 {
  B = 0,
  Y = 1,
  X = 2,
  I = 3,
  II = 4,
  Unknown5 = 5,
  Ocarina = 6,
  PictographBox = 7,
  Unknown8 = 8,
};

enum class ButtonIsUsable : u8 {
  Yes = 0,
  No = 0xff,
  // Other values are possible and can be seen when riding Epona.
};

/// Common gameplay data, also known as the Save Context (unofficially).
struct CommonData {
  FormEquipmentData& GetFormEquipment() {
    const auto idx = save.player_form == act::Player::Form::Human ? 0 : u8(save.player_form);
    return save.equipment.data[idx];
  }
  const FormEquipmentData& GetFormEquipment() const {
    const auto idx = save.player_form == act::Player::Form::Human ? 0 : u8(save.player_form);
    return save.equipment.data[idx];
  }

  int start;
  int scene;
  SaveData save;
  SaveData save_backup;
  CommonDataSub1 sub1;
  u64 unknown_1;
  u64 unknown_2;
  u64 unknown_3;
  CommonDataSub3 sub3;
  CommonDataSub4 sub4;
  CommonDataSub5 sub5;
  CommonDataSub6 sub6;
  CommonDataSub7 sub7;
  CommonDataSub8 sub8;
  CommonDataSub9 sub9;
  CommonDataSub10 sub10;
  CommonDataSub11 sub11;
  CommonDataSub12 sub12;
  u8 gap_3668[14];
  __attribute__((packed)) __attribute__((aligned(1))) int field_3676;
  __attribute__((packed)) __attribute__((aligned(1))) int field_367A;
  __attribute__((packed)) __attribute__((aligned(1))) int field_367E;
  u16 field_3682;
  u16 field_3684;
  u16 magic_accumulator;
  u16 field_3688;
  s16 magic_max;
  u16 magic_max_2;
  s16 magic_cost;
  u16 field_3690;
  u16 field_3692;
  u16 health_accumulator;
  u16 field_3696;
  u16 field_3698;
  u16 field_369A;
  u16 field_369C;
  u16 field_369E;
  u16 time_copy_2;
  // Used for scheduling NPCs?
  u16 time_copy;
  u8 field_36A4[32];
  u32 field_36C4;
  u8 gap_36C8[4];
  // MPO data.
  u8 pictograph_data[65356];

  // Data below isn't read from or written to save files.

  u16 save_idx;
  u8 gap_1361A[2];
  int setup;
  int setup2;
  int field_13624;
  RespawnData sub13s[8];
  u32 field_13728;
  int field_1372C;
  char field_13730;
  char field_13731;
  u16 field_13732;
  u16 field_13734;
  u16 field_13736;
  int field_13738;
  // 0-19
  int sound_env_index;

  /// see also UsableButton and ButtonIsUsable
  ButtonIsUsable usable_btns[9];
  u8 field_13749;
  u16 alpha_type;
  u16 alpha_type_2;
  u16 alpha_type_flag;
  u16 field_13750;
  u16 field_13752;
  u16 field_13754;
  u16 field_13756;

  int field_13758;
  char field_1375C;
  char field_1375D;
  char field_1375E;
  char field_1375F;
  u16 time_copy_3;
  char field_13762;
  char field_13763;
  u8 gap_13764[2204];
  u32 field_14000;
  u8 gap_14004[192];
  int field_140C4;
  int field_140C8;
  int field_140CC;
  int field_140D0;
  int field_140D4;
  u32 field_140D8;
  int field_140DC;
  int field_140E0;
  int field_140E4;
  int field_140E8;
  int field_140EC;
  char field_140F0;
  u16 field_140F2;
  int field_140F4;
};
static_assert(sizeof(CommonData) == 0x140F8);

CommonData& GetCommonData();

}  // namespace game

#endif