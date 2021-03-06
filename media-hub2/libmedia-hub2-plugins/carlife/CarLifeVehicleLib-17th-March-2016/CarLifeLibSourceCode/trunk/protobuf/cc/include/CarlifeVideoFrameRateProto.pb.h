// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CarlifeVideoFrameRateProto.proto

#ifndef PROTOBUF_CarlifeVideoFrameRateProto_2eproto__INCLUDED
#define PROTOBUF_CarlifeVideoFrameRateProto_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace com {
namespace baidu {
namespace carlife {
namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_CarlifeVideoFrameRateProto_2eproto();
void protobuf_AssignDesc_CarlifeVideoFrameRateProto_2eproto();
void protobuf_ShutdownFile_CarlifeVideoFrameRateProto_2eproto();

class CarlifeVideoFrameRate;

// ===================================================================

class CarlifeVideoFrameRate : public ::google::protobuf::Message {
 public:
  CarlifeVideoFrameRate();
  virtual ~CarlifeVideoFrameRate();

  CarlifeVideoFrameRate(const CarlifeVideoFrameRate& from);

  inline CarlifeVideoFrameRate& operator=(const CarlifeVideoFrameRate& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CarlifeVideoFrameRate& default_instance();

  void Swap(CarlifeVideoFrameRate* other);

  // implements Message ----------------------------------------------

  CarlifeVideoFrameRate* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CarlifeVideoFrameRate& from);
  void MergeFrom(const CarlifeVideoFrameRate& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 frameRate = 1;
  inline bool has_framerate() const;
  inline void clear_framerate();
  static const int kFrameRateFieldNumber = 1;
  inline ::google::protobuf::int32 framerate() const;
  inline void set_framerate(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:com.baidu.carlife.protobuf.CarlifeVideoFrameRate)
 private:
  inline void set_has_framerate();
  inline void clear_has_framerate();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 framerate_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_CarlifeVideoFrameRateProto_2eproto();
  friend void protobuf_AssignDesc_CarlifeVideoFrameRateProto_2eproto();
  friend void protobuf_ShutdownFile_CarlifeVideoFrameRateProto_2eproto();

  void InitAsDefaultInstance();
  static CarlifeVideoFrameRate* default_instance_;
};
// ===================================================================


// ===================================================================

// CarlifeVideoFrameRate

// required int32 frameRate = 1;
inline bool CarlifeVideoFrameRate::has_framerate() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CarlifeVideoFrameRate::set_has_framerate() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CarlifeVideoFrameRate::clear_has_framerate() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CarlifeVideoFrameRate::clear_framerate() {
  framerate_ = 0;
  clear_has_framerate();
}
inline ::google::protobuf::int32 CarlifeVideoFrameRate::framerate() const {
  return framerate_;
}
inline void CarlifeVideoFrameRate::set_framerate(::google::protobuf::int32 value) {
  set_has_framerate();
  framerate_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace carlife
}  // namespace baidu
}  // namespace com

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CarlifeVideoFrameRateProto_2eproto__INCLUDED
