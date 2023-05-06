#include <iostream>
#include <stdlib.h>
/*Ideas
 * Sleep hace que no te muestre todo el choclo de texto de una, si no que vaya como narrando
 * Que el combate sea como el pokemon, donde podes elegir: atacar, usar objeto o huir.
 * Tener un array que sea "mochila" donde pueda llevar x cantidad de objetos. (5 por ejemplo)
 * Hacer enemigos "mas dificiles" a medida que van avanzando los dias
 * que las peleas sean por turno (dentro de un while o do-while)
 * ADENTRO de las peleas no cuenta la energia, si no que se resta cierto monto al terminar una (quizas varia la cantidad que te saca segun la dificultad)
 * revisar estadisticas
 * puntosDeAccion = seria como la cantidad de acciones que puede realizar el personaje antes de que pase su turno. Y las habilidades cuestan x puntosDeAccion
 * estado de frenezi de los enemigos, cuando bajan a cierta cantidad de vida pegan mas fuerte
 */

using namespace std;

struct Personaje{
    string nombre;
    string clase;
    string tipo = "personaje";
    float vida;
    float energia;
    float puntosDeAccion;
    float ataque;
    float defensa;
    //capacidad de recoleccion?
    float equipamiento;
    float arma;


}personaje;

struct Enemigo{
    string nombre;
    float vida;
    float ataque;
    float defensa;
    string tipo = "enemigo";
    //drop?
    string drop;

}enemigo;

int numeroAleatorio(int minimo, int maximo) {
    srand(time(0));
    int numeroAleatorio = rand() % (maximo - minimo + 1) + minimo;
    return numeroAleatorio;
}

Enemigo creacionDeEnemigo(string nombre){
    Enemigo nuevoEnemigo;

    nuevoEnemigo.nombre = nombre;
    nuevoEnemigo.vida = 500;
    nuevoEnemigo.ataque = 50;
    nuevoEnemigo.defensa = 7;
    nuevoEnemigo.drop = "baba";

    return nuevoEnemigo;
}

void creacionDePersonaje(){
    //se tendria que pedir al usuario el nombre, que tipo (mostrar ventajas y desventajas), y estadisticas inicial de cada tipo
    //warrior = + vida + defensa -ataque -energia
    //mage = -vida -defensa ++ataque +energia (cuando tira un hechizo debe esperar 2 turnos hasta volver a atacar
    //archer = vida defensa +ataque +energia o mas CDP
    int opcion;
    string opcionDeClase;
    string clase;
    //Dar una bienvenida


    //Elegir un nombre
    cout << "Ingrese el nombre del personaje" <<endl;
    cin >> personaje.nombre;

    //Clase del personaje
    //puede ser un menu switch donde elija 1 2 o 3 y luego se vea una descripcion, stat de la tipo y luego preguntar si desea confirmar esa seleccion o volver a las clases
    do {
        system("cls");
        cout << "Elija una tipo" << endl;
        cout << "1. Guerrero" << endl;
        cout << "2. Mago" << endl;
        cout << "3. Arquero" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Un Guerrero es una tipo melee donde su mayor ventaja es la resistencia dada por la vida y la defensa pero no tiene muchos puntos de accion" << endl;
                cout << "Desea elegir el guerrero? si/no" << endl;
                cin >> opcionDeClase;
                while(opcionDeClase != "si" && opcionDeClase != "no"){
                    cout << "opcion invalida" << endl;
                    cin >> opcionDeClase;
                }
                if (opcionDeClase == "si"){
                    clase = "guerrero";
                }
                break;
            case 2:
                cout << "Un Mago es una tipo rango donde su mayor ventaja es el poder de ataque y los puntos de accion pero no tiene mucha defensa ni mucha vida" << endl;
                cout << "Desea elegir el mago?? si/no" << endl;
                cin >> opcionDeClase;
                while(opcionDeClase != "si" && opcionDeClase != "no"){
                    cout << "opcion invalida" << endl;
                    cin >> opcionDeClase;
                }
                if (opcionDeClase == "si"){
                    clase = "mago";
                }
                break;
            case 3:
                cout << "Un Arquero es una tipo rango donde su mayor ventaja es el poder de ataque y una defensa media pero no tiene mucha vida ni muchos puntos de accion" << endl;
                cout << "Desea elegir el arquero? si/no" << endl;
                cin >> opcionDeClase;
                while(opcionDeClase != "si" && opcionDeClase != "no"){
                    cout << "opcion invalida" << endl;
                    cin >> opcionDeClase;
                }
                if (opcionDeClase == "si"){
                    clase = "arquero";
                }
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    }while(opcionDeClase != "si");
    if (clase == "guerrero"){
        personaje.clase = "guerrero";
        personaje.defensa = 15;
        personaje.ataque = 10;
        personaje.puntosDeAccion = 3;
        personaje.energia = 100;
        personaje.vida = 150;
        cout << "Se ha creado un guerrero!" << endl;
    }
    else if (clase == "mago"){
        personaje.clase = "mago";
        personaje.defensa = 5;
        personaje.ataque = 20;
        personaje.puntosDeAccion = 6;
        personaje.energia = 100;
        personaje.vida = 100;
        cout << "Se ha creado un mago!" << endl;
    }else{
        personaje.clase = "arquero";
        personaje.defensa = 10;
        personaje.ataque = 15;
        personaje.puntosDeAccion = 4;
        personaje.energia = 100;
        personaje.vida = 125;
        cout << "Se ha creado un arquero!" << endl;
    }

    personaje.arma = 10;
    personaje.equipamiento = 20;


    system("cls");
}

