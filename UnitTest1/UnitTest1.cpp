
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61REK
{
    TEST_CLASS(UnitTest61REK)
    {
    public:

        // Рекурсивний підрахунок кількості
        int Count(int a[], int n, int i)
        {
            if (i >= n)
                return 0;

            if (a[i] < 0 || a[i] % 2 != 0)
                return 1 + Count(a, n, i + 1);

            return Count(a, n, i + 1);
        }

        TEST_METHOD(TestCount1)
        {
            int a[] = { -4, 2, 7, -3, 0, 8 };
            Assert::AreEqual(3, Count(a, 6, 0));
        }

        TEST_METHOD(TestCount2)
        {
            int a[] = { 2, 4, 6, 8, 10 };
            Assert::AreEqual(0, Count(a, 5, 0));
        }

        TEST_METHOD(TestCount3)
        {
            int a[] = { -5, -2, 3, 7, -8 };
            Assert::AreEqual(5, Count(a, 5, 0));
        }

        TEST_METHOD(TestCount4)
        {
            int a[] = { 0, 1, 2, 3, 4, 5 };
            Assert::AreEqual(3, Count(a, 6, 0));
        }
    };
}
