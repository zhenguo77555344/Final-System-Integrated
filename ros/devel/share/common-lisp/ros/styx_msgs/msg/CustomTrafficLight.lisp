; Auto-generated. Do not edit!


(cl:in-package styx_msgs-msg)


;//! \htmlinclude CustomTrafficLight.msg.html

(cl:defclass <CustomTrafficLight> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0)
   (waypoint
    :reader waypoint
    :initarg :waypoint
    :type cl:integer
    :initform 0))
)

(cl:defclass CustomTrafficLight (<CustomTrafficLight>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CustomTrafficLight>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CustomTrafficLight)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name styx_msgs-msg:<CustomTrafficLight> is deprecated: use styx_msgs-msg:CustomTrafficLight instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <CustomTrafficLight>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader styx_msgs-msg:state-val is deprecated.  Use styx_msgs-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'waypoint-val :lambda-list '(m))
(cl:defmethod waypoint-val ((m <CustomTrafficLight>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader styx_msgs-msg:waypoint-val is deprecated.  Use styx_msgs-msg:waypoint instead.")
  (waypoint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CustomTrafficLight>) ostream)
  "Serializes a message object of type '<CustomTrafficLight>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'waypoint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CustomTrafficLight>) istream)
  "Deserializes a message object of type '<CustomTrafficLight>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'waypoint) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CustomTrafficLight>)))
  "Returns string type for a message object of type '<CustomTrafficLight>"
  "styx_msgs/CustomTrafficLight")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CustomTrafficLight)))
  "Returns string type for a message object of type 'CustomTrafficLight"
  "styx_msgs/CustomTrafficLight")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CustomTrafficLight>)))
  "Returns md5sum for a message object of type '<CustomTrafficLight>"
  "734ca75135f2f650f74908ee10c9f58d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CustomTrafficLight)))
  "Returns md5sum for a message object of type 'CustomTrafficLight"
  "734ca75135f2f650f74908ee10c9f58d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CustomTrafficLight>)))
  "Returns full string definition for message of type '<CustomTrafficLight>"
  (cl:format cl:nil "uint8 state~%int64 waypoint~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CustomTrafficLight)))
  "Returns full string definition for message of type 'CustomTrafficLight"
  (cl:format cl:nil "uint8 state~%int64 waypoint~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CustomTrafficLight>))
  (cl:+ 0
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CustomTrafficLight>))
  "Converts a ROS message object to a list"
  (cl:list 'CustomTrafficLight
    (cl:cons ':state (state msg))
    (cl:cons ':waypoint (waypoint msg))
))
