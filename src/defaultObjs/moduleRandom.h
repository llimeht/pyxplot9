// moduleRandom.h
//
// The code in this file is part of PyXPlot
// <http://www.pyxplot.org.uk>
//
// Copyright (C) 2006-2012 Dominic Ford <coders@pyxplot.org.uk>
//               2008-2011 Ross Church
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

#ifndef _PPL_MODULE_RANDOM_H
#define _PPL_MODULE_RANDOM_H 1

#include "userspace/context.h"
#include "userspace/pplObj.h"

void pplfunc_setRandomSeed(long i);
void pplfunc_frandom   (ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);
void pplfunc_frandombin(ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);
void pplfunc_frandomcs (ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);
void pplfunc_frandomg  (ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);
void pplfunc_frandomln (ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);
void pplfunc_frandomp  (ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);
void pplfunc_frandomt  (ppl_context *c, pplObj *in, int nArgs, int *status, int *errType, char *errText);

#endif
