#include <iostream>
#include "application.hpp"

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
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

            int Application::main(std::vector<std::string> params) {
                if (params.size() == 0) {
                    return execute();
                }

                return help();
            }

            int Application::execute() {
                std::cout << "Application::execute()" << std::endl;
                return 0;
            }

            int Application::help() {
                std::cout
                        << "mkpw - a simple password generation utility"
                        << std::endl
                        << std::endl
                        << "usage: mkpw [arguments]"
                        << std::endl
                        << std::endl
                        << "Arguments:"
                        << std::endl
                        << "\t(none implemented yet)"
                        << std::endl;

                return 0;
            }
        }
    }
}
