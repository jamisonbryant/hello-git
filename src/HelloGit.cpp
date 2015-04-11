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
#include <stdlib.h>
#include <string>

// Library includes
#include <libconfig.h++>

// Project includes
#include "Console.hpp"

// Namespaces
using namespace libconfig;

int main() {
  // Load config file
  Config config_file;

  try {
    config_file.readFile("cfg/default.cfg");
  } catch(const FileIOException &ex) {
    Console::printError("Exception occurred while reading config file");
    return EXIT_FAILURE;
  } catch(const ParseException &ex) {
    Console::printError("Exception occurred while reading config file");
    return EXIT_FAILURE;
  }

  // Get version number
  try {
    std::string version = config_file.lookup("version");
    std::cout << "Hello Git v" << version << std::endl;
  } catch(const SettingNotFoundException &ex) {
    Console::printError("Exception occurred while getting version number");
    return EXIT_FAILURE;
  }
}
