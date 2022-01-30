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
#include "Events/Event.h"
#include "Mango/Events/ApplicationEvent.h"

#include "Window.h"

namespace Mango {

    class MANGO_API Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
	private:
        bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
    };

    // To be defined by client
    Application* CreateApplication();

}