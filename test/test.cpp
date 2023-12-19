#include "pch.h"
#include "CppUnitTest.h"
#include "..\\ConsoleApplication1\Data.h"
#include "..\\ConsoleApplication1\Nedv.h"
#include "..\\ConsoleApplication1\Price.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
    TEST_CLASS(test)
    {
    public:

        TEST_METHOD(TestReadDate1)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "25.13.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate2)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "35.07.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate3)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "13.11.2025" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate4)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "13.07" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate5)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "11,11,2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate6)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "31.11.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate7)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "32.07.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate8) // в высокосном году, в феврале 29 дней
        {
            const auto func = [] {
                auto sin = std::istringstream{ "29.02.2000" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadName1)
        {
            try {
                auto sin = std::istringstream{ "fedchenko" };
                string owner;
                sin >> owner;
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            }

        }

        TEST_METHOD(TestReadName2)
        {
            try {
                auto sin = std::istringstream{ "FEdchenko" };
                string owner;
                sin >> owner;
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            }
        }

        TEST_METHOD(TestReadName3)
        {
            try {
                auto sin = std::istringstream{ "Fe5dchenko" };
                string owner;
                sin >> owner;
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            }
        }

        TEST_METHOD(TestReadName4)
        {
            try {
                auto sin = std::istringstream{ "FEDCHENKO" };
                string owner;
                sin >> owner;
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadName5)
        {
            try {
                auto sin = std::istringstream{ "F2134" };
                string owner;
                sin >> owner;
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            }
        }

        TEST_METHOD(TestReadSum1)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "-432432432" };
                Price price;
                sin >> price;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }
    };
}
