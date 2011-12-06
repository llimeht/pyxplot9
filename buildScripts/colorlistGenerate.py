# colorlistGenerate.py
#
# The code in this file is part of PyXPlot
# <http://www.pyxplot.org.uk>
#
# Copyright (C) 2006-2012 Dominic Ford <coders@pyxplot.org.uk>
#               2008-2011 Ross Church
#
# $Id$
#
# PyXPlot is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation; either version 2 of the License, or (at your option) any later
# version.
#
# You should have received a copy of the GNU General Public License along with
# PyXPlot; if not, write to the Free Software Foundation, Inc., 51 Franklin
# Street, Fifth Floor, Boston, MA  02110-1301, USA

# ----------------------------------------------------------------------------

color_list={
"GreenYellow": [0.15, 0, 0.69, 0],
"Yellow": [0, 0, 1, 0],
"GoldenRod": [0, 0.10, 0.84, 0],
"Dandelion": [0, 0.29, 0.84, 0],
"Apricot": [0, 0.32, 0.52, 0],
"Peach": [0, 0.50, 0.70, 0],
"Melon": [0, 0.46, 0.50, 0],
"YellowOrange": [0, 0.42, 1, 0],
"Orange": [0, 0.61, 0.87, 0],
"BurntOrange": [0, 0.51, 1, 0],
"BitterSweet": [0, 0.75, 1, 0.24],
"RedOrange": [0, 0.77, 0.87, 0],
"Mahogany": [0, 0.85, 0.87, 0.35],
"Maroon": [0, 0.87, 0.68, 0.32],
"BrickRed": [0, 0.89, 0.94, 0.28],
"Red": [0, 1, 1, 0],
"OrangeRed": [0, 1, 0.50, 0],
"RubineRed": [0, 1, 0.13, 0],
"WildStrawberry": [0, 0.96, 0.39, 0],
"Salmon": [0, 0.53, 0.38, 0],
"CarnationPink": [0, 0.63, 0, 0],
"Magenta": [0, 1, 0, 0],
"VioletRed": [0, 0.81, 0, 0],
"Rhodamine": [0, 0.82, 0, 0],
"Mulberry": [0.34, 0.90, 0, 0.02],
"RedViolet": [0.07, 0.90, 0, 0.34],
"Fuchsia": [0.47, 0.91, 0, 0.08],
"Lavender": [0, 0.48, 0, 0],
"Thistle": [0.12, 0.59, 0, 0],
"Orchid": [0.32, 0.64, 0, 0],
"DarkOrchid": [0.40, 0.80, 0.20, 0],
"Purple": [0.45, 0.86, 0, 0],
"Plum": [0.50, 1, 0, 0],
"Violet": [0.79, 0.88, 0, 0],
"RoyalPurple": [0.75, 0.90, 0, 0],
"BlueViolet": [0.86, 0.91, 0, 0.04],
"Periwinkle": [0.57, 0.55, 0, 0],
"CadetBlue": [0.62, 0.57, 0.23, 0],
"CornflowerBlue": [0.65, 0.13, 0, 0],
"MidnightBlue": [0.98, 0.13, 0, 0.43],
"NavyBlue": [0.94, 0.54, 0, 0],
"RoyalBlue": [1, 0.50, 0, 0],
"Blue": [1, 1, 0, 0],
"Cerulean": [0.94, 0.11, 0, 0],
"Cyan": [1, 0, 0, 0],
"ProcessBlue": [0.96, 0, 0, 0],
"SkyBlue": [0.62, 0, 0.12, 0],
"Turquoise": [0.85, 0, 0.20, 0],
"TealBlue": [0.86, 0, 0.34, 0.02],
"Aquamarine": [0.82, 0, 0.30, 0],
"BlueGreen": [0.85, 0, 0.33, 0],
"Emerald": [1, 0, 0.50, 0],
"JungleGreen": [0.99, 0, 0.52, 0],
"SeaGreen": [0.69, 0, 0.50, 0],
"Green": [1, 0, 1, 0],
"ForestGreen": [0.91, 0, 0.88, 0.12],
"PineGreen": [0.92, 0, 0.59, 0.25],
"LimeGreen": [0.50, 0, 1, 0],
"YellowGreen": [0.44, 0, 0.74, 0],
"SpringGreen": [0.26, 0, 0.76, 0],
"OliveGreen": [0.64, 0, 0.95, 0.40],
"RawSienna": [0, 0.72, 1, 0.45],
"Sepia": [0, 0.83, 1, 0.70],
"Brown": [0, 0.81, 1, 0.60],
"Tan": [0.14, 0.42, 0.56, 0],
"Gray": [0, 0, 0, 0.50],
"Grey": [0, 0, 0, 0.50],
"Black": [0, 0, 0, 1],
"White": [0, 0, 0, 0],
"Invisible": [-1, -1, -1, -1],
"Null": [-1, -1, -1, -1],
"Transparent": [-1, -1, -1, -1],
}

for greylevel in range(0,101):
 color_list["Grey%02d"%greylevel] = [0, 0, 0, float(100-greylevel)/100]
 color_list["Gray%02d"%greylevel] = [0, 0, 0, float(100-greylevel)/100]

color_names = color_list.keys()
color_names.sort()

# Write ppl_colors.h
output = open("src/settings/epsColors.h","w")
output.write("""// This file auto-generated by colorsGenerate.py

#ifndef _EPSCOLORS_H
#define _EPSCOLORS_H 1

""")

for i in range(len(color_names)): output.write("#define COLOR_%s %d\n"%(color_names[i].upper() , i+20000))
output.write("\n#ifndef _EPSCOLORS_C\n")
output.write("extern char  *SW_COLOR_STR[];\n")
output.write("extern int    SW_COLOR_DCL[];\n")
output.write("extern int    SW_COLOR_INT[];\n\n")
output.write("extern double SW_COLOR_CMYK_C[];\n")
output.write("extern double SW_COLOR_CMYK_M[];\n")
output.write("extern double SW_COLOR_CMYK_Y[];\n")
output.write("extern double SW_COLOR_CMYK_K[];\n")
output.write("#endif\n\n#endif\n")
output.close()

# Write ppl_colors.c
output = open("src/settings/epsColors.c","w")
output.write("""// This file auto-generated by colorsGenerate.py

#define _EPSCOLORS_C 1

#include "epsColors.h"

char  *SW_COLOR_STR[] = {""")
for i in range(len(color_names)): output.write(""" "%s" , """%color_names[i])
output.write("};\nint    SW_COLOR_DCL[] = {")
for i in range(len(color_names)): output.write(""" %d , """%len(color_names[i]))
output.write("};\nint    SW_COLOR_INT[] = {")
for i in range(len(color_names)): output.write(""" COLOR_%s , """%(color_names[i].upper()))
output.write("-1};\ndouble SW_COLOR_CMYK_C[] = {")
for i in range(len(color_names)): output.write(""" %f , """%(color_list[color_names[i]][0]))
output.write("};\ndouble SW_COLOR_CMYK_M[] = {")
for i in range(len(color_names)): output.write(""" %f , """%(color_list[color_names[i]][1]))
output.write("};\ndouble SW_COLOR_CMYK_Y[] = {")
for i in range(len(color_names)): output.write(""" %f , """%(color_list[color_names[i]][2]))
output.write("};\ndouble SW_COLOR_CMYK_K[] = {")
for i in range(len(color_names)): output.write(""" %f , """%(color_list[color_names[i]][3]))
output.write("};\n")

output.close()
