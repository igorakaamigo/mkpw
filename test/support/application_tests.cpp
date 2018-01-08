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

#include "application_tests.hpp"

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
            namespace Test {
                MockApplication::MockApplication(std::shared_ptr<Generator> g) : Application(g) {}

                int MockApplication::main(int argc, char *argv[]) {
                    return Application::main(argc, argv);
                }

                int MockApplication::applicationMain(std::vector<std::string> args) {
                    return Application::main(args);
                }

                void ApplicationTests::SetUp() {
                    _generator = std::make_shared<MockGenerator>();
                    _application = std::make_shared<MockApplication>(_generator);
                    _output = std::make_shared<std::stringstream>();
                    __prevStream = std::cout.rdbuf(_output->rdbuf());
                }

                void ApplicationTests::TearDown() {
                    std::cout.rdbuf(__prevStream);
                    _output = NULL;
                    _application = NULL;
                    _generator = NULL;
                }
            }
        }
    }
}
