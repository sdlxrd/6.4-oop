#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\6.4 oop\6.4 oop\6.4 oop.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vector<int> V(5);
			V.five(0);
			Assert::AreEqual(true, V.Task());
		}
	};
}
