// This design is not thread safe.
// To make it thread safe, we need to synchronize the function that creates and returns the singleton object.

#include <iostream>

class MySingleton 
{
	private:
		static MySingleton* s_pInstance;
	
	public:
		// The GetInstance() is not thread safe as multiple threads can enter into the "if (!m_pInstance)" block
		// and can create multiple singleton instances.

		static MySingleton& GetInstance()
		{
			if (!s_pInstance)
			{
				s_pInstance = new MySingleton();
			}
			return *s_pInstance;
		}

		void Print()
		{
			std::cout << std::endl << "This is an example of Classic Singleton Pattern.";
		}

	private:
		MySingleton() = default;
		~MySingleton() = default;
		MySingleton(const MySingleton&) = delete;
		MySingleton& operator =(const MySingleton&) = delete;
};

MySingleton* MySingleton::s_pInstance = nullptr;

int main()
{
	MySingleton::GetInstance().Print();
	std::cout << std::endl;
	return 0;
}

