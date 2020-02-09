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

class RecentStreamTimeInfo : public common::serializer::JsonSerializer<RecentStreamTimeInfo> {
 public:
  RecentStreamTimeInfo();
  RecentStreamTimeInfo(stream_id_t id, timestamp_t time);

  bool IsValid() const;

  void SetChannel(stream_id_t channel);
  stream_id_t GetChannel() const;

  void SetTimestamp(timestamp_t time);
  timestamp_t GetTimestamp() const;

  bool Equals(const RecentStreamTimeInfo& eq) const;

 protected:
  common::Error DoDeSerialize(json_object* serialized) override;
  common::Error SerializeFields(json_object* deserialized) const override;

 private:
  stream_id_t id_;
  timestamp_t timestamp_utc_;
};

inline bool operator==(const RecentStreamTimeInfo& lhs, const RecentStreamTimeInfo& rhs) {
  return lhs.Equals(rhs);
}

inline bool operator!=(const RecentStreamTimeInfo& x, const RecentStreamTimeInfo& y) {
  return !(x == y);
}

}  // namespace commands_info
}  // namespace fastotv