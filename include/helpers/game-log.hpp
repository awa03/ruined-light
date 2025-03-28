#ifndef GAME_LOG_HPP
#define GAME_LOG_HPP

#include <fstream>
#include <iostream>
#include <mutex>
#include <stdexcept>

#define SPACING " | "
int log_counter;

class LogFile {
 private:
  static std::mutex log_mutex;
  static constexpr const char* LOG_FILE = "game_log.txt"; 

 public:
  static void SetCounter(int new_count = 0) {
    log_counter = new_count;
  }

  static bool WriteLog(const std::string& write_text) {
    std::lock_guard<std::mutex> lock(log_mutex); 

    try {
      std::ofstream log_file(LOG_FILE, std::ios::app); 
      if (!log_file) {
        throw std::runtime_error("Failed to open log file.");
      }

      log_file << log_counter << SPACING << write_text << "\n";
      log_file.close();
    } 
    catch (const std::exception& e) {
      std::cerr << "Error writing to log file: " << e.what() << std::endl;
      return false;
    }
    
    log_counter++;

    return true;
  }
};

std::mutex LogFile::log_mutex;

#endif 

