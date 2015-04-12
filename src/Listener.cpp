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
//#include <voce.h>
#include <pocketsphinx.h>

// Project includes
#include "Listener.hpp"

Listener::Listener() {
  std::cout << "Listener invoked" << std::endl;

  // Initialize voice synthesis
  //voce::init("lib/voce/lib", true, false, "", "");
  //voce::synthesize("Listener initialized");
  //voce::destroy();

  // Test pocketsphinx
  ps_decoder_t *ps;
  cmd_ln_t *config;

  config = cmd_ln_init(NULL, ps_args(), TRUE,
                       "-hmm", "/usr/local/share/pocketsphinx/model/en-us/en-us",
                       "-lm", "/usr/local/share/pocketsphinx/model/en-us/en-us.lm.dmp",
                       "-dict", "/usr/local/share/pocketsphinx/model/en-us/cmudict-en-us.dict",
                       NULL);

  ps = ps_init(config);
  if (ps == NULL)
    std::cout << "error" << std::endl;
}

Listener::~Listener() {
  std::cout << "Listener destroyed" << std::endl;
}
