#include "stdafx.h"
#include "proxy.h"


void egProxy()
{
	CProxy proxy("server-1");
	proxy.connect();
	proxy.send("111");
	proxy.connect();
	proxy.send("222");
	proxy.connect();

}