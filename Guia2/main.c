#include <stdio.h>
#include <stdlib.h>

typedef struct {
      char nombre[30];
      char genero[30];
      int edad;
}persona;

void cargarEstructura();
void mostrarEstructura();
int contarGenero();

int main()
{
    persona arreglo[30];
    cargarEstructura();
    mostrarEstructura();
    int cantidad = contarGenero();
    printf("Cantidad del genero elegido: %i", cantidad);
    return 0;
}
void cargarEstructura(){
    FILE * buffer = fopen("archivo.bin", "ab");
    char control = 's';
    persona aux;

    printf("Desea cargar personas? (s/n) \n");
    fflush(stdin);
    scanf("%c", &control);
    if(buffer){
        while(control == 's'){
              printf("Ingrese el nombre de la persona \n");
              fflush(stdin);
              scanf("%s", &aux.nombre);

              printf("Ingrese el genero de la persona: \n");
              fflush(stdin);
              scanf("%s", &aux.genero);

              printf("Ingrese la edad de la persona: \n");
              scanf("%i",&aux.edad);

              printf("Desea seguir cargando personas? (s/n) \n");
              fflush(stdin);
              scanf("%c", &control);

              fwrite(&aux, sizeof(persona), 1, buffer);
        }
        fclose(buffer);
    }
}

void mostrarEstructura(){
    FILE * buffer;
    buffer=fopen("archivo.bin", "rb");
    persona aux;
    if(buffer){
        while(fread(&aux, sizeof(persona), 1, buffer) > 0){
              printf("Nombre de la persona: %s \n", aux.nombre);

              printf("Genero de la persona: %s \n", aux.genero);

              printf("Edad de la persona: %i \n", aux.edad);

              printf("------------------------\n");
        }
        fclose(buffer);
    }
}

int contarGenero(){
    FILE * buffer;
    buffer=fopen("archivo.bin", "rb");
    persona aux;
    char generoBuscar[20];
    int cantidad = 0;

    printf("Ingrese el genero a buscar: \n");
    fflush(stdin);
    scanf("%s", &generoBuscar);

    if(buffer){
        while(fread(&aux, sizeof(persona), 1, buffer) > 0){
           if(strcmpi(aux.genero, generoBuscar) == 0){
            cantidad++;
           }
        }
        fclose(buffer);
    }
    return cantidad;
}
