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

  // Test pocketsphinx
  ps_decoder_t *ps;
  cmd_ln_t *config;
  FILE *fh;
  char const *hyp, *uttid;
  int16 buf[512];
  int rv;
  int32 score;

  config = cmd_ln_init(NULL, ps_args(), TRUE,
                       "-hmm", "/usr/local/share/pocketsphinx/model/en-us/en-us",
                       "-lm", "/usr/local/share/pocketsphinx/model/en-us/en-us.lm.dmp",
                       "-dict", "/usr/local/share/pocketsphinx/model/en-us/cmudict-en-us.dict",
                       NULL);

  ps = ps_init(config);

  if (ps == NULL)
    std::cout << "Error: ps was null" << std::endl;

  //  fh = fopen("lib/pocketsphinx/test/data/goforward.raw", "rb");
  fh = fopen("etc/buffalo.wav", "rb");

  if (fh == NULL)
    std::cout << "Error: file handle was null" << std::endl;

  rv = ps_start_utt(ps);

  if (rv < 0)
    std::cout << "Error: rv < 0" << std::endl;

  while (!feof(fh)) {
    size_t nsamp;
    nsamp = fread(buf, 2, 512, fh);
    rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
  }

  rv = ps_end_utt(ps);

  if (rv < 0)
    std::cout << "Error: rv < 0" << std::endl;

  hyp = ps_get_hyp(ps, &score);

  if (hyp == NULL)
    std::cout << "Error: Hyp was null" << std::endl;

  printf("Recognized: %s\n", hyp);

  fclose(fh);
  ps_free(ps);
  cmd_ln_free_r(config);
}

Listener::~Listener() {
  std::cout << "Listener destroyed" << std::endl;
}
