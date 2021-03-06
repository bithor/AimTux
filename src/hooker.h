#ifndef __HOOKER_H_
#define __HOOKER_H_

#define CCSMODEMANAGER_INIT_SIGNATURE "\x48\x8D\x05\x00\x00\x00\x00\x48\x89\xE5\x48\x89\x05\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x5D\x48"
#define CCSMODEMANAGER_INIT_MASK "xxx????xxxxxx????x????xx"

#define GLOWOBJECT_SIGNATURE "\xE8\x00\x00\x00\x00\x48\x8B\x3D\x00\x00\x00\x00\xBE\x01\x00\x00\x00\xC7"
#define GLOWOBJECT_MASK "x????xxx????xxxxxx"

#define MSGFUNC_SERVERRANKREVEALALL_SIGNATURE "\x55\x48\x89\xE5\x53\x48\x89\xFB\x48\x83\xEC\x08\xE8\x00\x00\x00\x00\x48\x8D\x00\x00\x00\x00\x00\x48\x8B\x10\x48\x89\xC7\xFF\x52\x28"
#define MSGFUNC_SERVERRANKREVEALALL_MASK "xxxxxxxxxxxxx????xx?????xxxxxxxxx"

#define SENDCLANTAG_SIGNATURE "\x55\x48\x89\xE5\x48\x89\x5D\xE8\x4C\x89\x65\xF0\x49\x89\xFC\xBF\x48\x00\x00\x00\x4C\x89\x6D\xF8\x48\x83\xEC\x20\x49"
#define SENDCLANTAG_MASK "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

#include <link.h>
#include "patternfinder.h"
#include "SDK/SDK.h"
#include "vmt.h"

namespace Hooker
{
	void HookInterfaces();
	void HookVMethods();
	void HookIClientMode();
	void HookGlobalVars();
	void HookGlowManager();
	void HookRankReveal();
	void HookSendClanTag();
}

#endif