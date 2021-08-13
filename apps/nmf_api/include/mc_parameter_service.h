/*  =========================================================================
    mc_parameter_service - The parameter service allows the user to subscribe to parameter value report and optionally be able to set new values.

    The MIT License (MIT)
    =========================================================================
*/

#ifndef MC_PARAMETER_SERVICE_H_INCLUDED
#define MC_PARAMETER_SERVICE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/mc_parameter_service.api" to make changes.
//  @interface
//  This API is a draft, and may change without notice.
#ifdef NMF_API_BUILD_DRAFT_API
//  *** Draft method, for development use, may change without warning ***
//  Instanciate a consumer object for the getValue operation.
NMF_API_EXPORT mc_parameter_service_t *
    mc_parameter_service_new (const char *provider_host, const char *provider_port, const char *consumer_port);

//  *** Draft method, for development use, may change without warning ***
//  The destructor.
NMF_API_EXPORT void
    mc_parameter_service_destroy (mc_parameter_service_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//
NMF_API_EXPORT void
    mc_parameter_service_get_value (mc_parameter_service_t *self, long *param_inst_ids);

//  *** Draft method, for development use, may change without warning ***
//  Self test of this class.
NMF_API_EXPORT void
    mc_parameter_service_test (bool verbose);

#endif // NMF_API_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif
