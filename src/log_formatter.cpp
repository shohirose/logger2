#include "shirose/log_formatter.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

namespace shirose {

std::string DefaultLogFormatter::formatLog(LogLevel logLevel, const char* tag,
                                           const std::string& message) {
  std::stringstream ss;
  ss << '[' << getLogLevelName(logLevel) << "] ";

  using std::chrono::system_clock;
  const auto timePoint = system_clock::now();
  const auto time = system_clock::to_time_t(timePoint);
  ss << std::put_time(std::localtime(&time), "%F %T");

  ss << ' ' << tag << " [" << std::this_thread::get_id() << "] " << message
     << '\n';

  return ss.str();
}

}  // namespace shirose
