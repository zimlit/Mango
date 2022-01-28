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

#include "mgpch.h"
#include "Application.h"
#include "Mango/Events/ApplicationEvent.h"
#include "Mango/Log.h"

namespace Mango {

    Application::Application() {
        
    }

    Application::~Application() {

    }

    void Application::Run() {
        WindowResizeEvent e(1280,720);
        MG_TRACE(e);

        while (true);
    }
}