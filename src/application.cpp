/**
 * MIT License
 *
 * Copyright (c) 2018 Igor M Osipov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include "application.hpp"

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
            int Application::main(int argc, char *argv[]) {
                return main(std::vector<std::string>(argv, argv + argc));
            }

            Application::Application(std::shared_ptr<Generator> g) : _options("Allowed options"), _generator(g) {
                namespace bpo = boost::program_options;

                bpo::options_description generic("Generic options");
                generic.add_options()
                        ("help,H", "Print Help (this message) and exit")
                        ("version,V", "Print version information and exit");

                bpo::options_description configuration("Configuration");
                configuration.add_options()
                        ("length,L", bpo::value<int>(&_passwordLength)->default_value(8), "Password length");

                _options
                        .add(generic)
                        .add(configuration);
            }

            void Application::parseCommandLine(std::vector<std::string> args) {
                namespace bpo = boost::program_options;

                bpo::store(bpo::command_line_parser(args).options(_options).run(), _variables);
                bpo::notify(_variables);
            }

            int Application::main(std::vector<std::string> args) {
                parseCommandLine(args);

                if (_variables.count("help")) {
                    std::cout << _options;
                    return 0;
                }

                if (_variables.count("version")) {
                    std::cout << "mkpv - a simple password generation utility v0.1.0" << std::endl;
                    return 0;
                }

                std::cout << _generator->generate(_passwordLength) << std::endl;
                return 0;
            }
        }
    }
}
