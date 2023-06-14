#include <atomic>
#include <cstdint>
#include <cstdio>

struct Test
{	
	std::atomic<int64_t>              m_Value;
	uint32_t* 						  m_pData;

	bool Check(int64_t v)
    {
        return v >= m_Value.load();
    }	
};

extern void DoSomething();

extern "C" void CrashClang(Test* pParam)
{
	uint32_t a0;
	uint32_t a1 = 0x803307BC;
	{
		try
		{
			{
				uint32_t a2 = 96;
start:
				a0 = pParam->m_pData[a1];
				if (a0)
				{
					goto part1;
				}
				{
					try
					{
						{							
part0:							
							if (pParam->Check(0))
							{
								try
								{
									DoSomething();
								}
								catch (...)
								{
									throw;
								}
							}
							goto part0;
						}
					}
					catch (...)
					{
						throw;
					}
				}				
				return;				
part1:
				a1 -=4;
				a2 -= 1;
				if (a2)
				{
					if (pParam->Check(0))
					{
						try
						{
							DoSomething();
						}
						catch (...)
						{
							printf("%u\n", a1);
							throw;
						}
					}
					goto start;
				}
				return;				
			}
		}
		catch (...)
		{
			throw;
		}
	}
}
