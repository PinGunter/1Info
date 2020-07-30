#!/bin/bash
# Título:		numE
# Fecha: 		7/3/2020
# Autor: 		Salvador Romero
# Versión: 		1.0
# Descripción: 	Devuelve el numero de archivos que existen en el directorio pasado
#				como argumento
# Opciones: 	ninguna
# Uso: 			numE directorio

ls $1 | wc -l
