#include "pf.h"


// structure definition for composite pf_autonomousadcs_attitudemodesunpointing
struct _pf_autonomousadcs_attitudemodesunpointing_t {
};

// fields accessors for composite pf_autonomousadcs_attitudemodesunpointing

// default constructor
pf_autonomousadcs_attitudemodesunpointing_t * pf_autonomousadcs_attitudemodesunpointing_new(void)
{
  pf_autonomousadcs_attitudemodesunpointing_t *self = (pf_autonomousadcs_attitudemodesunpointing_t *) calloc(1, sizeof(pf_autonomousadcs_attitudemodesunpointing_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodesunpointing_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodesunpointing_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  return rc;
}
int pf_autonomousadcs_attitudemodesunpointing_encode_malbinary(pf_autonomousadcs_attitudemodesunpointing_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  return rc;
}
int pf_autonomousadcs_attitudemodesunpointing_decode_malbinary(pf_autonomousadcs_attitudemodesunpointing_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  return rc;
}

// destructor
void pf_autonomousadcs_attitudemodesunpointing_destroy(pf_autonomousadcs_attitudemodesunpointing_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_attitudemodesunpointing_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:AttitudeModeSunPointing: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
