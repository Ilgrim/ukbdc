/* This file is part of ukbdc.
 *
 * ukbdc is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ukbdc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ukbdc; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "io.h"
#include "io_impl.h"

#include <stdbool.h>

bool IO_get(uint8_t pin)
{
	if (pin & 0x80)
		return IO_get_external(pin);
	else
		return IO_get_internal(pin);
}

void IO_set(uint8_t pin, bool val)
{
	if (pin & 0x80)
		IO_set_external(pin, val);
	else
		IO_set_internal(pin, val);
}

void IO_config(uint8_t pin, bool dir)
{
	if (pin & 0x80)
		IO_config_external(pin, dir);
	else
		IO_config_internal(pin, dir);
}
