namespace BitwiseEngine {

template<class T>
class RefPtr
{
public:
	RefPtr(T* obj = NULL)
	{
		m_obj = obj;
		if(m_obj)
		{
			m_obj->AddRef();
		}
	}

	RefPtr(const RefPtr& ref)
	{
		m_obj = ref.m_obj;
		if(m_obj)
		{
			m_obj->AddRef();
		}
	}

	virtual ~RefPtr()
	{
		if(m_obj)
		{
			m_obj->RemoveRef();
		}
	}

	operator T*() const
	{
		return m_obj;
	}

	T& operator*() const
	{
		return *m_obj;
	}

	T* operator->() const
	{
		return m_obj;
	}

	RefPtr& operator=(T* obj)
	{
		if(m_obj != obj)
		{
			if(obj)
			{
				obj->AddRef();
			}

			if(m_obj)
			{
				m_obj->RemoveRef();
			}

			m_obj = obj;
		}
		return *this;
	}

	RefPtr& operator=(const RefPtr& ref)
	{
		if(m_obj != ref.m_obj)
		{
			if(ref.m_obj)
			{
				ref.m_obj->AddRef();
			}

			if(m_obj)
			{
				m_obj->RemoveRef();
			}

			m_obj = ref.m_obj;
		}
		return *this;
	}

	bool operator==(T* obj) const
	{
		return m_obj == obj;
	}

	bool operator!=(T* obj) const
	{
		return m_obj != obj;
	}

	bool operator==(const RefPtr& ref) const
	{
		return m_obj == ref.m_obj;
	}

	bool operator!=(const RefPtr& ref) const
	{
		return m_obj != ref.m_obj;
	}

protected:
	T* m_obj;

};


}