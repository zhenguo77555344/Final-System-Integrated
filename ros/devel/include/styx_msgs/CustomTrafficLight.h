// Generated by gencpp from file styx_msgs/CustomTrafficLight.msg
// DO NOT EDIT!


#ifndef STYX_MSGS_MESSAGE_CUSTOMTRAFFICLIGHT_H
#define STYX_MSGS_MESSAGE_CUSTOMTRAFFICLIGHT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace styx_msgs
{
template <class ContainerAllocator>
struct CustomTrafficLight_
{
  typedef CustomTrafficLight_<ContainerAllocator> Type;

  CustomTrafficLight_()
    : state(0)
    , waypoint(0)  {
    }
  CustomTrafficLight_(const ContainerAllocator& _alloc)
    : state(0)
    , waypoint(0)  {
  (void)_alloc;
    }



   typedef uint8_t _state_type;
  _state_type state;

   typedef int64_t _waypoint_type;
  _waypoint_type waypoint;




  typedef boost::shared_ptr< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> const> ConstPtr;

}; // struct CustomTrafficLight_

typedef ::styx_msgs::CustomTrafficLight_<std::allocator<void> > CustomTrafficLight;

typedef boost::shared_ptr< ::styx_msgs::CustomTrafficLight > CustomTrafficLightPtr;
typedef boost::shared_ptr< ::styx_msgs::CustomTrafficLight const> CustomTrafficLightConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::styx_msgs::CustomTrafficLight_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace styx_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'styx_msgs': ['/home/student/Documents/Final-System-Integrated/ros/src/styx_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
{
  static const char* value()
  {
    return "734ca75135f2f650f74908ee10c9f58d";
  }

  static const char* value(const ::styx_msgs::CustomTrafficLight_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x734ca75135f2f650ULL;
  static const uint64_t static_value2 = 0xf74908ee10c9f58dULL;
};

template<class ContainerAllocator>
struct DataType< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
{
  static const char* value()
  {
    return "styx_msgs/CustomTrafficLight";
  }

  static const char* value(const ::styx_msgs::CustomTrafficLight_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 state\n\
int64 waypoint\n\
";
  }

  static const char* value(const ::styx_msgs::CustomTrafficLight_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
      stream.next(m.waypoint);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CustomTrafficLight_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::styx_msgs::CustomTrafficLight_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::styx_msgs::CustomTrafficLight_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
    s << indent << "waypoint: ";
    Printer<int64_t>::stream(s, indent + "  ", v.waypoint);
  }
};

} // namespace message_operations
} // namespace ros

#endif // STYX_MSGS_MESSAGE_CUSTOMTRAFFICLIGHT_H
