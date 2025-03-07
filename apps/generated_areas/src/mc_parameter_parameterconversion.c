#include "mc.h"


// structure definition for composite mc_parameter_parameterconversion
struct _mc_parameter_parameterconversion_t {
  mal_octet_t f_convertedtype;
  mal_string_t * f_convertedunit;
  mc_conditionalconversion_list_t * f_conditionalconversions;
};

// fields accessors for composite mc_parameter_parameterconversion
mal_octet_t mc_parameter_parameterconversion_get_convertedtype(mc_parameter_parameterconversion_t * self)
{
  return self->f_convertedtype;
}
void mc_parameter_parameterconversion_set_convertedtype(mc_parameter_parameterconversion_t * self, mal_octet_t f_convertedtype)
{
  self->f_convertedtype = f_convertedtype;
}
mal_string_t * mc_parameter_parameterconversion_get_convertedunit(mc_parameter_parameterconversion_t * self)
{
  return self->f_convertedunit;
}
void mc_parameter_parameterconversion_set_convertedunit(mc_parameter_parameterconversion_t * self, mal_string_t * f_convertedunit)
{
  self->f_convertedunit = f_convertedunit;
}
mc_conditionalconversion_list_t * mc_parameter_parameterconversion_get_conditionalconversions(mc_parameter_parameterconversion_t * self)
{
  return self->f_conditionalconversions;
}
void mc_parameter_parameterconversion_set_conditionalconversions(mc_parameter_parameterconversion_t * self, mc_conditionalconversion_list_t * f_conditionalconversions)
{
  self->f_conditionalconversions = f_conditionalconversions;
}

// default constructor
mc_parameter_parameterconversion_t * mc_parameter_parameterconversion_new(void)
{
  mc_parameter_parameterconversion_t *self = (mc_parameter_parameterconversion_t *) calloc(1, sizeof(mc_parameter_parameterconversion_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameter_parameterconversion_add_encoding_length_malbinary(mc_parameter_parameterconversion_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_octet_encoding_length(encoder, self->f_convertedtype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_convertedunit != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_convertedunit != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_convertedunit, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mc_conditionalconversion_list_add_encoding_length_malbinary(self->f_conditionalconversions, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_parameter_parameterconversion_encode_malbinary(mc_parameter_parameterconversion_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_octet(encoder, cursor, self->f_convertedtype);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_convertedunit != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_convertedunit);
    if (rc < 0)
      return rc;
  }
  rc = mc_conditionalconversion_list_encode_malbinary(self->f_conditionalconversions, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_parameter_parameterconversion_decode_malbinary(mc_parameter_parameterconversion_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_octet(decoder, cursor, &self->f_convertedtype);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_convertedunit);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_convertedunit = NULL;
  }
  self->f_conditionalconversions = mc_conditionalconversion_list_new(0);
  if (self->f_conditionalconversions == NULL) return -1;
  rc = mc_conditionalconversion_list_decode_malbinary(self->f_conditionalconversions, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_parameter_parameterconversion_destroy(mc_parameter_parameterconversion_t ** self_p)
{
  if ((*self_p)->f_convertedunit != NULL)
  {
    mal_string_destroy(& (*self_p)->f_convertedunit);
  }
  if ((*self_p)->f_conditionalconversions != NULL)
  {
    mc_conditionalconversion_list_destroy(& (*self_p)->f_conditionalconversions);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameter_parameterconversion_test(bool verbose)
{
  printf(" * MC:Parameter:ParameterConversion: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
