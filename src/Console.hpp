/**
 * Hello Git - Voice Interaction Program for Git Repositories
 * Copyright 2015 Jamison Bryant
 *
 * Console Class Header
 * (see Console.cpp for more details)
 *
 * Author:  Jamison Bryant (robojamison@gmail.com)
 * Website: https://github.com/robojamison/hello-git
 * License: MIT
 */

#include <string>

class Console {
 public:
  static void printError(std::string text);
  static void printMessage(std::string text);
};
