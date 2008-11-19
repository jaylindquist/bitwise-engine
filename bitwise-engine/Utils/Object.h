#pragma once
#include <string>

namespace BitwiseEngine {

class Object
{
public:
	Object(void);
	virtual ~Object(void);

	unsigned int GetID() const;
	virtual std::string ToString() const;

	void AddRef();
	void RemoveRef();
	int GetRefs() const;
private:
	static unsigned int ms_nextID;
	unsigned int m_id;
	int m_references;
};

}