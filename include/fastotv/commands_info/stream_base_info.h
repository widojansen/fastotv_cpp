/*  Copyright (C) 2014-2020 FastoGT. All right reserved.

    This file is part of FastoTV.

    FastoTV is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoTV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoTV. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>

#include <common/serializer/json_serializer.h>

#include <fastotv/types.h>

namespace fastotv {
namespace commands_info {

class StreamBaseInfo : public common::serializer::JsonSerializer<StreamBaseInfo> {
 public:
  typedef unsigned int iarc_t;
  typedef std::vector<stream_id_t> parts_t;
  static const iarc_t DEFAULT_IARC = 21;

  StreamBaseInfo();
  StreamBaseInfo(stream_id_t sid,
                 const std::string& group,
                 iarc_t iarc,
                 bool favorite,
                 timestamp_t recent,
                 timestamp_t interruption_time,
                 bool enable_audio,
                 bool enable_video,
                 const parts_t& parts);

  bool IsValid() const;

  stream_id_t GetStreamID() const;
  void SetStreamID(const stream_id_t sid);

  std::string GetGroup() const;
  void SetGroup(const std::string& group);

  iarc_t GetIARC() const;
  void SetIARC(iarc_t iarc);

  timestamp_t GetRecent() const;
  void SetRecent(timestamp_t rec);

  bool GetFavorite() const;
  void SetFavorite(bool fav);

  timestamp_t GetInterruptionTime() const;
  void SetInterruptionTime(timestamp_t iarc);

  bool IsEnableAudio() const;
  bool IsEnableVideo() const;

  parts_t GetParts() const;
  void SetParts(const parts_t& parts);

  bool Equals(const StreamBaseInfo& url) const;

 protected:
  common::Error DoDeSerialize(json_object* serialized) override;
  common::Error SerializeFields(json_object* deserialized) const override;

 private:
  stream_id_t stream_id_;
  std::string group_;
  iarc_t iarc_;
  bool favorite_;
  timestamp_t recent_;
  timestamp_t interruption_time_;

  bool enable_audio_;
  bool enable_video_;
  parts_t parts_;
};

inline bool operator==(const StreamBaseInfo& left, const StreamBaseInfo& right) {
  return left.Equals(right);
}

inline bool operator!=(const StreamBaseInfo& x, const StreamBaseInfo& y) {
  return !(x == y);
}

}  // namespace commands_info
}  // namespace fastotv
