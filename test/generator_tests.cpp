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

#include "support/generator_tests.hpp"

namespace Amigo {
    namespace Utils {
        namespace Mkpw {
            namespace Test {
                TEST_F(GeneratorTests, ItsGenerateMethodShouldReturnAStringWithASuppliedLength) {
                    ASSERT_EQ(20, _generator->generate(20).size());
                }

                TEST_F(GeneratorTests, ItsGenerateMethodShouldReturnUniqueStrings) {
                    std::string a = _generator->generate(12);
                    std::string b = _generator->generate(12);
                    ASSERT_FALSE(a == b);
                }
            }
        }
    }
}
