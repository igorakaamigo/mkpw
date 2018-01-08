#pragma once

#include <vector>
#include <string>

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
            class Application {
            public:
                static Application &instance();

                int main(std::vector<std::string>);

            protected:
                virtual int execute();

            protected:
                Application();

                Application(const Application &);

                ~Application();

                Application &operator=(const Application &);
            };
        }
    }
}
