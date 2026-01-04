#include "libdetour/libdetour.h"
#include "libsigscan/libsigscan.h"

typedef void (*CL_CheckForPureServerWhitelistFn)(void** pFilesToReload);
CL_CheckForPureServerWhitelistFn originalCheckForPureServerWhitelistFn = NULL;
detour_ctx_t CL_CheckForPureServerWhitelist_ctx;

DETOUR_DECL_TYPE(void, originalCheckForPureServerWhitelistFn, void** pFilesToReload);

void Hooked_CL_CheckForPureServerWhitelist(void** pFilesToReload)
{
	return;
}

__attribute__((constructor))
void init()
{
	originalCheckForPureServerWhitelistFn = (CL_CheckForPureServerWhitelistFn)sigscan_module("engine.so", "83 3D ? ? ? ? 01 7E ? 80 3D ? ? ? ? ? 75 ?");
	detour_init(&CL_CheckForPureServerWhitelist_ctx, (void*)originalCheckForPureServerWhitelistFn, (void*)&Hooked_CL_CheckForPureServerWhitelist);
	detour_enable(&CL_CheckForPureServerWhitelist_ctx);
}