touch tests//.timeout
CMD="valgrind --leak-check=full  valgrind --leak-check=full /home/salva/Universidad/Primero/Cuatrimestre2/MP/Practicas/Proyectos/move/dist/Debug/GNU-Linux/move   1> tests//.out11 2>&1"
eval $CMD
rm tests//.timeout
