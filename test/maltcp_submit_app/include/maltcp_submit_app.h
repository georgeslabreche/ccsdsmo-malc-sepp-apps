#ifndef __MALTCP_SUBMIT_APP_H_INCLUDED__
#define __MALTCP_SUBMIT_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "maltcp.h"
#include "testarea.h"
#include "malactor.h"

#define MALTCP_SUBMIT_APP_VERSION_MAJOR 1
#define MALTCP_SUBMIT_APP_VERSION_MINOR 0
#define MALTCP_SUBMIT_APP_VERSION_PATCH 0

#define MALTCP_SUBMIT_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MALTCP_SUBMIT_APP_VERSION \
		MALTCP_SUBMIT_APP_MAKE_VERSION(MALTCP_SUBMIT_APP_VERSION_MAJOR, MALTCP_SUBMIT_APP_VERSION_MINOR, MALTCP_SUBMIT_APP_VERSION_PATCH)

typedef struct _maltcp_submit_app_myprovider_t maltcp_submit_app_myprovider_t;
typedef struct _maltcp_submit_app_myconsumer_t maltcp_submit_app_myconsumer_t;

void maltcp_submit_app_test(bool verbose);

// Public API classes
#include "maltcp_submit_app_myconsumer.h"
#include "maltcp_submit_app_myprovider.h"

#ifdef __cplusplus
}
#endif

#endif
