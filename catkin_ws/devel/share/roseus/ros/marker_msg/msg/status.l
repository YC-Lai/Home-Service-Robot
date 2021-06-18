;; Auto-generated. Do not edit!


(when (boundp 'marker_msg::status)
  (if (not (find-package "MARKER_MSG"))
    (make-package "MARKER_MSG"))
  (shadow 'status (find-package "MARKER_MSG")))
(unless (find-package "MARKER_MSG::STATUS")
  (make-package "MARKER_MSG::STATUS"))

(in-package "ROS")
;;//! \htmlinclude status.msg.html


(defclass marker_msg::status
  :super ros::object
  :slots (_status _x _y _w ))

(defmethod marker_msg::status
  (:init
   (&key
    ((:status __status) "")
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:w __w) 0.0)
    )
   (send-super :init)
   (setq _status (string __status))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _w (float __w))
   self)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:w
   (&optional __w)
   (if __w (setq _w __w)) _w)
  (:serialization-length
   ()
   (+
    ;; string _status
    4 (length _status)
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _w
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _status
       (write-long (length _status) s) (princ _status s)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _w
       (sys::poke _w (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _status
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _status (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _w
     (setq _w (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get marker_msg::status :md5sum-) "0e04b4c545b887ef56c6688a5b36a345")
(setf (get marker_msg::status :datatype-) "marker_msg/status")
(setf (get marker_msg::status :definition-)
      "string status
float64 x
float64 y
float64 w
")



(provide :marker_msg/status "0e04b4c545b887ef56c6688a5b36a345")


