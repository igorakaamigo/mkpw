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

#include "support/application_tests.hpp"

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
            namespace Test {
                using ::testing::Return;

                TEST_F(ApplicationTests, ItsMainMethodForCMainFunctionShouldReturnMainMethodWithVector) {
                    const char* args[] = { "executable path", "first arg", "second arg" };

                    EXPECT_CALL(*_application, main(std::vector<std::string>({ "executable path", "first arg", "second arg" })))
                        .WillOnce(Return(123));
                    int result = _application->main(3, const_cast<char**>(args));

                    ASSERT_EQ(123, result);
                }

                TEST_F(ApplicationTests, ItsMainMethodShouldReturnZeroForParamlessApplicationCall) {
                    int result = _application->applicationMain(std::vector<std::string>({ "executable path" }));
                    ASSERT_EQ(0, result);
                }

                TEST_F(ApplicationTests, ItsMainMethodShouldRespondToHelpCommand) {
                    std::string expected = "Allowed options:\n"
                                           "\n"
                                           "Generic options:\n"
                                           "  -H [ --help ]             Print Help (this message) and exit\n"
                                           "  -V [ --version ]          Print version information and exit\n"
                                           "\n"
                                           "Configuration:\n"
                                           "  -L [ --length ] arg (=8)  Password length\n";

                    int result = _application->applicationMain(std::vector<std::string>({ "executable path", "--help" }));
                    ASSERT_EQ(expected, _output->str());
                    ASSERT_EQ(0, result);
                }

                TEST_F(ApplicationTests, ItsMainMethodShouldRespondToVersionCommand) {
                    std::string expected = "mkpv - a simple password generation utility v0.1.0\n";
                    int result = _application->applicationMain(std::vector<std::string>({ "executable path", "--version" }));
                    ASSERT_EQ(expected, _output->str());
                    ASSERT_EQ(0, result);
                }

                TEST_F(ApplicationTests, ItsMainMethodShouldWriteTheResultOfGenerateCall) {
                    EXPECT_CALL(*_generator, generate(20))
                        .WillOnce(Return(std::string("12345678901234567890")));
                    _application->applicationMain(std::vector<std::string>({ "executable path", "--length=20" }));
                    ASSERT_EQ("12345678901234567890\n", _output->str());
                }
            }
        }
    }
}
