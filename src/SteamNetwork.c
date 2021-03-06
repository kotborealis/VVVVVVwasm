#include "Network.h"

#include <stdio.h>
#include <stdint.h>
#include <SDL.h>

/* Steamworks interface versions */

#define VVVVVV_STEAMCLIENT "SteamClient017"
#define VVVVVV_STEAMUSERSTATS "STEAMUSERSTATS_INTERFACE_VERSION011"

/* Shared object file name */

//#if defined(_WIN32)
//#define NETWORK_LIBRARY "steam_api.dll"
//#elif defined(__APPLE__)
//#define NETWORK_LIBRARY "libsteam_api.dylib"
//#elif defined(__linux__)
//#define NETWORK_LIBRARY "libsteam_api.so"
//#else
//#error NETWORK_LIBRARY: Unrecognized platform!
//#endif

#define NETWORK_LIBRARY ""

/* Function Pointer Types */

typedef uint8_t (*SteamAPI_InitFunc)();
typedef void (*SteamAPI_ShutdownFunc)();
typedef void (*SteamAPI_RunCallbacksFunc)();
typedef intptr_t (*SteamInternal_CreateInterfaceFunc)(const char*);
typedef int32_t (*SteamAPI_GetHSteamUserFunc)();
typedef int32_t (*SteamAPI_GetHSteamPipeFunc)();
typedef intptr_t (*SteamAPI_ISteamClient_GetISteamUserStatsFunc)(
	intptr_t,
	int32_t,
	int32_t,
	const char*
);
typedef uint8_t (*SteamAPI_ISteamUserStats_RequestCurrentStatsFunc)(intptr_t);
typedef uint8_t (*SteamAPI_ISteamUserStats_StoreStatsFunc)(intptr_t);
typedef uint8_t (*SteamAPI_ISteamUserStats_GetStatFunc)(
	intptr_t,
	const char*,
	int32_t*
);
typedef uint8_t (*SteamAPI_ISteamUserStats_SetStatFunc)(
	intptr_t,
	const char*,
	int32_t
);
typedef uint8_t (*SteamAPI_ISteamUserStats_SetAchievementFunc)(
	intptr_t,
	const char*
);

/* DLL, Entry Points */

static void *libHandle = NULL;
static intptr_t steamUserStats = (intptr_t) NULL;

#define DEFINE_FUNC(name) static name##Func name = NULL;
DEFINE_FUNC(SteamAPI_Init)
DEFINE_FUNC(SteamAPI_Shutdown)
DEFINE_FUNC(SteamAPI_RunCallbacks)
DEFINE_FUNC(SteamInternal_CreateInterface)
DEFINE_FUNC(SteamAPI_GetHSteamUser)
DEFINE_FUNC(SteamAPI_GetHSteamPipe)
DEFINE_FUNC(SteamAPI_ISteamClient_GetISteamUserStats)
DEFINE_FUNC(SteamAPI_ISteamUserStats_RequestCurrentStats)
DEFINE_FUNC(SteamAPI_ISteamUserStats_StoreStats)
DEFINE_FUNC(SteamAPI_ISteamUserStats_GetStat)
DEFINE_FUNC(SteamAPI_ISteamUserStats_SetStat)
DEFINE_FUNC(SteamAPI_ISteamUserStats_SetAchievement)
#undef DEFINE_FUNC

/* Clean up after ourselves... */

static void ClearPointers()
{
	SDL_UnloadObject(libHandle);
	libHandle = NULL;
	steamUserStats = (intptr_t) NULL;
	SteamAPI_Init = NULL;
	SteamAPI_Shutdown = NULL;
	SteamAPI_RunCallbacks = NULL;
	SteamInternal_CreateInterface = NULL;
	SteamAPI_GetHSteamUser = NULL;
	SteamAPI_GetHSteamPipe = NULL;
	SteamAPI_ISteamClient_GetISteamUserStats = NULL;
	SteamAPI_ISteamUserStats_RequestCurrentStats = NULL;
	SteamAPI_ISteamUserStats_StoreStats = NULL;
	SteamAPI_ISteamUserStats_GetStat = NULL;
	SteamAPI_ISteamUserStats_SetStat = NULL;
	SteamAPI_ISteamUserStats_SetAchievement = NULL;
}

/* NETWORK API Implementation */

