#include <BitwiseEngine/Object.h>
#include <BitwiseEngine/RefPtr.h>
#include <UnitTest++/UnitTest++.h>


using namespace BitwiseEngine;

SUITE(RefPtrTestSuite)
{
	TEST(AquirePointerFromPointer)
	{
		Object* obj = new Object();
		RefPtr<Object> ref(obj);
		
		CHECK_EQUAL(obj->GetID(), ref->GetID());
	}
	
	TEST(AquirePointerFromRef)
	{
		Object* obj = new Object();
		RefPtr<Object> ref1(obj);
		RefPtr<Object> ref2(ref1);

		CHECK_EQUAL(obj->GetID(), ref2->GetID());
	}

	TEST(ReturnPointerFromAssignment)
	{
		RefPtr<Object> ref(new Object());
		Object* obj = ref;

		CHECK_EQUAL(obj->GetID(), ref->GetID());
	}

	TEST(ReturnObjectFromDereference)
	{
		RefPtr<Object> ref(new Object());
		Object obj = *ref;

		CHECK_EQUAL(obj.GetID(), ref->GetID());
	}

	TEST(AssignmentFromPointer)
	{
		RefPtr<Object> ref;
		Object* obj = new Object();
		ref = obj;

		CHECK_EQUAL(obj->GetID(), ref->GetID());
	}

	TEST(AssignmentFromRef)
	{
		RefPtr<Object> ref1(new Object());
		RefPtr<Object> ref2;
		ref2 = ref1;

		CHECK_EQUAL(ref1->GetID(), ref2->GetID());
	}

	TEST(PointerEqualsRef)
	{
		Object* obj = new Object();
		RefPtr<Object> ref(obj);
	
		CHECK(ref == obj);
		CHECK(obj == ref);
	}

	TEST(PointerNotEqualsRef)
	{
		Object* obj = new Object();
		RefPtr<Object> ref(obj);
	
		CHECK(!(ref != obj));
		CHECK(!(obj != ref));
	}

	TEST(RefEqualsRef)
	{
		RefPtr<Object> ref1(new Object());
		RefPtr<Object> ref2(ref1);
	
		CHECK(ref1 == ref2);
		CHECK(ref2 == ref1);
	}

	TEST(RefNotEqualsRef)
	{
		RefPtr<Object> ref1(new Object());
		RefPtr<Object> ref2(ref1);
	
		CHECK(!(ref1 != ref2));
		CHECK(!(ref2 != ref1));
	}

}