/**
 * Hello Git - Voice Interaction Program for Git Repositories
 * Copyright 2015 Jamison Bryant
 *
 * Listener Class
 * Listens to the user's input and performs the appropriate action
 *
 * Author:  Jamison Bryant (robojamison@gmail.com)
 * Website: https://github.com/robojamison/hello-git
 * License: MIT
 */

// C++ includes
#include <iostream>
#include <string.h>

// Library includes
#include <voce.h>

// Project includes
#include "Listener.hpp"

Listener::Listener() {
  std::cout << "Listener invoked" << std::endl;

  // Initialize voice synthesis
  voce::init("lib/voce/lib", true, false, "", "");
  voce::synthesize("Listener initialized");
  voce::destroy();
}

Listener::~Listener() {
  std::cout << "Listener destroyed" << std::endl;
}
