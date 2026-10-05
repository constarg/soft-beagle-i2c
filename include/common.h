/**
 * File: common.h
 *
 ***********************************************************************
 * Copyright (C) 2026  Constantinos Argyriou
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
 * Email: constarg@pm.me
 ***********************************************************************
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#define CAT_(a, b) a##b
#define CAT(a, b)  CAT_(a, b)

#define RESERVED(from, to) uint8_t CAT(reserved_, __LINE__)[(to) - (from)]

#define __IO volatile

#endif  // __COMMON_H__