int NETWORK_init()
{
	printf("Stub NETWORK_init\n");
	return 1;
//	intptr_t steamClient;
//	int32_t steamUser, steamPipe;
//
//	libHandle = SDL_LoadObject(NETWORK_LIBRARY);
//	if (!libHandle)
//	{
//		printf("%s not found!\n", NETWORK_LIBRARY);
//		return 0;
//	}
//
//	#define LOAD_FUNC(name) \
//		name = (name##Func) SDL_LoadFunction(libHandle, #name); \
//		if (!name) \
//		{ \
//			printf("%s symbol %s not found!\n", NETWORK_LIBRARY, #name); \
//			ClearPointers(); \
//			return 0; \
//		}
//	LOAD_FUNC(SteamAPI_Init)
//	LOAD_FUNC(SteamAPI_Shutdown)
//	LOAD_FUNC(SteamAPI_RunCallbacks)
//	LOAD_FUNC(SteamInternal_CreateInterface)
//	LOAD_FUNC(SteamAPI_GetHSteamUser)
//	LOAD_FUNC(SteamAPI_GetHSteamPipe)
//	LOAD_FUNC(SteamAPI_ISteamClient_GetISteamUserStats)
//	LOAD_FUNC(SteamAPI_ISteamUserStats_RequestCurrentStats)
//	LOAD_FUNC(SteamAPI_ISteamUserStats_StoreStats)
//	LOAD_FUNC(SteamAPI_ISteamUserStats_GetStat)
//	LOAD_FUNC(SteamAPI_ISteamUserStats_SetStat)
//	LOAD_FUNC(SteamAPI_ISteamUserStats_SetAchievement)
//	#undef LOAD_FUNC
//
//	if (!SteamAPI_Init())
//	{
//		printf("Steamworks not initialized!\n");
//		ClearPointers();
//		return 0;
//	}
//	steamClient = SteamInternal_CreateInterface(VVVVVV_STEAMCLIENT);
//	steamUser = SteamAPI_GetHSteamUser();
//	steamPipe = SteamAPI_GetHSteamPipe();
//	if (!steamClient || !steamUser || !steamPipe)
//	{
//		SteamAPI_Shutdown();
//		printf(VVVVVV_STEAMCLIENT " not created!\n");
//		ClearPointers();
//		return 0;
//	}
//	steamUserStats = SteamAPI_ISteamClient_GetISteamUserStats(
//		steamClient,
//		steamUser,
//		steamPipe,
//		VVVVVV_STEAMUSERSTATS
//	);
//	if (!steamUserStats)
//	{
//		SteamAPI_Shutdown();
//		printf(VVVVVV_STEAMUSERSTATS " not created!\n");
//		ClearPointers();
//		return 0;
//	}
//	SteamAPI_ISteamUserStats_RequestCurrentStats(steamUserStats);
//	return 1;
}

void NETWORK_shutdown()
{
	printf("Stub NETWORK_shutdown\n");
//	if (libHandle)
//	{
//		SteamAPI_Shutdown();
//		ClearPointers();
//	}
}

void NETWORK_update()
{
	printf("Stub NETWORK_update\n");
//	if (libHandle)
//	{
//		SteamAPI_RunCallbacks();
//	}
}

void NETWORK_unlockAchievement(const char *name)
{
	printf("Stub NETWORK_unlockAchievement\n");
//	if (libHandle)
//	{
//		SteamAPI_ISteamUserStats_SetAchievement(
//			steamUserStats,
//			name
//		);
//		SteamAPI_ISteamUserStats_StoreStats(steamUserStats);
//	}
}

int32_t NETWORK_getAchievementProgress(const char *name)
{
	printf("Stub NETWORK_getAchievementProgress\n");
	return 0;
//	int32_t result = -1;
//	if (libHandle)
//	{
//		SteamAPI_ISteamUserStats_GetStat(
//			steamUserStats,
//			name,
//			&result
//		);
//	}
//	return result;
}

void NETWORK_setAchievementProgress(const char *name, int32_t stat)
{
	printf("Stub NETWORK_setAchievementProgress\n");
//	if (libHandle)
//	{
//		SteamAPI_ISteamUserStats_SetStat(
//			steamUserStats,
//			name,
//			stat
//		);
//		SteamAPI_ISteamUserStats_StoreStats(steamUserStats);
//	}
}
