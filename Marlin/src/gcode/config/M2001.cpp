/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../gcode.h"
#include "../../MarlinCore.h" // for startOrResumeJob

#include "../../sd/cardreader.h"
#include "../../inc/MarlinConfig.h"


#if ENABLED(LEANTRONIC)
/*
 * M2001:
 */

void GcodeSuite::M2001() {

  static uint16_t total_samples = 1;
  static uint16_t count_samples = 0;

  if (parser.seenval('S')) total_samples = parser.value_int();
  if (parser.seenval('C')) count_samples = parser.value_int();

  if (count_samples > total_samples) {

      if (IS_SD_PRINTING()){
        card.flag.abort_sd_printing = true;         //Abort the current SD print job (started with M24)
        }

      count_samples = 0;
  }

  //if (parser.seen("SC")) {
      //SERIAL_ECHO_START();
      //SERIAL_CHAR("S:");
      //SERIAL_ECHO(total_samples);
      //SERIAL_CHAR(" C:");
      //SERIAL_ECHO(count_samples);
      //SERIAL_EOL();
  //}

}

#endif // LEANTRONIC