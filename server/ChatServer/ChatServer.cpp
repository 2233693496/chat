﻿// ChatServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "LogicSystem.h"
#include <csignal>
#include <thread>
#include <mutex>
#include "AsioIOServicePool.h"
#include "CServer.h"
#include "ConfigMgr.h"
#include "RedisMgr.h"
using namespace std;
bool bstop = false;
std::condition_variable cond_quit;
std::mutex mutex_quit;

int main()
{
	auto& cfg = ConfigMgr::Inst();
	auto server_name = cfg["SelfServer"]["Name"];
	try {
		auto pool = AsioIOServicePool::GetInstance();
		//将登录数设置为0
		RedisMgr::GetInstance()->HSet(LOGIN_COUNT, server_name,"0");
		boost::asio::io_context  io_context;
		boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
		signals.async_wait([&io_context, pool](auto, auto) {
			io_context.stop();
			pool->Stop();
			});
		auto port_str = cfg["SelfServer"]["Port"];
		CServer s(io_context, atoi(port_str.c_str()));
		io_context.run();
		RedisMgr::GetInstance()->HDel(LOGIN_COUNT, server_name);
		RedisMgr::GetInstance()->Close();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << endl;
		RedisMgr::GetInstance()->HDel(LOGIN_COUNT, server_name);
		RedisMgr::GetInstance()->Close();
	}

}

