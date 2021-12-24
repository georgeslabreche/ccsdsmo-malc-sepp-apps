/*  =========================================================================
    sm_appslauncher_listapp_consumer - The request consumer for the listApp operation

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SM_APPSLAUNCHER_LISTAPP_CONSUMER_H_INCLUDED
#define SM_APPSLAUNCHER_LISTAPP_CONSUMER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/sm_appslauncher_listapp_consumer.api" to make changes.
//  @interface
//  This is a stable class, and may not change except for emergencies. It
//  is provided in stable builds.
#define SM_APPSLAUNCHER_LISTAPP_CONSUMER_URI "sm/appslauncher/consumer/listApp"  // The consumer URI for the listApp operation

//  Create a consumer object for the listApp operation
NMFAPI_C_EXPORT sm_appslauncher_listapp_consumer_t *
    sm_appslauncher_listapp_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri);

//  The destructor
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_destroy (sm_appslauncher_listapp_consumer_t **self_p);

//  Clear the response variables
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_response_clear (sm_appslauncher_listapp_consumer_t *self);

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_mutex_lock (sm_appslauncher_listapp_consumer_t *self);

//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_mutex_unlock (sm_appslauncher_listapp_consumer_t *self);

//  Create and initialize the actor
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_actor_init (sm_appslauncher_listapp_consumer_t *self);

//  Get response variable for appsInstIds
NMFAPI_C_EXPORT long *
    sm_appslauncher_listapp_consumer_get_response_apps_inst_id_list (sm_appslauncher_listapp_consumer_t *self);

//  Get response variable for running apps
NMFAPI_C_EXPORT bool *
    sm_appslauncher_listapp_consumer_get_response_apps_inst_running_list (sm_appslauncher_listapp_consumer_t *self);

//  Get response variable for number of apps
NMFAPI_C_EXPORT size_t
    sm_appslauncher_listapp_consumer_get_response_element_count (sm_appslauncher_listapp_consumer_t *self);

//  Get error code from processing the response
NMFAPI_C_EXPORT int
    sm_appslauncher_listapp_consumer_get_response_error_code (sm_appslauncher_listapp_consumer_t *self);

//  Get the app names MAL message field
NMFAPI_C_EXPORT char **
    sm_appslauncher_listapp_consumer_get_field_app_name_list (sm_appslauncher_listapp_consumer_t *self);

//  Set the app names MAL message field
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_set_field_app_name_list (sm_appslauncher_listapp_consumer_t *self, char **app_name_list);

//  Get the size of the app names MAL message field
NMFAPI_C_EXPORT size_t
    sm_appslauncher_listapp_consumer_get_field_app_name_list_size (sm_appslauncher_listapp_consumer_t *self);

//  Set the size of the app names MAL message field
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_set_field_app_name_list_size (sm_appslauncher_listapp_consumer_t *self, size_t app_name_list_size);

//  Get the category MAL message field
NMFAPI_C_EXPORT char *
    sm_appslauncher_listapp_consumer_get_field_category (sm_appslauncher_listapp_consumer_t *self);

//  Set the category MAL message field
NMFAPI_C_EXPORT void
    sm_appslauncher_listapp_consumer_set_field_category (sm_appslauncher_listapp_consumer_t *self, char *category);

//  @end

#ifdef __cplusplus
}
#endif

#endif
