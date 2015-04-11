/**
 * Hello Git - Voice Interaction Program for Git Repositories
 * Copyright 2015 Jamison Bryant
 *
 * Main Class
 * Launches the application and begins the voice interaction.
 *
 * Author:  Jamison Bryant (robojamison@gmail.com)
 * Website: https://github.com/robojamison/hello-git
 * License: MIT
 */

// C++ includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Library includes
#include <libconfig.h++>

// Namespaces
using namespace libconfig;

int main() {
  // Load config file
  Config config_file;

  try {
    config_file.readFile("cfg/default.cfg");
  } catch(const FileIOException &ex) {
    std::cout << "ERROR: FileIOException occurred while trying to read " 
              << "config file" << std::endl;
    return EXIT_FAILURE;
  } catch(const ParseException &ex) {
    std::cout << "ERROR: ParseException occurred while trying to read " 
              << "config file" << std::endl;
    return EXIT_FAILURE;
  }

  // Get version number
  std::string version;

  try {
    version = std::string(config_file.lookup("version").c_str());
  } catch(const SettingNotFoundException &ex) {
    std::cout << "ERROR: SettingNotFoundException occurred while trying to "
              << "get setting from config file" << std::endl;
    return EXIT_FAILURE;
  }

  // Print header
  std::cout << version << std::endl;
}
