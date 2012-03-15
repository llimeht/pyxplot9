// interpolate.h
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

#ifndef _INTERPOLATE_H
#define _INTERPOLATE_H 1

#include "parser/parser.h"
#include "userspace/context.h"
#include "userspace/pplObj.h"
#include "userspace/pplObjFunc.h"

void directive_interpolate (ppl_context *c, parserLine *pl, parserOutput *in, int interactive);
void ppl_spline_evaluate   (ppl_context *c, char *FuncName, splineDescriptor *desc, pplObj *in, pplObj *out, int *status, char *errout);
void ppl_interp2d_evaluate (ppl_context *c, const char *FuncName, splineDescriptor *desc, const pplObj *in1, const pplObj *in2, const unsigned char bmp, pplObj *out, int *status, char *errout);

#endif

