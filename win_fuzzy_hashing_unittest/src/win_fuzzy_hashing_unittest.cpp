// pbase_unittest.cpp : 定义控制台应用程序的入口点。
//

#include "../include/stdafx.h"
#include <windows.h>
#include "gtest/gtest.h"

int _tmain(int argc, _TCHAR* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  system("pause");
	return 0;
}