/*
        Copyright 2022  Devin Rockwell

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
extern Mango::Application* Mango::CreateApplication();


int main(int argc, char** argv) {
    auto app = Mango::CreateApplication();
    
    app->Run();

    delete app;
    return 0;
}
#else
extern Mango::Application* Mango::CreateApplication();

int main(int argc, char** argv) {
    auto app = Mango::CreateApplication();
    
    app->Run();

    delete app;
    return 0;
}
#endif