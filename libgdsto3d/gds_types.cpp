/*
 * File: gds_types.cpp
 * Author: Roger Light
 * Project: gdsto3d
 *
 * This file contains Windows specific byte swapping code.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */


/* Win32 specific byte swapping code */

long endian_swap_long(long value)
{
	_asm{
		mov eax,value
		bswap eax
		mov value,eax
	}
	return value;
}

short endian_swap_short(short value)
{
	_asm{
		mov ax,value
		xchg ah,al
		mov value,ax
	}
	return value;
}

