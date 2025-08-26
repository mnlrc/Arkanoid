/**
 * @file logger.cpp
 * @author Manuel Rocca
 * @brief Source file for the Logger class
 * @date 2025
 */

#include "logger.hpp"

// #### Static Members ####
std::unique_ptr<Logger> Logger::instance_ = nullptr;
std::ofstream Logger::log_file_;

std::string get_date()
{
  const time_t now = time(nullptr);
  const tm *localTime = localtime(&now);

  std::ostringstream oss;
  oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

// #### Logger Singleton ####
Logger::Logger() = default;

Logger &Logger::get_instance(const std::string &path)
{
  if (!instance_)
  {
    instance_ = std::unique_ptr<Logger>(new Logger());
    if (!path.empty())
    {

      const std::string date = get_date();
      const std::string filename = path + date + ".log";

      Logger::log_file_.open(filename, std::ios::app);
      if (!Logger::log_file_.is_open())
      {
        throw std::runtime_error("Failed to open log file: " + filename);
      }
    }
    else
    {
      Logger::log_file_.open(path + "arkanoid.log", std::ios::app);
    }
  }
  return *instance_;
}

Logger::~Logger()
{
  if (log_file_.is_open())
  {
    log_file_.close();
  }
}

void Logger::log(const std::string &message)
{
  if (log_file_.is_open())
  {
    log_file_ << message << std::endl;
  }
}
