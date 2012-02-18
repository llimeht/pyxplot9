// traceback.h
//
// The code in this file is part of PyXPlot
// <http://www.pyxplot.org.uk>
//
// Copyright (C) 2006-2012 Dominic Ford <coders@pyxplot.org.uk>
//               2008-2012 Ross Church
//
// $Id$
//
// PyXPlot is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// You should have received a copy of the GNU General Public License along with
// PyXPlot; if not, write to the Free Software Foundation, Inc., 51 Franklin
// Street, Fifth Floor, Boston, MA  02110-1301, USA

// ----------------------------------------------------------------------------

#ifndef _TRACEBACK_H
#define _TRACEBACK_H 1

#define TB_MAXLEVEL 8

#include "stringTools/strConstants.h"

typedef struct traceback {
  int errPos, errLine;
  long sourceId;
  char source[FNAME_LENGTH];
  char context[FNAME_LENGTH];
  char *linetext;
 } traceback;

typedef struct errStatus {
  int  errType, status, tracebackDepth;
  char errMsgExpr[LSTR_LENGTH]; long sourceIdExpr; int errPosExpr;
  char errMsgCmd [LSTR_LENGTH]; long sourceIdCmd;  int errPosCmd;
  char errBuff[LSTR_LENGTH];
  traceback tbLevel[TB_MAXLEVEL];
 } errStatus;

#endif
