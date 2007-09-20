// (c) Copyright 2006-2007 notaz, All rights reserved.
// Free for non-commercial use.

// For commercial use, separate licencing terms must be obtained.



// engine states
enum TPicoGameState {
	PGS_Paused = 1,
	PGS_Running,
	PGS_Quit,
	PGS_KeyConfig,
	PGS_ReloadRom,
	PGS_Menu,
	PGS_RestartRun,
};

typedef struct {
	char lastRomFile[512];
	int EmuOpt;		// LSb->MSb: use_sram, show_fps, enable_sound, gzip_saves,
					// <reserved>, no_save_cfg_on_exit, <unused>, 16_bit_mode
					// <reserved>, confirm_save, show_cd_leds, confirm_load
					// <reserved>, <reserved>
	int PicoOpt;		// used for config saving only, see Pico.h
	int PsndRate;		// ditto
	int PicoRegion;		// ditto
	int Frameskip;
	int CPUclock;		// unused, placeholder for config compatibility
	int KeyBinds[32];
	int volume;
	int gamma;		// unused
	int JoyBinds[4][32];	// unused
	int PicoAutoRgnOrder;
	int PicoCDBuffers;
	int scaling;		// unused
} currentConfig_t;

extern char romFileName[];
extern int engineState;
extern currentConfig_t currentConfig;


int  emu_ReloadRom(void);
void emu_Init(void);
void emu_Deinit(void);
int  emu_SaveLoadGame(int load, int sram);
void emu_Loop(void);
void emu_ResetGame(void);
int  emu_ReadConfig(int game, int no_defaults);
int  emu_WriteConfig(int game);
char *emu_GetSaveFName(int load, int is_sram, int slot);
int  emu_check_save_file(int slot);
void emu_set_save_cbs(int gz);
void emu_forced_frame(void);
int  emu_cd_check(int *pregion);
int  find_bios(int region, char **bios_file);
void scaling_update(void);
