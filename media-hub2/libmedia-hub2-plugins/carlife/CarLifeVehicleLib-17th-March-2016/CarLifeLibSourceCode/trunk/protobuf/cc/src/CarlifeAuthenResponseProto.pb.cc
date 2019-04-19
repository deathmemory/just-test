// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CarlifeAuthenResponseProto.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "CarlifeAuthenResponseProto.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace com {
namespace baidu {
namespace carlife {
namespace protobuf {

namespace {

const ::google::protobuf::Descriptor* CarlifeAuthenResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CarlifeAuthenResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_CarlifeAuthenResponseProto_2eproto() {
  protobuf_AddDesc_CarlifeAuthenResponseProto_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "CarlifeAuthenResponseProto.proto");
  GOOGLE_CHECK(file != NULL);
  CarlifeAuthenResponse_descriptor_ = file->message_type(0);
  static const int CarlifeAuthenResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeAuthenResponse, encryptvalue_),
  };
  CarlifeAuthenResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CarlifeAuthenResponse_descriptor_,
      CarlifeAuthenResponse::default_instance_,
      CarlifeAuthenResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeAuthenResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeAuthenResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CarlifeAuthenResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_CarlifeAuthenResponseProto_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CarlifeAuthenResponse_descriptor_, &CarlifeAuthenResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_CarlifeAuthenResponseProto_2eproto() {
  delete CarlifeAuthenResponse::default_instance_;
  delete CarlifeAuthenResponse_reflection_;
}

void protobuf_AddDesc_CarlifeAuthenResponseProto_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n CarlifeAuthenResponseProto.proto\022\032com."
    "baidu.carlife.protobuf\"-\n\025CarlifeAuthenR"
    "esponse\022\024\n\014encryptValue\030\001 \002(\t", 109);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "CarlifeAuthenResponseProto.proto", &protobuf_RegisterTypes);
  CarlifeAuthenResponse::default_instance_ = new CarlifeAuthenResponse();
  CarlifeAuthenResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_CarlifeAuthenResponseProto_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_CarlifeAuthenResponseProto_2eproto {
  StaticDescriptorInitializer_CarlifeAuthenResponseProto_2eproto() {
    protobuf_AddDesc_CarlifeAuthenResponseProto_2eproto();
  }
} static_descriptor_initializer_CarlifeAuthenResponseProto_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int CarlifeAuthenResponse::kEncryptValueFieldNumber;
#endif  // !_MSC_VER

CarlifeAuthenResponse::CarlifeAuthenResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void CarlifeAuthenResponse::InitAsDefaultInstance() {
}

CarlifeAuthenResponse::CarlifeAuthenResponse(const CarlifeAuthenResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void CarlifeAuthenResponse::SharedCtor() {
  _cached_size_ = 0;
  encryptvalue_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CarlifeAuthenResponse::~CarlifeAuthenResponse() {
  SharedDtor();
}

void CarlifeAuthenResponse::SharedDtor() {
  if (encryptvalue_ != &::google::protobuf::internal::kEmptyString) {
    delete encryptvalue_;
  }
  if (this != default_instance_) {
  }
}

void CarlifeAuthenResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CarlifeAuthenResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CarlifeAuthenResponse_descriptor_;
}

const CarlifeAuthenResponse& CarlifeAuthenResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_CarlifeAuthenResponseProto_2eproto();
  return *default_instance_;
}

CarlifeAuthenResponse* CarlifeAuthenResponse::default_instance_ = NULL;

CarlifeAuthenResponse* CarlifeAuthenResponse::New() const {
  return new CarlifeAuthenResponse;
}

void CarlifeAuthenResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_encryptvalue()) {
      if (encryptvalue_ != &::google::protobuf::internal::kEmptyString) {
        encryptvalue_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CarlifeAuthenResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string encryptValue = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_encryptvalue()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->encryptvalue().data(), this->encryptvalue().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void CarlifeAuthenResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string encryptValue = 1;
  if (has_encryptvalue()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->encryptvalue().data(), this->encryptvalue().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->encryptvalue(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* CarlifeAuthenResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string encryptValue = 1;
  if (has_encryptvalue()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->encryptvalue().data(), this->encryptvalue().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->encryptvalue(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int CarlifeAuthenResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string encryptValue = 1;
    if (has_encryptvalue()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->encryptvalue());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CarlifeAuthenResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CarlifeAuthenResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CarlifeAuthenResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CarlifeAuthenResponse::MergeFrom(const CarlifeAuthenResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_encryptvalue()) {
      set_encryptvalue(from.encryptvalue());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CarlifeAuthenResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CarlifeAuthenResponse::CopyFrom(const CarlifeAuthenResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CarlifeAuthenResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void CarlifeAuthenResponse::Swap(CarlifeAuthenResponse* other) {
  if (other != this) {
    std::swap(encryptvalue_, other->encryptvalue_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CarlifeAuthenResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CarlifeAuthenResponse_descriptor_;
  metadata.reflection = CarlifeAuthenResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace carlife
}  // namespace baidu
}  // namespace com

// @@protoc_insertion_point(global_scope)
