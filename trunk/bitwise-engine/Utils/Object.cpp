#include "Object.h"
#include <sstream>

using namespace BitwiseEngine::Utils;

unsigned int Object::ms_nextID = 0;

Object::Object(void)
{
	m_id = ms_nextID;
	ms_nextID++;

	m_references = 0;
}

Object::~Object(void)
{
}

std::string
Object::ToString() const
{
	using namespace std;

#pragma warning(push)
#pragma warning(disable:4311) // disable pointer truncation warning

	stringstream sstr;
	sstr << "Object (0x" << hex << reinterpret_cast<unsigned int>(this) << dec << ")";
	return sstr.str();

#pragma warning(pop)
}

unsigned int
Object::GetID() const
{
	return m_id;
}


void 
Object::AddRef()
{
	m_references++;
}

void 
Object::RemoveRef()
{
	m_references--;
	if(m_references <= 0)
	{
		delete this;
	}
}

int 
Object::GetRefs() const
{
	return m_references;
}