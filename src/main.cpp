#include "application.hpp"

int main(int argc, char *argv[]) {
    Amigo::Utils::Mkpw::Application::instance().main(
            std::vector<std::string>(argv + 1, argv + argc)
    );
}
