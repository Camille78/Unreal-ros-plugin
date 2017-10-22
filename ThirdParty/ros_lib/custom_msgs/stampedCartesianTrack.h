#ifndef _ROS_mdt_msgs_stampedCartesianTrack_h
#define _ROS_mdt_msgs_stampedCartesianTrack_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "geographic_msgs/KeyValue.h"

namespace mdt_msgs
{

  class stampedCartesianTrack : public ros::Msg
  {
    public:
      typedef geometry_msgs::PointStamped _cart_track_type;
      _cart_track_type cart_track;
      typedef double _cog_type;
      _cog_type cog;
      typedef double _sog_type;
      _sog_type sog;
      typedef double _age_type;
      _age_type age;
      typedef int32_t _trackID_type;
      _trackID_type trackID;
      typedef geographic_msgs::KeyValue _additionalParameter_type;
      _additionalParameter_type additionalParameter;

    stampedCartesianTrack():
      cart_track(),
      cog(0),
      sog(0),
      age(0),
      trackID(0),
      additionalParameter()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cart_track.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_cog;
      u_cog.real = this->cog;
      *(outbuffer + offset + 0) = (u_cog.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cog.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cog.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cog.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cog.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cog.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cog.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cog.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cog);
      union {
        double real;
        uint64_t base;
      } u_sog;
      u_sog.real = this->sog;
      *(outbuffer + offset + 0) = (u_sog.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sog.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sog.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sog.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sog.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sog.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sog.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sog.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sog);
      union {
        double real;
        uint64_t base;
      } u_age;
      u_age.real = this->age;
      *(outbuffer + offset + 0) = (u_age.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_age.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_age.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_age.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_age.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_age.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_age.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_age.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->age);
      union {
        int32_t real;
        uint32_t base;
      } u_trackID;
      u_trackID.real = this->trackID;
      *(outbuffer + offset + 0) = (u_trackID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trackID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trackID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trackID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trackID);
      offset += this->additionalParameter.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cart_track.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_cog;
      u_cog.base = 0;
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cog.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cog = u_cog.real;
      offset += sizeof(this->cog);
      union {
        double real;
        uint64_t base;
      } u_sog;
      u_sog.base = 0;
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sog.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sog = u_sog.real;
      offset += sizeof(this->sog);
      union {
        double real;
        uint64_t base;
      } u_age;
      u_age.base = 0;
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_age.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->age = u_age.real;
      offset += sizeof(this->age);
      union {
        int32_t real;
        uint32_t base;
      } u_trackID;
      u_trackID.base = 0;
      u_trackID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trackID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trackID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trackID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->trackID = u_trackID.real;
      offset += sizeof(this->trackID);
      offset += this->additionalParameter.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mdt_msgs/stampedCartesianTrack"; };
    const char * getMD5(){ return "dc36a6899a1b846f3a33d87b0faa83c3"; };

  };

}
#endif