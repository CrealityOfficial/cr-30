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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"
#include "../../sd/cardreader.h"
#include "../../module/configuration_store.h"

#if ENABLED(POWER_LOSS_RECOVERY)
  #include "../../feature/powerloss.h"
#endif

#if ENABLED(GCODE_REPEAT_MARKERS)

#include "../gcode.h"
#include "../../MarlinCore.h"

void report_M808()
{
  SERIAL_ECHOPAIR_P(PSTR(" M808 L"), repeat_markers_count);
}

/**
 * M808: M808: Repeat Markers Count menu
 *
 * Parameters
 *  L<bool>   : Repeat Markers Count
 */
void GcodeSuite::M808() 
{
  uint16_t repeat_markers_value;
  if(parser.seen('L'))
  {
    repeat_markers_value = parser.value_int();
    if((card.flag.sdprinting == true) && (recovery.info.recovery_repeat_markers_flag == false))
    {
      repeat_markers_count = repeat_markers_count;
    }
    else
    {
      repeat_markers_count = repeat_markers_value;
    }
    (void)settings.save();
  }
  return report_M808();
}

#endif // GCODE_REPEAT_MARKERS