int calculoDeDefensa(){
    int defensaTotal;
    defensaTotal = personaje.equipamiento + personaje.defensa;
    return defensaTotal;
}
int calculoDePoder(){
    int poderTotal;
    poderTotal = personaje.arma + personaje.ataque;
    return poderTotal;
}

bool golpeara(int porcentajeDeQueGolpee){
    bool golpeara;
    float indiceDeGolpe = porcentajeDeQueGolpee/10;
    int chance = numeroAleatorio(1,10);
    if (indiceDeGolpe >= chance){
        golpeara = true;
    }else{
        golpeara = false;
    }
    return golpeara;
}

void batalla(Enemigo tipoDeEnemigo){
    int accionDeEnemigo;
    int accionDelPersonaje;
    float defensaDelPersonaje = calculoDeDefensa();
    float defensaDelEnemigo = tipoDeEnemigo.defensa;
    float ataqueDelPersonaje = calculoDePoder();
    float ataqueDelEnemigo = tipoDeEnemigo.ataque;

    while(personaje.vida >0 && tipoDeEnemigo.vida > 0){
        //tiro un dado, si queda entre 1 o 2 el enemigo ataca, si saca 3 el enemigo se defiende
        accionDeEnemigo = numeroAleatorio(1, 3);
        if (accionDeEnemigo <= 2){
            cout << "El enemigo te atacara! que haras?" << endl;
            cout << tipoDeEnemigo.nombre << " [Vida: " << tipoDeEnemigo.vida << "] " << "[Defensa: "<< defensaDelEnemigo<< "]"<< endl;
            cout << personaje.nombre << " [Vida: " << personaje.vida << "]" << "[Defensa: "<< defensaDelPersonaje << "]"<< endl;
            cout << "1.[Ataque pesado (40%)] 2.[Ataque ligero (90%)] 3.[Defenderse] 4.[Inventario] 5.[Pasar turno]"<< endl;
            cin >> accionDelPersonaje;
            switch (accionDelPersonaje) {
                case 1:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado fuerte con un poder de " << ataqueDelPersonaje * 3 << "!!"<< endl;

                        if ((ataqueDelPersonaje * 3) >= defensaDelEnemigo){
                            tipoDeEnemigo.vida -= ((ataqueDelPersonaje * 3) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje * 3);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando ataca el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                        if (ataqueDelEnemigo >= defensaDelPersonaje){
                            personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                            defensaDelPersonaje = 0;
                        }else{
                            defensaDelPersonaje -= ataqueDelEnemigo;
                        }
                    }
                    break;
                case 2:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado con un poder de " << ataqueDelPersonaje << "!!"<< endl;
                        if ((ataqueDelPersonaje) >= defensaDelEnemigo){
                            tipoDeEnemigo.vida -= ((ataqueDelPersonaje) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando ataca el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                        if (ataqueDelEnemigo >= defensaDelPersonaje){
                            personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                            defensaDelPersonaje = 0;
                        }else{
                            defensaDelPersonaje -= ataqueDelEnemigo;
                        }
                    }
                    break;
                case 3:
                    cout << "Te vas a defender! (+" << (personaje.defensa+ personaje.equipamiento) / 2 <<")"<< endl;
                    defensaDelPersonaje = (calculoDeDefensa()/2);
                    //cuando ataca el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                        if (ataqueDelEnemigo >= defensaDelPersonaje){
                            personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                            defensaDelPersonaje = 0;
                        }else{
                            defensaDelPersonaje -= ataqueDelEnemigo;
                        }
                    }
                    break;
                case 4:
                    cout << "Hacer el inventario :D" << endl;
                    break;
                case 5:
                    //cuando ataca el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                        if (ataqueDelEnemigo >= defensaDelPersonaje){
                            personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                            defensaDelPersonaje = 0;
                        }else{
                            defensaDelPersonaje -= ataqueDelEnemigo;
                        }
                    }
                    break;
                default:
                    cout <<"Has torpezado y te han atacado!"<< endl;
                    //cuando ataca el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                        if (ataqueDelEnemigo >= defensaDelPersonaje){
                            personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                            defensaDelPersonaje = 0;
                        }else{
                            defensaDelPersonaje -= ataqueDelEnemigo;
                        }
                    }
                    break;
            }
        }else{
            cout << "El enemigo se defendera! que haras?" << endl;
            cout << tipoDeEnemigo.nombre << " [Vida: " << tipoDeEnemigo.vida << "] " << "[Defensa: "<< defensaDelEnemigo<< "]"<< endl;
            cout << personaje.nombre << " [Vida: " << personaje.vida << "]" << "[Defensa: "<< defensaDelPersonaje << "]"<< endl;
            cout << "1.[Ataque pesado (40%)] 2.[Ataque ligero (90%)] 3.[Defenderse] 4.[Inventario] 5.[Pasar turno]"<< endl;
            cin >> accionDelPersonaje;
            switch (accionDelPersonaje) {
                case 1:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado fuerte con un poder de " << ataqueDelPersonaje * 3 << "!!"<< endl;

                        if ((ataqueDelPersonaje * 3) >= defensaDelEnemigo){
                            tipoDeEnemigo.vida -= ((ataqueDelPersonaje * 3) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje * 3);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando se defiende el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo se ha defendido! (+"<< defensaDelEnemigo / 2<<")" << endl;
                        defensaDelEnemigo += (tipoDeEnemigo.defensa / 2);
                    }
                    break;
                case 2:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado con un poder de " << ataqueDelPersonaje << "!!"<< endl;
                        if ((ataqueDelPersonaje) >= defensaDelEnemigo){
                            tipoDeEnemigo.vida -= ((ataqueDelPersonaje) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando se defiende el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El enemigo se ha defendido! (+"<< defensaDelEnemigo / 2<<")" << endl;
                        defensaDelEnemigo += (tipoDeEnemigo.defensa / 2);
                    }
                    break;
                case 3:
                    cout << "Te vas a defender! (+" << (personaje.defensa+ personaje.equipamiento) / 2 <<")"<< endl;
                    defensaDelPersonaje += (calculoDeDefensa()/2);
                    //cuando se defiende el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El se ha defendido! (+"<< defensaDelEnemigo / 2<<")" << endl;
                        defensaDelEnemigo += (tipoDeEnemigo.defensa / 2);
                    }
                    break;
                case 4:
                    cout << "Hacer el inventario :D" << endl;
                    break;
                case 5:
                    //cuando se defiende el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout << "El se ha defendido! (+"<< defensaDelEnemigo / 2<<")" << endl;
                        defensaDelEnemigo += (tipoDeEnemigo.defensa / 2);
                    }
                    break;
                default:
                    //cuando ataca el enemigo
                    if (tipoDeEnemigo.vida > 0){
                        cout <<"Has torpezado y te han atacado! (-"<<ataqueDelEnemigo<<")"<< endl;
                        if (ataqueDelEnemigo >= defensaDelPersonaje){
                            personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                            defensaDelPersonaje = 0;
                        }else{
                            defensaDelPersonaje -= ataqueDelEnemigo;
                        }
                    }
                    break;
            }
        }
        cout << "----------------------------------------------------" << endl;
    }
    if (personaje.vida <= 0){
        cout << "Has perdido" << endl;
    }
    if (tipoDeEnemigo.vida <= 0){
        cout << "Lo has derrotado!" << endl;
    }
}


int main() {
    srand(time(0));
    creacionDePersonaje();
    Enemigo slime = creacionDeEnemigo("Slime");


    batalla(slime);

    return 0;
}
