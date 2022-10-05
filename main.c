// This file is released into the public domain.
// Read LICENSE.txt for more information.

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  lua_State* L = luaL_newstate();

  luaL_requiref(L, LUA_GNAME, luaopen_base, 1);
  luaL_requiref(L, LUA_COLIBNAME, luaopen_coroutine, 1);
  luaL_requiref(L, LUA_TABLIBNAME, luaopen_table, 1);
  luaL_requiref(L, LUA_IOLIBNAME, luaopen_io, 1);
  luaL_requiref(L, LUA_OSLIBNAME, luaopen_os, 1);
  luaL_requiref(L, LUA_STRLIBNAME, luaopen_string, 1);
  luaL_requiref(L, LUA_MATHLIBNAME, luaopen_math, 1);
  luaL_requiref(L, LUA_UTF8LIBNAME, luaopen_utf8, 1);
  luaL_requiref(L, LUA_DBLIBNAME, luaopen_debug, 1);
  lua_pop(L, 9);

  if (argc >= 2) {
    int n = 0;
    for (int i=1; i<argc; ++i) {
      lua_pushstring(L, " ");
      lua_pushstring(L, argv[i]);
      n += 2;
    }
    lua_concat(L, n-1);
    const char* expr = lua_tostring(L, -1);

    if (luaL_loadbuffer(L, expr, strlen(expr), expr) ||
        lua_pcall(L, 0, 1, 0)) {
      const char* s = lua_tostring(L, -1);
      if (s)
        fprintf(stderr, "error: %s\n", s);
    }
    else if (!lua_isnone(L, -1)) {
      const char* s = lua_tostring(L, -1);
      if (s)
        printf("%s\n", s);
    }
  }

  lua_close(L);
  return 0;
}
