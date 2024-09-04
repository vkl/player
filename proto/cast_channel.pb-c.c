/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: cast_channel.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "cast_channel.pb-c.h"
void   api__cast_message__init
                     (Api__CastMessage         *message)
{
  static const Api__CastMessage init_value = API__CAST_MESSAGE__INIT;
  *message = init_value;
}
size_t api__cast_message__get_packed_size
                     (const Api__CastMessage *message)
{
  assert(message->base.descriptor == &api__cast_message__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t api__cast_message__pack
                     (const Api__CastMessage *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &api__cast_message__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t api__cast_message__pack_to_buffer
                     (const Api__CastMessage *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &api__cast_message__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Api__CastMessage *
       api__cast_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Api__CastMessage *)
     protobuf_c_message_unpack (&api__cast_message__descriptor,
                                allocator, len, data);
}
void   api__cast_message__free_unpacked
                     (Api__CastMessage *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &api__cast_message__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   api__auth_challenge__init
                     (Api__AuthChallenge         *message)
{
  static const Api__AuthChallenge init_value = API__AUTH_CHALLENGE__INIT;
  *message = init_value;
}
size_t api__auth_challenge__get_packed_size
                     (const Api__AuthChallenge *message)
{
  assert(message->base.descriptor == &api__auth_challenge__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t api__auth_challenge__pack
                     (const Api__AuthChallenge *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &api__auth_challenge__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t api__auth_challenge__pack_to_buffer
                     (const Api__AuthChallenge *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &api__auth_challenge__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Api__AuthChallenge *
       api__auth_challenge__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Api__AuthChallenge *)
     protobuf_c_message_unpack (&api__auth_challenge__descriptor,
                                allocator, len, data);
}
void   api__auth_challenge__free_unpacked
                     (Api__AuthChallenge *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &api__auth_challenge__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   api__auth_response__init
                     (Api__AuthResponse         *message)
{
  static const Api__AuthResponse init_value = API__AUTH_RESPONSE__INIT;
  *message = init_value;
}
size_t api__auth_response__get_packed_size
                     (const Api__AuthResponse *message)
{
  assert(message->base.descriptor == &api__auth_response__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t api__auth_response__pack
                     (const Api__AuthResponse *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &api__auth_response__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t api__auth_response__pack_to_buffer
                     (const Api__AuthResponse *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &api__auth_response__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Api__AuthResponse *
       api__auth_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Api__AuthResponse *)
     protobuf_c_message_unpack (&api__auth_response__descriptor,
                                allocator, len, data);
}
void   api__auth_response__free_unpacked
                     (Api__AuthResponse *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &api__auth_response__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   api__auth_error__init
                     (Api__AuthError         *message)
{
  static const Api__AuthError init_value = API__AUTH_ERROR__INIT;
  *message = init_value;
}
size_t api__auth_error__get_packed_size
                     (const Api__AuthError *message)
{
  assert(message->base.descriptor == &api__auth_error__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t api__auth_error__pack
                     (const Api__AuthError *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &api__auth_error__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t api__auth_error__pack_to_buffer
                     (const Api__AuthError *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &api__auth_error__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Api__AuthError *
       api__auth_error__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Api__AuthError *)
     protobuf_c_message_unpack (&api__auth_error__descriptor,
                                allocator, len, data);
}
void   api__auth_error__free_unpacked
                     (Api__AuthError *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &api__auth_error__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   api__device_auth_message__init
                     (Api__DeviceAuthMessage         *message)
{
  static const Api__DeviceAuthMessage init_value = API__DEVICE_AUTH_MESSAGE__INIT;
  *message = init_value;
}
size_t api__device_auth_message__get_packed_size
                     (const Api__DeviceAuthMessage *message)
{
  assert(message->base.descriptor == &api__device_auth_message__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t api__device_auth_message__pack
                     (const Api__DeviceAuthMessage *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &api__device_auth_message__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t api__device_auth_message__pack_to_buffer
                     (const Api__DeviceAuthMessage *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &api__device_auth_message__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Api__DeviceAuthMessage *
       api__device_auth_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Api__DeviceAuthMessage *)
     protobuf_c_message_unpack (&api__device_auth_message__descriptor,
                                allocator, len, data);
}
void   api__device_auth_message__free_unpacked
                     (Api__DeviceAuthMessage *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &api__device_auth_message__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCEnumValue api__cast_message__protocol_version__enum_values_by_number[1] =
{
  { "CASTV2_1_0", "API__CAST_MESSAGE__PROTOCOL_VERSION__CASTV2_1_0", 0 },
};
static const ProtobufCIntRange api__cast_message__protocol_version__value_ranges[] = {
{0, 0},{0, 1}
};
static const ProtobufCEnumValueIndex api__cast_message__protocol_version__enum_values_by_name[1] =
{
  { "CASTV2_1_0", 0 },
};
const ProtobufCEnumDescriptor api__cast_message__protocol_version__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "api.CastMessage.ProtocolVersion",
  "ProtocolVersion",
  "Api__CastMessage__ProtocolVersion",
  "api",
  1,
  api__cast_message__protocol_version__enum_values_by_number,
  1,
  api__cast_message__protocol_version__enum_values_by_name,
  1,
  api__cast_message__protocol_version__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const ProtobufCEnumValue api__cast_message__payload_type__enum_values_by_number[2] =
{
  { "STRING", "API__CAST_MESSAGE__PAYLOAD_TYPE__STRING", 0 },
  { "BINARY", "API__CAST_MESSAGE__PAYLOAD_TYPE__BINARY", 1 },
};
static const ProtobufCIntRange api__cast_message__payload_type__value_ranges[] = {
{0, 0},{0, 2}
};
static const ProtobufCEnumValueIndex api__cast_message__payload_type__enum_values_by_name[2] =
{
  { "BINARY", 1 },
  { "STRING", 0 },
};
const ProtobufCEnumDescriptor api__cast_message__payload_type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "api.CastMessage.PayloadType",
  "PayloadType",
  "Api__CastMessage__PayloadType",
  "api",
  2,
  api__cast_message__payload_type__enum_values_by_number,
  2,
  api__cast_message__payload_type__enum_values_by_name,
  1,
  api__cast_message__payload_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const ProtobufCFieldDescriptor api__cast_message__field_descriptors[7] =
{
  {
    "protocol_version",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Api__CastMessage, protocol_version),
    &api__cast_message__protocol_version__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "source_id",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Api__CastMessage, source_id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "destination_id",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Api__CastMessage, destination_id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "namespace",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Api__CastMessage, namespace_),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload_type",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Api__CastMessage, payload_type),
    &api__cast_message__payload_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload_utf8",
    6,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Api__CastMessage, payload_utf8),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload_binary",
    7,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Api__CastMessage, has_payload_binary),
    offsetof(Api__CastMessage, payload_binary),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned api__cast_message__field_indices_by_name[] = {
  2,   /* field[2] = destination_id */
  3,   /* field[3] = namespace */
  6,   /* field[6] = payload_binary */
  4,   /* field[4] = payload_type */
  5,   /* field[5] = payload_utf8 */
  0,   /* field[0] = protocol_version */
  1,   /* field[1] = source_id */
};
static const ProtobufCIntRange api__cast_message__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 7 }
};
const ProtobufCMessageDescriptor api__cast_message__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "api.CastMessage",
  "CastMessage",
  "Api__CastMessage",
  "api",
  sizeof(Api__CastMessage),
  7,
  api__cast_message__field_descriptors,
  api__cast_message__field_indices_by_name,
  1,  api__cast_message__number_ranges,
  (ProtobufCMessageInit) api__cast_message__init,
  NULL,NULL,NULL    /* reserved[123] */
};
#define api__auth_challenge__field_descriptors NULL
#define api__auth_challenge__field_indices_by_name NULL
#define api__auth_challenge__number_ranges NULL
const ProtobufCMessageDescriptor api__auth_challenge__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "api.AuthChallenge",
  "AuthChallenge",
  "Api__AuthChallenge",
  "api",
  sizeof(Api__AuthChallenge),
  0,
  api__auth_challenge__field_descriptors,
  api__auth_challenge__field_indices_by_name,
  0,  api__auth_challenge__number_ranges,
  (ProtobufCMessageInit) api__auth_challenge__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor api__auth_response__field_descriptors[2] =
{
  {
    "signature",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Api__AuthResponse, signature),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "client_auth_certificate",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Api__AuthResponse, client_auth_certificate),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned api__auth_response__field_indices_by_name[] = {
  1,   /* field[1] = client_auth_certificate */
  0,   /* field[0] = signature */
};
static const ProtobufCIntRange api__auth_response__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor api__auth_response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "api.AuthResponse",
  "AuthResponse",
  "Api__AuthResponse",
  "api",
  sizeof(Api__AuthResponse),
  2,
  api__auth_response__field_descriptors,
  api__auth_response__field_indices_by_name,
  1,  api__auth_response__number_ranges,
  (ProtobufCMessageInit) api__auth_response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue api__auth_error__error_type__enum_values_by_number[2] =
{
  { "INTERNAL_ERROR", "API__AUTH_ERROR__ERROR_TYPE__INTERNAL_ERROR", 0 },
  { "NO_TLS", "API__AUTH_ERROR__ERROR_TYPE__NO_TLS", 1 },
};
static const ProtobufCIntRange api__auth_error__error_type__value_ranges[] = {
{0, 0},{0, 2}
};
static const ProtobufCEnumValueIndex api__auth_error__error_type__enum_values_by_name[2] =
{
  { "INTERNAL_ERROR", 0 },
  { "NO_TLS", 1 },
};
const ProtobufCEnumDescriptor api__auth_error__error_type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "api.AuthError.ErrorType",
  "ErrorType",
  "Api__AuthError__ErrorType",
  "api",
  2,
  api__auth_error__error_type__enum_values_by_number,
  2,
  api__auth_error__error_type__enum_values_by_name,
  1,
  api__auth_error__error_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const ProtobufCFieldDescriptor api__auth_error__field_descriptors[1] =
{
  {
    "error_type",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Api__AuthError, error_type),
    &api__auth_error__error_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned api__auth_error__field_indices_by_name[] = {
  0,   /* field[0] = error_type */
};
static const ProtobufCIntRange api__auth_error__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor api__auth_error__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "api.AuthError",
  "AuthError",
  "Api__AuthError",
  "api",
  sizeof(Api__AuthError),
  1,
  api__auth_error__field_descriptors,
  api__auth_error__field_indices_by_name,
  1,  api__auth_error__number_ranges,
  (ProtobufCMessageInit) api__auth_error__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor api__device_auth_message__field_descriptors[3] =
{
  {
    "challenge",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Api__DeviceAuthMessage, challenge),
    &api__auth_challenge__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "response",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Api__DeviceAuthMessage, response),
    &api__auth_response__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "error",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Api__DeviceAuthMessage, error),
    &api__auth_error__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned api__device_auth_message__field_indices_by_name[] = {
  0,   /* field[0] = challenge */
  2,   /* field[2] = error */
  1,   /* field[1] = response */
};
static const ProtobufCIntRange api__device_auth_message__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor api__device_auth_message__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "api.DeviceAuthMessage",
  "DeviceAuthMessage",
  "Api__DeviceAuthMessage",
  "api",
  sizeof(Api__DeviceAuthMessage),
  3,
  api__device_auth_message__field_descriptors,
  api__device_auth_message__field_indices_by_name,
  1,  api__device_auth_message__number_ranges,
  (ProtobufCMessageInit) api__device_auth_message__init,
  NULL,NULL,NULL    /* reserved[123] */
};
