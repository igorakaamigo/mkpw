#include <iostream>
#include "application.hpp"

namespace Amigo::Utils::Mkpw {
    Application::Application() {}

    Application::Application(const Application &) {}

    Application::~Application() {}

    Application &Application::operator=(const Application &) {
        return *this;
    }

    Application &Application::instance() {
        static Application instance;
        return instance;
    }

    int Application::main(std::vector<std::string>) {
        return execute();
    }

    int Application::execute() {
        std::cout << "Application::execute()" << std::endl;
        return 0;
    }
}
