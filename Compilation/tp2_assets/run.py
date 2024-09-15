#!/usr/bin/python
# -*- coding: utf-8 -*-
import os, sys

memwalk_command = "memwalk/memwalk" # chemin vers l'exécutable memwalk'

points = 128 # nombre de points
min_2f = 10  # puissance de 2 minimale
max_2f = 25  # puissance de 2 maximale


for i in range(0, points):
	# `i_2f` varie linéairement entre `min_2f` et ̀ max_2f`, en ̀ points` étapes
	i_2f = min_2f + float(max_2f - min_2f) * i / float(points)
	
	# la quantité de mémoire utilisée à cette étape est 2^(i_2f)
	mem = int(pow(2, i_2f)) & 0xFFFFFFF0
	
	# affiche l'étape courante
	sys.stderr.write('\r %d / %d : %d bytes' % (i + 1, points, mem))
	
	# lance memwalk
	ret = os.system("%s -m %d -n 10000000 -r -t 5" % (memwalk_command, mem))
	if ret != 0: break

print "\n"
