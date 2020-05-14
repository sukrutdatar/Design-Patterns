// This design is thread safe.
// To make it thread safe, we have implemented Meyers Singleton Pattern.

#include <iostream>
#include <mutex>

std::mutex g_mutex;

class MySingleton 
{
	private:
		static MySingleton* s_pInstance;
	
	public:
		// The GetInstance() is thread safe as we have made "GetInstance()" mutually exclusive
		// using std::mutex and std::lock_guard.
		
		// See: 
        // https://en.cppreference.com/w/cpp/thread/mutex
        // https://en.cppreference.com/w/cpp/thread/lock_guard

		static MySingleton& GetInstance()
		{
            if (!s_pInstance)
            {
                std::lock_guard<std::mutex> lk(g_mutex);

                if (!s_pInstance)
                {
                    s_pInstance = new MySingleton();
                }
            }
			return *s_pInstance;
		}

		void Print()
		{
			std::cout << std::endl << "This is an example of thread-safe Singleton Pattern using std::mutex, also known as Double-checked locking pattern.";
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

