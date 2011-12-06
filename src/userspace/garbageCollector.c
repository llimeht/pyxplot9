// garbageCollector.c
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

#include "stdlib.h"
#include "stdio.h"

#include "gsl/gsl_matrix.h"
#include "gsl/gsl_vector.h"

#include "coreUtils/dict.h"
#include "coreUtils/list.h"
#include "userspace/garbageCollector.h"
#include "userspace/pplObj.h"
#include "userspace/pplObjFunc_fns.h"

void ppl_garbageNamespace(dict *n)
 {
  dictItem *ptr, *ptrnext;
  if ((n==NULL)||(!n->useMalloc)) return;
  ptr = n->first;
  while (ptr != NULL)
   {
    ptrnext = ptr->next;
    ppl_garbageObject((pplObj *)ptr->data);
    free(ptr->key);
    // free(ptr->data); -- already done by garbage collector
    free(ptr);
    ptr = ptrnext;
   }
  free(n);
  return;
 }

void ppl_garbageList(list *l)
 {
  listItem *ptr, *ptrnext;
  if ((l==NULL)||(!l->useMalloc)) return;
  ptr = l->first;
  while (ptr != NULL)
   {
    ptrnext = ptr->next;
    ppl_garbageObject((pplObj *)ptr->data);
    // free(ptr->data); -- already done by garbage collector
    free(ptr);
    ptr = ptrnext;
   }
  free(l);
  return;
 }

void ppl_garbageObject(pplObj *o)
 {
  int objType = o->objType;
  o->objType = PPLOBJ_ZOM; // Object is now a zombie
  switch(objType)
   {
    case PPLOBJ_STR:
    case PPLOBJ_EXC:
      if (o->auxilMalloced) { void *old=o->auxil; o->auxil=NULL; if (old!=NULL) free(old); }
      break;
    case PPLOBJ_FILE:
     {
      pplFile *f = (pplFile *)(o->auxil);
      o->auxil = NULL;
      if ((f!=NULL)&&(--f->refCount <= 0))
       {
        if ((f->open) && (f->file!=NULL)) { FILE *old=f->file; f->file=NULL; fclose(old); }
        free(f);
       }
      break;
     }
    case PPLOBJ_FUNC:
     {
      pplFunc *f = (pplFunc *)(o->auxil);
      o->auxil = NULL;
      if ((f!=NULL)&&(--f->refCount <= 0)) pplObjFuncDestroy(f);
      break;
     }
    case PPLOBJ_TYPE:
     {
      pplType *t = (pplType *)(o->auxil);
      o->auxil = NULL;
      if (t!=NULL) t->refCount--;
      break; // Types don't ever get garbage collected
     }
    case PPLOBJ_LIST:
     {
      list *l = (list *)(o->auxil);
      o->auxil = NULL;
      if ((l!=NULL)&&(--l->refCount <= 0)) ppl_garbageList(l);
      break;
     }
    case PPLOBJ_VEC:
     {
      pplVector *v = (pplVector *)(o->auxil);
      o->auxil = NULL;
      if ((v!=NULL)&&(--v->refCount <= 0))
       {
        gsl_vector_free(v->v);
        if (o->auxilMalloced) free(v);
       }
      break;
     }
    case PPLOBJ_MAT:
     {
      pplMatrix *m = (pplMatrix *)(o->auxil);
      o->auxil = NULL;
      if ((m!=NULL)&&(--m->refCount <= 0))
       {
        gsl_matrix_free(m->m);
        if (o->auxilMalloced) free(m);
       }
      break;
     }
    case PPLOBJ_USER:
     {
      ppl_garbageObject(o->objPrototype);
     }
    case PPLOBJ_DICT:
    case PPLOBJ_MOD:
     {
      dict *d = (dict *)(o->auxil);
      if ((d!=NULL)&&(--d->refCount <= 0)) ppl_garbageNamespace(d);
      break;
     }
   }

  if (o->amMalloced) free(o);
  return;
 }
