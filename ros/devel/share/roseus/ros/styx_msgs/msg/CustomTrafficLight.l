;; Auto-generated. Do not edit!


(when (boundp 'styx_msgs::CustomTrafficLight)
  (if (not (find-package "STYX_MSGS"))
    (make-package "STYX_MSGS"))
  (shadow 'CustomTrafficLight (find-package "STYX_MSGS")))
(unless (find-package "STYX_MSGS::CUSTOMTRAFFICLIGHT")
  (make-package "STYX_MSGS::CUSTOMTRAFFICLIGHT"))

(in-package "ROS")
;;//! \htmlinclude CustomTrafficLight.msg.html


(defclass styx_msgs::CustomTrafficLight
  :super ros::object
  :slots (_state _waypoint ))

(defmethod styx_msgs::CustomTrafficLight
  (:init
   (&key
    ((:state __state) 0)
    ((:waypoint __waypoint) 0)
    )
   (send-super :init)
   (setq _state (round __state))
   (setq _waypoint (round __waypoint))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:waypoint
   (&optional __waypoint)
   (if __waypoint (setq _waypoint __waypoint)) _waypoint)
  (:serialization-length
   ()
   (+
    ;; uint8 _state
    1
    ;; int64 _waypoint
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _state
       (write-byte _state s)
     ;; int64 _waypoint
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _waypoint (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _waypoint) (= (length (_waypoint . bv)) 2)) ;; bignum
              (write-long (ash (elt (_waypoint . bv) 0) 0) s)
              (write-long (ash (elt (_waypoint . bv) 1) -1) s))
             ((and (class _waypoint) (= (length (_waypoint . bv)) 1)) ;; big1
              (write-long (elt (_waypoint . bv) 0) s)
              (write-long (if (>= _waypoint 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _waypoint s)(write-long (if (>= _waypoint 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int64 _waypoint
#+(or :alpha :irix6 :x86_64)
      (setf _waypoint (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _waypoint (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get styx_msgs::CustomTrafficLight :md5sum-) "734ca75135f2f650f74908ee10c9f58d")
(setf (get styx_msgs::CustomTrafficLight :datatype-) "styx_msgs/CustomTrafficLight")
(setf (get styx_msgs::CustomTrafficLight :definition-)
      "uint8 state
int64 waypoint
")



(provide :styx_msgs/CustomTrafficLight "734ca75135f2f650f74908ee10c9f58d")


