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

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Mango {
    class MANGO_API Log {
    public:
        static void Init();

    static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}


// Core log macros
#define MG_CORE_TRACE(...)    ::Mango::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MG_CORE_INFO(...)     ::Mango::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MG_CORE_WARN(...)     ::Mango::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MG_CORE_ERROR(...)    ::Mango::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MG_CORE_CRITICAL(...) ::Mango::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MG_TRACE(...)         ::Mango::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MG_INFO(...)          ::Mango::Log::GetClientLogger()->info(__VA_ARGS__)
#define MG_WARN(...)          ::Mango::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MG_ERROR(...)         ::Mango::Log::GetClientLogger()->error(__VA_ARGS__)
#define MG_CRITICAL(...)      ::Mango::Log::GetClientLogger()->critical(__VA_ARGS__)