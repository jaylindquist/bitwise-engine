#include <BitwiseEngine/Object.h>
#include <UnitTest++/UnitTest++.h>
#include <sstream>

using namespace BitwiseEngine;
unsigned int firstID = 0;


SUITE(ObjectTestSuite)
{
	TEST(ToStringEqualsObject)
	{
		using namespace std;

#pragma warning(push)
#pragma warning(disable:4311) // disable pointer truncation warning

		Object obj;
		stringstream objStr;
		objStr << "Object (0x" << hex << reinterpret_cast<unsigned int>(&obj) << dec << ")";

		CHECK_EQUAL(objStr.str(), obj.ToString());

		firstID = obj.GetID();

#pragma warning(pop)
	}

	TEST(InheritedToStringEqualsObject)
	{
		using namespace std;

#pragma warning(push)
#pragma warning(disable:4311) // disable pointer truncation warning

		class ChildObject : public Object
		{
		public:

		};

		Object obj;
		stringstream objStr;
		objStr << "Object (0x" << hex << reinterpret_cast<unsigned int>(&obj) << dec << ")";

		CHECK_EQUAL(objStr.str(), obj.ToString());

#pragma warning(pop)
	}

	TEST(OverriddenToStringEqualsChild)
	{
		class ChildObject : public Object
		{
		public:
			virtual std::string ToString() { return "Child"; }
		};

		ChildObject obj;
		std::stringstream objStr;
		objStr << "Child";

		CHECK_EQUAL(objStr.str(), obj.ToString());
	}

	TEST(GetIDEqualsThree)
	{
		Object obj;
		CHECK_EQUAL(firstID + 3, obj.GetID());
	}

	TEST(ReferenceCountIncremented)
	{
		Object* obj = new Object();
		CHECK_EQUAL(0, obj->GetRefs());

		obj->AddRef();
		CHECK_EQUAL(1, obj->GetRefs());

		delete obj;
	}

	TEST(ReferenceCountDecremented)
	{
		Object* obj = new Object();
		obj->AddRef();
		obj->AddRef();
		CHECK_EQUAL(2, obj->GetRefs());
		
		obj->RemoveRef();
		CHECK_EQUAL(1, obj->GetRefs());

		delete obj;
	}

	TEST(ObjectDeletionOnReferenceDecrement)
	{
		Object* obj = new Object();
		obj->AddRef();
		obj->RemoveRef();

		try
		{
			// obj deleted when last reference removed
			delete obj;
			CHECK(false);
		}
		catch(...)
		{
			CHECK(true);
		}
	}
}