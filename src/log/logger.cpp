/**
 * @file logger.cpp
 * @author Manuel Rocca
 * @brief Source file for the Logger class
 * @date 2025
 */

#include "logger.hpp"


// #### Static Members ####
std::unique_ptr<Logger> Logger::instance_ = nullptr;
std::ofstream Logger::logFile_;

std::string getDate() {
  const time_t now = time(nullptr);
  const tm *localTime = localtime(&now);

  std::ostringstream oss;
  oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

// #### Logger Singleton ####
Logger::Logger() = default;

Logger &Logger::getInstance(const std::string &path) {
  if (!instance_) {
    instance_ = std::unique_ptr<Logger>(new Logger());
    if (!path.empty()) {

      const std::string date = getDate();
      const std::string filename = path + date + ".log";

      Logger::logFile_.open(filename, std::ios::app);
      if (!Logger::logFile_.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
      }
    } else {
      Logger::logFile_.open(path + "arkanoid.log", std::ios::app);
    }
  }
  return *instance_;
}

Logger::~Logger() {
  if (logFile_.is_open()) {
    logFile_.close();
  }
}

void Logger::log(const std::string &message) {
  if (logFile_.is_open()) {
    logFile_ << message << std::endl;
  }
}
