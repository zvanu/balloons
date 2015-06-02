#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\balloons\dtlibrary\SortedDynamicVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittest
{		
	TEST_CLASS(SortedDynamicVectorTest)
	{
	public:
		TEST_METHOD(addTest)
		{
			Containers::SortedDynamicVector<int> sList;
			int index;

			sList.add(5);
			sList.add(4);
			sList.add(3);
			sList.add(2);
			sList.add(1);
			sList.add(6);
			sList.add(0);
			index = 0;
			for (auto it = sList.begin(); it != sList.end(); it++)
			{
				Assert::AreEqual(*it, index);
				index++;
			}
		}

		TEST_METHOD(removeTest)
		{
			Containers::SortedDynamicVector<int> sList;
			int index;

			sList.add(5);
			sList.add(4);
			sList.add(3);
			sList.add(2);
			sList.add(1);
			sList.add(6);
			sList.add(0);
			index = 0;
			sList.removeFront();
			Assert::AreEqual(sList.getFront(), 1);
			sList.removeBack();
			Assert::AreEqual(sList.getBack(), 5);
			sList.removeAtIndex(2);
			Assert::AreEqual(sList.getAtIndex(0), 1);
			Assert::AreEqual(sList.getAtIndex(1), 2);
			Assert::AreEqual(sList.getAtIndex(2), 4);
			Assert::AreEqual(sList.getAtIndex(3), 5);
		}

		TEST_METHOD(getTest)
		{
			Containers::SortedDynamicVector<int> sList;
			int index;

			Assert::IsTrue(sList.size() == 0);
			sList.add(5);
			Assert::IsTrue(sList.size() == 1);
			sList.add(4);
			Assert::IsTrue(sList.size() == 2);
			sList.add(3);
			Assert::IsTrue(sList.size() == 3);
			sList.add(2);
			Assert::IsTrue(sList.size() == 4);
			sList.add(1);
			Assert::IsTrue(sList.size() == 5);
			sList.add(6);
			Assert::IsTrue(sList.size() == 6);
			sList.add(0);
			Assert::IsTrue(sList.size() == 7);
			for (index = 0; index < 7; index++)
			{
				Assert::AreEqual(sList.getAtIndex(index), index);
			}
			Assert::AreEqual(sList.getFront(), 0);
			Assert::AreEqual(sList.getBack(), 6);
		}

		TEST_METHOD(containsTest)
		{
			Containers::SortedDynamicVector<int> sList;

			sList.add(5);
			sList.add(4);
			sList.add(3);
			sList.add(2);
			sList.add(1);
			sList.add(6);
			sList.add(0);
			Assert::IsTrue(true == sList.contains(0));
			Assert::IsTrue(true == sList.contains(1));
			Assert::IsTrue(true == sList.contains(2));
			Assert::IsTrue(true == sList.contains(3));
			Assert::IsTrue(true == sList.contains(4));
			Assert::IsTrue(true == sList.contains(5));
			Assert::IsTrue(true == sList.contains(6));
			Assert::IsTrue(false == sList.contains(7));
			Assert::IsTrue(false == sList.contains(-1));
		}

		TEST_METHOD(clearTest)
		{
			Containers::SortedDynamicVector<int> sList;

			sList.add(5);
			sList.add(4);
			sList.add(3);
			sList.add(2);
			sList.add(1);
			sList.add(6);
			sList.add(0);
			Assert::IsTrue(true == sList.contains(0));
			Assert::IsTrue(true == sList.contains(1));
			Assert::IsTrue(true == sList.contains(2));
			Assert::IsTrue(true == sList.contains(3));
			Assert::IsTrue(true == sList.contains(4));
			Assert::IsTrue(true == sList.contains(5));
			Assert::IsTrue(true == sList.contains(6));
			sList.clear();
			Assert::IsTrue(false == sList.contains(0));
			Assert::IsTrue(false == sList.contains(1));
			Assert::IsTrue(false == sList.contains(2));
			Assert::IsTrue(false == sList.contains(3));
			Assert::IsTrue(false == sList.contains(4));
			Assert::IsTrue(false == sList.contains(5));
			Assert::IsTrue(false == sList.contains(6));
			Assert::IsTrue(0 == sList.size());
		}

		TEST_METHOD(iteratorTest)
		{
			Containers::SortedDynamicVector<int> sList;
			Containers::SortedDynamicVector<int>::Iterator it;

			it = sList.begin();
			Assert::IsTrue(true == it.hasNext());
			Assert::IsTrue(true == it.isValid());
			sList.add(0);
			sList.add(1);
			sList.add(2);
			it = sList.begin();
			Assert::IsTrue(true == it.isValid());
			Assert::IsTrue(true == it.hasNext());
			Assert::AreEqual(*it, 0);
			it++;
			Assert::AreEqual(*it, 1);
			++it;
			Assert::AreEqual(*it, 2);
			Assert::IsTrue(true == it.hasNext());
			Assert::IsFalse(it == sList.end());
			it++;
			Assert::IsTrue(it == sList.end());
			Assert::IsTrue(it != sList.begin());
		}
	};
}