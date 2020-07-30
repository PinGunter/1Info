touch tests//.timeout
CMD="valgrind --leak-check=full  valgrind --leak-check=full /home/salvaromero/infouni/Primero/Cuatrimestre2/MP/Practicas/Proyectos/tiles/dist/Debug/GNU-Linux/tiles  1> tests//.out13 2>&1"
eval $CMD
rm tests//.timeout
