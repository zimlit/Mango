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

#include <Mango.h>

class ExampleLayer : public Mango::Layer {
public:
    ExampleLayer()
        : Layer("Example") {}

    void OnUpdate() override {
        MG_INFO("ExampleLayer::Update");
    }

    void OnEvent(Mango::Event& event) override {
        MG_TRACE("{0}", event);
    }
};

class Sandbox : public Mango::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {

    }
};

Mango::Application* Mango::CreateApplication() {
    return new Sandbox();
}