#include "mc.h"


// structure definition for composite mc_parameter_parameterrawvalue
struct _mc_parameter_parameterrawvalue_t {
  mal_long_t f_paraminstid;
  bool f_rawvalue_is_present;
  unsigned char f_rawvalue_attribute_tag;
  union mal_attribute_t f_rawvalue;
};

// fields accessors for composite mc_parameter_parameterrawvalue
mal_long_t mc_parameter_parameterrawvalue_get_paraminstid(mc_parameter_parameterrawvalue_t * self)
{
  return self->f_paraminstid;
}
void mc_parameter_parameterrawvalue_set_paraminstid(mc_parameter_parameterrawvalue_t * self, mal_long_t f_paraminstid)
{
  self->f_paraminstid = f_paraminstid;
}
bool mc_parameter_parameterrawvalue_rawvalue_is_present(mc_parameter_parameterrawvalue_t * self)
{
  return self->f_rawvalue_is_present;
}
void mc_parameter_parameterrawvalue_rawvalue_set_present(mc_parameter_parameterrawvalue_t * self, bool is_present)
{
  self->f_rawvalue_is_present = is_present;
}
unsigned char mc_parameter_parameterrawvalue_rawvalue_get_attribute_tag(mc_parameter_parameterrawvalue_t * self)
{
  return self->f_rawvalue_attribute_tag;
}
void mc_parameter_parameterrawvalue_rawvalue_set_attribute_tag(mc_parameter_parameterrawvalue_t * self, unsigned char attribute_tag)
{
  self->f_rawvalue_attribute_tag = attribute_tag;
}
union mal_attribute_t mc_parameter_parameterrawvalue_get_rawvalue(mc_parameter_parameterrawvalue_t * self)
{
  return self->f_rawvalue;
}
void mc_parameter_parameterrawvalue_set_rawvalue(mc_parameter_parameterrawvalue_t * self, union mal_attribute_t f_rawvalue)
{
  self->f_rawvalue = f_rawvalue;
}

// default constructor
mc_parameter_parameterrawvalue_t * mc_parameter_parameterrawvalue_new(void)
{
  mc_parameter_parameterrawvalue_t *self = (mc_parameter_parameterrawvalue_t *) calloc(1, sizeof(mc_parameter_parameterrawvalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameter_parameterrawvalue_add_encoding_length_malbinary(mc_parameter_parameterrawvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_paraminstid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_rawvalue_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_rawvalue_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_rawvalue_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_rawvalue_attribute_tag, self->f_rawvalue, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameter_parameterrawvalue_encode_malbinary(mc_parameter_parameterrawvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_paraminstid);
  if (rc < 0)
    return rc;
  presence_flag = self->f_rawvalue_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_rawvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_rawvalue_attribute_tag, self->f_rawvalue);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameter_parameterrawvalue_decode_malbinary(mc_parameter_parameterrawvalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_paraminstid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_rawvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_rawvalue_attribute_tag, &self->f_rawvalue);
    if (rc < 0)
      return rc;
  }
  self->f_rawvalue_is_present = presence_flag;
  return rc;
}

// destructor
void mc_parameter_parameterrawvalue_destroy(mc_parameter_parameterrawvalue_t ** self_p)
{
  if ((*self_p)->f_rawvalue_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_rawvalue, (*self_p)->f_rawvalue_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameter_parameterrawvalue_test(bool verbose)
{
  printf(" * MC:Parameter:ParameterRawValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
