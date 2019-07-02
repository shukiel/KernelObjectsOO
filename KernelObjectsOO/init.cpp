#include "pch.h"
#include "init.h"
#include <plog/log.h>
#include <iostream>



namespace OOK
{

	const int m_logMaxSize = 1000000;
	const int m_maxNumOfFiles = 5;


	InitST* InitST::m_instance = nullptr;

	void InitST::initLogger()
	{
		plog::init(plog::verbose, "OOK_VERBOSE.log", m_logMaxSize, m_maxNumOfFiles);
	}

	InitST* OOK::InitST::getInstance()
	{	
		if (nullptr == m_instance)
		{
			m_instance = new InitST();
		}
	
		return m_instance;
	}
	
	InitST::InitST()
	{
		initLogger();
		std::cout << "Init Library OOK" << std::endl;
	}
	
	InitST::~InitST()
	{
		std::cout << "Cleanup" << std::endl;
	}
}
