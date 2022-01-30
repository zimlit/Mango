/*
        Copyright 2022  Devin Rockwell

    This file is part of Mango.

    Mango is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Mango is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Mango.  If not, see <https://www.gnu.org/licenses/>.    
*/

#pragma once

#ifdef MG_PLATFORM_WINDOWS
    #ifdef MG_BUILD_DLL
        #define MANGO_API __declspec(dllexport)
    #else
        #define MANGO_API __declspec(dllimport)
    #endif

    #ifdef MG_ENABLE_ASSERTS
        #define MG_ASSERT(x, ...) { if(!(x)) { MG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
        #define MG_CORE_ASSERT(x, ...) { if(!(x)) { MG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #else
        #define MG_ASSERT(x, ...)
        #define MG_CORE_ASSERT(x, ...)
    #endif
#else
    #ifdef MG_ENABLE_ASSERTS
        #define MG_ASSERT(x, ...) { if(!(x)) { MG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
        #define MG_CORE_ASSERT(x, ...) { if(!(x)) { MG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
    #else
        #define MG_ASSERT(x, ...)
        #define MG_CORE_ASSERT(x, ...)
    #endif

    #define MANGO_API
#endif

#define BIT(x) 1 << x
