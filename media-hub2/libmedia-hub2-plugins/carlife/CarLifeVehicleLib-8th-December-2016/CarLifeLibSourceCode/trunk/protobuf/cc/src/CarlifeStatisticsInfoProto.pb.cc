// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CarlifeStatisticsInfoProto.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "CarlifeStatisticsInfoProto.pb.h"

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

const ::google::protobuf::Descriptor* CarlifeStatisticsInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CarlifeStatisticsInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_CarlifeStatisticsInfoProto_2eproto() {
  protobuf_AddDesc_CarlifeStatisticsInfoProto_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "CarlifeStatisticsInfoProto.proto");
  GOOGLE_CHECK(file != NULL);
  CarlifeStatisticsInfo_descriptor_ = file->message_type(0);
  static const int CarlifeStatisticsInfo_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, cuid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, versionname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, versioncode_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, channel_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, connectcount_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, connectsuccesscount_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, connecttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, crashlog_),
  };
  CarlifeStatisticsInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CarlifeStatisticsInfo_descriptor_,
      CarlifeStatisticsInfo::default_instance_,
      CarlifeStatisticsInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CarlifeStatisticsInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CarlifeStatisticsInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_CarlifeStatisticsInfoProto_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CarlifeStatisticsInfo_descriptor_, &CarlifeStatisticsInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_CarlifeStatisticsInfoProto_2eproto() {
  delete CarlifeStatisticsInfo::default_instance_;
  delete CarlifeStatisticsInfo_reflection_;
}

void protobuf_AddDesc_CarlifeStatisticsInfoProto_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n CarlifeStatisticsInfoProto.proto\022\032com."
    "baidu.carlife.protobuf\"\272\001\n\025CarlifeStatis"
    "ticsInfo\022\014\n\004cuid\030\001 \002(\t\022\023\n\013versionName\030\002 "
    "\002(\t\022\023\n\013versionCode\030\003 \002(\005\022\017\n\007channel\030\004 \002("
    "\t\022\024\n\014connectCount\030\005 \002(\005\022\033\n\023connectSucces"
    "sCount\030\006 \002(\005\022\023\n\013connectTime\030\007 \002(\005\022\020\n\010cra"
    "shLog\030\010 \001(\t", 251);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "CarlifeStatisticsInfoProto.proto", &protobuf_RegisterTypes);
  CarlifeStatisticsInfo::default_instance_ = new CarlifeStatisticsInfo();
  CarlifeStatisticsInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_CarlifeStatisticsInfoProto_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_CarlifeStatisticsInfoProto_2eproto {
  StaticDescriptorInitializer_CarlifeStatisticsInfoProto_2eproto() {
    protobuf_AddDesc_CarlifeStatisticsInfoProto_2eproto();
  }
} static_descriptor_initializer_CarlifeStatisticsInfoProto_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int CarlifeStatisticsInfo::kCuidFieldNumber;
const int CarlifeStatisticsInfo::kVersionNameFieldNumber;
const int CarlifeStatisticsInfo::kVersionCodeFieldNumber;
const int CarlifeStatisticsInfo::kChannelFieldNumber;
const int CarlifeStatisticsInfo::kConnectCountFieldNumber;
const int CarlifeStatisticsInfo::kConnectSuccessCountFieldNumber;
const int CarlifeStatisticsInfo::kConnectTimeFieldNumber;
const int CarlifeStatisticsInfo::kCrashLogFieldNumber;
#endif  // !_MSC_VER

CarlifeStatisticsInfo::CarlifeStatisticsInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void CarlifeStatisticsInfo::InitAsDefaultInstance() {
}

CarlifeStatisticsInfo::CarlifeStatisticsInfo(const CarlifeStatisticsInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void CarlifeStatisticsInfo::SharedCtor() {
  _cached_size_ = 0;
  cuid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  versionname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  versioncode_ = 0;
  channel_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  connectcount_ = 0;
  connectsuccesscount_ = 0;
  connecttime_ = 0;
  crashlog_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CarlifeStatisticsInfo::~CarlifeStatisticsInfo() {
  SharedDtor();
}

void CarlifeStatisticsInfo::SharedDtor() {
  if (cuid_ != &::google::protobuf::internal::kEmptyString) {
    delete cuid_;
  }
  if (versionname_ != &::google::protobuf::internal::kEmptyString) {
    delete versionname_;
  }
  if (channel_ != &::google::protobuf::internal::kEmptyString) {
    delete channel_;
  }
  if (crashlog_ != &::google::protobuf::internal::kEmptyString) {
    delete crashlog_;
  }
  if (this != default_instance_) {
  }
}

void CarlifeStatisticsInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CarlifeStatisticsInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CarlifeStatisticsInfo_descriptor_;
}

const CarlifeStatisticsInfo& CarlifeStatisticsInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_CarlifeStatisticsInfoProto_2eproto();
  return *default_instance_;
}

CarlifeStatisticsInfo* CarlifeStatisticsInfo::default_instance_ = NULL;

CarlifeStatisticsInfo* CarlifeStatisticsInfo::New() const {
  return new CarlifeStatisticsInfo;
}

void CarlifeStatisticsInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_cuid()) {
      if (cuid_ != &::google::protobuf::internal::kEmptyString) {
        cuid_->clear();
      }
    }
    if (has_versionname()) {
      if (versionname_ != &::google::protobuf::internal::kEmptyString) {
        versionname_->clear();
      }
    }
    versioncode_ = 0;
    if (has_channel()) {
      if (channel_ != &::google::protobuf::internal::kEmptyString) {
        channel_->clear();
      }
    }
    connectcount_ = 0;
    connectsuccesscount_ = 0;
    connecttime_ = 0;
    if (has_crashlog()) {
      if (crashlog_ != &::google::protobuf::internal::kEmptyString) {
        crashlog_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CarlifeStatisticsInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string cuid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_cuid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->cuid().data(), this->cuid().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_versionName;
        break;
      }

      // required string versionName = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_versionName:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_versionname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->versionname().data(), this->versionname().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_versionCode;
        break;
      }

      // required int32 versionCode = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_versionCode:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &versioncode_)));
          set_has_versioncode();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_channel;
        break;
      }

      // required string channel = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_channel:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_channel()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->channel().data(), this->channel().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_connectCount;
        break;
      }

      // required int32 connectCount = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_connectCount:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &connectcount_)));
          set_has_connectcount();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_connectSuccessCount;
        break;
      }

      // required int32 connectSuccessCount = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_connectSuccessCount:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &connectsuccesscount_)));
          set_has_connectsuccesscount();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_connectTime;
        break;
      }

      // required int32 connectTime = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_connectTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &connecttime_)));
          set_has_connecttime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_crashLog;
        break;
      }

      // optional string crashLog = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_crashLog:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_crashlog()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->crashlog().data(), this->crashlog().length(),
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

void CarlifeStatisticsInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string cuid = 1;
  if (has_cuid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->cuid().data(), this->cuid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->cuid(), output);
  }

  // required string versionName = 2;
  if (has_versionname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->versionname().data(), this->versionname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->versionname(), output);
  }

  // required int32 versionCode = 3;
  if (has_versioncode()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->versioncode(), output);
  }

  // required string channel = 4;
  if (has_channel()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->channel().data(), this->channel().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->channel(), output);
  }

  // required int32 connectCount = 5;
  if (has_connectcount()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->connectcount(), output);
  }

  // required int32 connectSuccessCount = 6;
  if (has_connectsuccesscount()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->connectsuccesscount(), output);
  }

  // required int32 connectTime = 7;
  if (has_connecttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->connecttime(), output);
  }

  // optional string crashLog = 8;
  if (has_crashlog()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->crashlog().data(), this->crashlog().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      8, this->crashlog(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* CarlifeStatisticsInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string cuid = 1;
  if (has_cuid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->cuid().data(), this->cuid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->cuid(), target);
  }

  // required string versionName = 2;
  if (has_versionname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->versionname().data(), this->versionname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->versionname(), target);
  }

  // required int32 versionCode = 3;
  if (has_versioncode()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->versioncode(), target);
  }

  // required string channel = 4;
  if (has_channel()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->channel().data(), this->channel().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->channel(), target);
  }

  // required int32 connectCount = 5;
  if (has_connectcount()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->connectcount(), target);
  }

  // required int32 connectSuccessCount = 6;
  if (has_connectsuccesscount()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->connectsuccesscount(), target);
  }

  // required int32 connectTime = 7;
  if (has_connecttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->connecttime(), target);
  }

  // optional string crashLog = 8;
  if (has_crashlog()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->crashlog().data(), this->crashlog().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->crashlog(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int CarlifeStatisticsInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string cuid = 1;
    if (has_cuid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->cuid());
    }

    // required string versionName = 2;
    if (has_versionname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->versionname());
    }

    // required int32 versionCode = 3;
    if (has_versioncode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->versioncode());
    }

    // required string channel = 4;
    if (has_channel()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->channel());
    }

    // required int32 connectCount = 5;
    if (has_connectcount()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->connectcount());
    }

    // required int32 connectSuccessCount = 6;
    if (has_connectsuccesscount()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->connectsuccesscount());
    }

    // required int32 connectTime = 7;
    if (has_connecttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->connecttime());
    }

    // optional string crashLog = 8;
    if (has_crashlog()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->crashlog());
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

void CarlifeStatisticsInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CarlifeStatisticsInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CarlifeStatisticsInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CarlifeStatisticsInfo::MergeFrom(const CarlifeStatisticsInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_cuid()) {
      set_cuid(from.cuid());
    }
    if (from.has_versionname()) {
      set_versionname(from.versionname());
    }
    if (from.has_versioncode()) {
      set_versioncode(from.versioncode());
    }
    if (from.has_channel()) {
      set_channel(from.channel());
    }
    if (from.has_connectcount()) {
      set_connectcount(from.connectcount());
    }
    if (from.has_connectsuccesscount()) {
      set_connectsuccesscount(from.connectsuccesscount());
    }
    if (from.has_connecttime()) {
      set_connecttime(from.connecttime());
    }
    if (from.has_crashlog()) {
      set_crashlog(from.crashlog());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CarlifeStatisticsInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CarlifeStatisticsInfo::CopyFrom(const CarlifeStatisticsInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CarlifeStatisticsInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000007f) != 0x0000007f) return false;

  return true;
}

void CarlifeStatisticsInfo::Swap(CarlifeStatisticsInfo* other) {
  if (other != this) {
    std::swap(cuid_, other->cuid_);
    std::swap(versionname_, other->versionname_);
    std::swap(versioncode_, other->versioncode_);
    std::swap(channel_, other->channel_);
    std::swap(connectcount_, other->connectcount_);
    std::swap(connectsuccesscount_, other->connectsuccesscount_);
    std::swap(connecttime_, other->connecttime_);
    std::swap(crashlog_, other->crashlog_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CarlifeStatisticsInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CarlifeStatisticsInfo_descriptor_;
  metadata.reflection = CarlifeStatisticsInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace carlife
}  // namespace baidu
}  // namespace com

// @@protoc_insertion_point(global_scope)