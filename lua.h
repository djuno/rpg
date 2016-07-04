#include<lua5.2/lua.h>
#include<lua5.2/lauxlib.h>
#include<lua5.2/lualib.h>
#include<iostream>
#include<string>

class Lua
{
			public:
				Lua();
				~Lua();
				void Runfile(const char*);




			private:
				lua_State *L;
				const char* luafile;




};
