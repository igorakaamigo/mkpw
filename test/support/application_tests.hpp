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

#pragma once

#include <gmock/gmock.h>
#include "../../src/application.hpp"
#include "../../src/generator.hpp"

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
            namespace Test {
                class MockGenerator : public Generator {
                public:
                    MOCK_METHOD1(generate, std::string(int length));
                };

                class MockApplication : public Application {
                public:
                    MockApplication(std::shared_ptr<Generator>);

                    int main(int argc, char *argv[]);

                    int applicationMain(std::vector<std::string> args);

                    MOCK_METHOD1(main, int(std::vector<std::string> arguments));
                };

                class ApplicationTests : public ::testing::Test {
                protected:
                    virtual void SetUp();
                    virtual void TearDown();

                protected:
                    std::shared_ptr<MockApplication> _application;
                    std::shared_ptr<MockGenerator> _generator;
                    std::shared_ptr<std::stringstream> _output;

                private:
                    std::streambuf* __prevStream;
                };
            }
        }
    }
}
