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
	originalCheckForPureServerWhitelistFn = (CL_CheckForPureServerWhitelistFn)sigscan_module("engine.so", "83 3D FD 8A 65 00 01 7E 77 80 3D A8 13 66 00 00 75 6E 48 8D 05 AF 96 6B");
	detour_init(&CL_CheckForPureServerWhitelist_ctx, (void*)originalCheckForPureServerWhitelistFn, (void*)&Hooked_CL_CheckForPureServerWhitelist);
	detour_enable(&CL_CheckForPureServerWhitelist_ctx);
}