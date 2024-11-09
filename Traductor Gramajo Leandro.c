#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Función para reemplazar palabras clave en español con las equivalentes en C
void reemplazarPalabras(char *linea, char *lineaNueva) {
    char *largodepalabra = linea;

    // Limpiar la línea nueva antes de comenzar
    lineaNueva[0] = '\0'; 

    // Recorrer la línea original y buscar las palabras clave
    while (*largodepalabra != '\0') {
        if (strncmp(largodepalabra, "incluir", 7) == 0) {
            strcat(lineaNueva, "include");
            largodepalabra += 7;
        } else if (strncmp(largodepalabra, "imprimirf", 9) == 0) {
            strcat(lineaNueva, "printf");
            largodepalabra += 9;
        } else if (strncmp(largodepalabra, "escanearf", 9) == 0) {
            strcat(lineaNueva, "scanf");
            largodepalabra += 9;
        } else if (strncmp(largodepalabra, "entero", 6) == 0) {
            strcat(lineaNueva, "int");
            largodepalabra += 6;
        } else if (strncmp(largodepalabra, "caracter", 8) == 0) {
            strcat(lineaNueva, "char");
            largodepalabra += 8;
        } else if (strncmp(largodepalabra, "decimal", 7) == 0) {
            strcat(lineaNueva, "float");
            largodepalabra += 7;
        } else if (strncmp(largodepalabra, "retornar", 8) == 0) {
            strcat(lineaNueva, "return");
            largodepalabra += 8;
        } else if (strncmp(largodepalabra, "principal", 9) == 0) {
            strcat(lineaNueva, "main");
            largodepalabra += 9;
        } else if (strncmp(largodepalabra, "si", 2) == 0) {
        if (strncmp(largodepalabra, "sistema", 7) == 0){
            strcat(lineaNueva, "system");
            largodepalabra += 7;
        }else {strcat(lineaNueva, "if");
            largodepalabra += 2;}
        } else if (strncmp(largodepalabra, "sino", 4) == 0) {
            strcat(lineaNueva, "else");
            largodepalabra += 4;
        } else if (strncmp(largodepalabra, "mientras", 8) == 0) {
            strcat(lineaNueva, "while");
            largodepalabra += 8;
        } else if (strncmp(largodepalabra, "leercaractersiguiente", 21) == 0) {
            strcat(lineaNueva, "getchar");
            largodepalabra += 21;    
        } else if (strncmp(largodepalabra, "pausa", 5) == 0) {
            strcat(lineaNueva, "pause");
            largodepalabra += 5;    
        } else {
            // Si no es una palabra clave, copiar el carácter actual
            strncat(lineaNueva, largodepalabra, 1);
            largodepalabra++;
        }
    }
}




int main() {
FILE *archivoEsp,*archivoC;
char linea[8000];
char lineaNueva[8000];
int estado = 1;
int opcionelegida = 0;

while (estado == 1){ 
printf("===============================\n");
printf("|    !!Bienvenido al Super    |\n");
printf("|        Traductor!!          |\n");
printf("===============================\n");
printf("Porfavor elija alguna de las siguientes opciones: \n");
printf("[1] - Empezar traduccion\n");
printf("[2] - Generar archivo de demostracion\n");
printf("[3] - Cerrar programa\n");
printf("[4] - Listado de palabras disponibles para traduccir al ingles\n ");
scanf("%i", &opcionelegida);
getchar(); 
switch (opcionelegida)  {
case 1:{

archivoEsp = fopen("./codigospanish.txt", "r");
if (archivoEsp == NULL) {
printf("No se encontro el archivo codigospanish.txt\n");
break;
                        }
// Abrir el archivo de salida para guardar el código C generado
archivoC = fopen("./codigotraducido.txt", "w");

while (fgets(linea, sizeof(linea), archivoEsp) != NULL) {
lineaNueva[0] = '\0';  // Limpiar la línea nueva
reemplazarPalabras(linea, lineaNueva);  // Realizar los reemplazos de palabras clave
fputs(lineaNueva, archivoC);     // Escribir la línea convertida en el archivo de salida

}
// Cerrar los archivos
fclose(archivoEsp);
fclose(archivoC);
printf("traduccion completada su archivo \"codigospanish.txt\" fue traducido en el archivo \"codigotraducido.c\" con exito!.\n");
break;

        }
case 2:{
FILE *archivodemostracion = fopen("codigospanish.txt", "w");
fprintf(archivodemostracion, 
"#incluir <stdio.h>\n"
    "#incluir <stdlib.h>\n"
    "int principal() {\n"
    "    entero numero;\n"
    "    caracter letra;\n\n"
    "    imprimirf(\"Ingrese un numero entero: \");\n"
    "    escanearf(\"%%d\", &numero);\n"
    "    leercaractersiguiente();\n"
    "    imprimirf(\"Ingrese un caracter: \");\n"
    "    escanearf(\"%%c\", &letra);\n\n"
    "    imprimirf(\"Ingresaste el numero: %%d y el caracter: %%c\\n\", numero, letra);\n\n"
    "    entero contador = 0;\n\n"
    "    imprimirf(\"Contando hasta 5:\\n\");\n"
    "    mientras (contador < 5) {\n"
    "    imprimirf(\"%%d\\n\", contador);\n"
    "    contador++;\n"
    "    }\n"
    "    sistema (\"pausa\");\n"
    "    retornar 0;\n"
    "}\n"
);
fclose(archivodemostracion);
printf("Archivo de demostracion creado con exito: \"codigospanish.txt\"\n");
break;
case 3:{
    estado = 0;
    break;
    }
case 4:{
    printf(
    "lista de palabras:\n"
     "- incluir\n"
     "- imprimir\n"
     "- escanear\n"
     "- entero\n"
     "- caracter\n"
     "- decimal\n"
     "- retornar\n"
     "- principal\n"
     "- si\n"
     "- sistema\n"
     "- sino\n"
     "- mientras\n"
     "- pausa\n"
     "- leercaractersiguiente\n");
break;
}    
   }
  }
 }
}
    
