#ifndef __TIME_H__
#define __TIME_H__

enum class Wakeup {
  IMMEDIATE = 1,
  LATER_MIN = 2,
  LATER_AT_TIME = 3,
};

enum class TError {
  STALE_TIME
};

const char SEPARATOR = ':';
struct Time {
 public:
  // convert given h,m,s in hh::mm::ss
  // needs an argcheck too
  explicit Time (char const* argTime);
  uint32_t getTime();
 private:
  Wakeup getWakeupType(const std::string& sArgTime);
  void setImmediateTime();
  void setTimeInMinutes(const std::string& sArgTime);
  void setFormattedTime(const std::string& sArgTime);
  uint32_t convertToMinutes();
  void setHours(const uint32_t& hours);
  void setMinutes(const uint32_t& minutes);
  void setSeconds(const uint32_t& seconds);
  void handleError(const TError error);
  uint32_t hours_;
  uint32_t minutes_;
  uint32_t seconds_;
  uint32_t wakeupTime_;
};

#endif // __TIME_H__
