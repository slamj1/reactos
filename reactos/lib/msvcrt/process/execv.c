/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */
#include <msvcrti.h>


int _execv(const char* szPath, char* const* szaArgv)
{
  return _spawnve(P_OVERLAY, szPath, szaArgv, _environ);
}
