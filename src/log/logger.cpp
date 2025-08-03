/**
 * @file logger.cpp
 * @author Manuel Rocca
 * @brief Source file for the Logger class.
 * @date 2025
 */

// #### Internal Includes ####
#include "logger.hpp"

// #### C++ Includes ####
// STD
#include <ctime>
#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

// #### Static Members ####
unique_ptr<Logger> Logger::instance_ = nullptr;
ofstream Logger::logFile_;

string getDate() {
  const time_t now = time(nullptr);
  const tm *localTime = localtime(&now);

  ostringstream oss;
  oss << put_time(localTime, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

// #### Logger Singleton ####
Logger::Logger() = default;

Logger &Logger::getInstance(const string &path) {
  if (!instance_) {
    instance_ = unique_ptr<Logger>(new Logger());
    if (!path.empty()) {

      const string date = getDate();
      const string filename = path + date + ".log";

      Logger::logFile_.open(filename, ios::app);
      if (!Logger::logFile_.is_open()) {
        throw runtime_error("Failed to open log file: " + filename);
      }
    } else {
      Logger::logFile_.open(path + "arkanoid.log", ios::app);
    }
  }
  return *instance_;
}

Logger::~Logger() {
  if (logFile_.is_open()) {
    logFile_.close();
  }
}

void Logger::log(const string &message) {
  if (logFile_.is_open()) {
    logFile_ << message << endl;
  }
}
