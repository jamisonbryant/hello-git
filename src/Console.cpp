/**
 * Hello Git - Voice Interaction Program for Git Repositories
 * Copyright 2015 Jamison Bryant
 *
 * Console Class
 * Convenience class for printing messages/errors to the console.
 *
 * Author:  Jamison Bryant (robojamison@gmail.com)
 * Website: https://github.com/robojamison/hello-git
 * License: MIT
 */

#include "Console.hpp"
#include <iostream>
#include <string>

void Console::printError(std::string text) {
  std::cout << text << std::endl;
}

void Console::printMessage(std::string text) {
  std::cerr << text << std::endl;
}
