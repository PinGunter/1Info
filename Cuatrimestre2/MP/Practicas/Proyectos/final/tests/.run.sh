touch tests//.timeout
CMD="   /home/salvaromero/InfoUni/Primero/Cuatrimestre2/MP/Practicas/Proyectos/final/dist/Debug/GNU-Linux/final   -w 7 -l en -r 2020 -h 7 < data/empty.data  1> tests//.out4 2>&1"
eval $CMD
rm tests//.timeout
