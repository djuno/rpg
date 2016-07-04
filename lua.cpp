#include "lua.h"


Lua::Lua()
{
  L=luaL_newstate();
  luaL_openlibs(L);
}
Lua::~Lua()
{
  lua_close(L);
}




void Lua::Runfile(const char* luafile)
{
  luaL_loadfile(L,luafile);
  lua_pcall(L,0,0,0);

}
