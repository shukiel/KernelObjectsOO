#pragma once


#define INIT_OOK OOK::InitST  __OOK__ST__ =  *OOK::InitST::getInstance() ;

namespace OOK
{

	class InitST
	{
	public:
		 static InitST* getInstance();
		 ~InitST();

	private:

		InitST();

		static InitST* m_instance;
		void initLogger();
	};

	
}


