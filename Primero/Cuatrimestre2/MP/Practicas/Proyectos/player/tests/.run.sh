touch tests//.timeout
CMD="   /home/salva/Universidad/Primero/Cuatrimestre2/MP/Practicas/Proyectos/player/dist/Debug/GNU-Linux/player  < tests/US_EXCEPTION.test 1> tests//.out7 2>&1"
eval $CMD
rm tests//.timeout
