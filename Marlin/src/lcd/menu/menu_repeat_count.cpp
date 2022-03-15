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

//
// Configuration Menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU

#include "../../module/configuration_store.h"
#include "menu.h"

uint16_t repeat_markers_count;
void menu_repeat_markers()
{
  START_MENU();
  BACK_ITEM(MSG_MAIN);

  #if GCODE_REPEAT_MARKERS
    EDIT_ITEM(uint16_3, MSG_REPEAT_MARKERS_COUNT, &repeat_markers_count, 0, 999);
  #endif

  #if ENABLED(EEPROM_SETTINGS)
    ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);
  #endif

  END_MENU();
}

#endif // HAS_LCD_MENU
