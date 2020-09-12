// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018-2019, 2ACoin Developers
//
// Please see the included LICENSE file for more information

#pragma once

#include <string>

const std::string windowsAsciiArt =
"\n                                                  \n"
  "___  ___                                  _       \n"
  "|  \/  |                                 (_)      \n"
  "| .  . | __ _ _ __   __ _  ___   ___ ___  _ _ __  \n"
  "| |\/| |/ _` | '_ \ / _` |/ _ \ / __/ _ \| | '_ \ \n"
  "| |  | | (_| | | | | (_| | (_) | (_| (_) | | | | |\n"
  "\_|  |_/\__,_|_| |_|\__, |\___/ \___\___/|_|_| |_|\n"
  "                    __/ |                         \n"
  "                    |___/                         \n";

const std::string nonWindowsAsciiArt =
"\n                                                  \n"
  "___  ___                                  _       \n"
  "|  \/  |                                 (_)      \n"
  "| .  . | __ _ _ __   __ _  ___   ___ ___  _ _ __  \n"
  "| |\/| |/ _` | '_ \ / _` |/ _ \ / __/ _ \| | '_ \ \n"
  "| |  | | (_| | | | | (_| | (_) | (_| (_) | | | | |\n"
  "\_|  |_/\__,_|_| |_|\__, |\___/ \___\___/|_|_| |_|\n"
  "                    __/ |                         \n"
  "                    |___/                         \n";

/* Windows has some characters it won't display in a terminal. If your ascii
   art works fine on Windows and Linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32

const std::string asciiArt = windowsAsciiArt;

#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif
