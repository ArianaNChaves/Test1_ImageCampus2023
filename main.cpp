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
 * estado de frenezi de los enemigos, cuando bajan a cierta cantidad de vida pegan mas fuerte
 */
using namespace std;

 enum Items {
     POCION_DE_VIDA,
     POCION_DE_DEFENSA,
     BABA,
     HUESO,
     MADERA,
     PIEDRA,
     MINERAL,
 };

 struct Slot {
     Items item;
     int cantidad;
 };

struct Armamento {
    string nombre;
    int poderDeAtaque;
    Items requisito;
};

struct Equipamiento {
    string nombre;
    int defensa;
    Items requisito;
};
struct Herramientas {
    string nombre;
    int capacidadDeRecoleccion;
    Items requisito;
};

struct Personaje{
    Slot consumibles[2] = {{POCION_DE_VIDA, 3}, {POCION_DE_DEFENSA, 3}};
    Slot objetos[5] = {{MINERAL, 0}, {BABA, 0}, {HUESO, 0}, {MADERA, 0}, {PIEDRA, 0}};
    Armamento arma = {"Espada basica", 10};
    Equipamiento armadura = {"Equipo basico", 10};
    Herramientas herramienta = {"Guantes basicos", 3};

    string nombre;
    float vida;
    float energia;
    float ataque;
    float defensa;
    float capacidadDeRecoleccion;

}personaje;
struct Enemigo{
    string nombre;
    float vida;
    float ataque;
    float defensa;
    string tipo = "enemigo";
    string drop;

}enemigo;
int numeroAleatorio(int minimo, int maximo) {
    srand(time(0));
    int numeroAleatorio = rand() % (maximo - minimo + 1) + minimo;
    return numeroAleatorio;
}
Enemigo creacionDeEnemigo(string nombre){
    Enemigo nuevoEnemigo;

    if (nombre == "Slime"){
        nuevoEnemigo.nombre = nombre;
        nuevoEnemigo.vida = 60;
        nuevoEnemigo.ataque = 20;
        nuevoEnemigo.defensa = 10;
        nuevoEnemigo.drop = BABA;
    }
    if (nombre == "Esqueleto"){
        nuevoEnemigo.nombre = nombre;
        nuevoEnemigo.vida = 75;
        nuevoEnemigo.ataque = 30;
        nuevoEnemigo.defensa = 15;
        nuevoEnemigo.drop = HUESO;
    }
    if (nombre == "Arbol"){
        nuevoEnemigo.nombre = nombre;
        nuevoEnemigo.vida = 150;
        nuevoEnemigo.ataque = 10;
        nuevoEnemigo.defensa = 50;
        nuevoEnemigo.drop = MADERA;
    }
    if (nombre == "Golem"){
        nuevoEnemigo.nombre = nombre;
        nuevoEnemigo.vida = 100;
        nuevoEnemigo.ataque = 20;
        nuevoEnemigo.defensa = 80;
        nuevoEnemigo.drop = PIEDRA;
    }


    return nuevoEnemigo;
}
void creacionDePersonaje(){
    //Dar una bienvenida

    //Elegir un nombre
    cout << "Ingrese el nombre del personaje" <<endl;
    cin >> personaje.nombre;

    system("cls");

    personaje.defensa = 15;
    personaje.ataque = 20;
    personaje.energia = 100;
    personaje.vida = 100;
    personaje.capacidadDeRecoleccion = 2;

    cout << "Se ha creado el personaje!" << endl;

    system("pause");
    system("cls");
}
int defensaTotal(){
    int defensaTotal;
    defensaTotal = personaje.armadura.defensa + personaje.defensa;
    return defensaTotal;
}
int poderTotal(){
    int poderTotal;
    poderTotal = personaje.arma.poderDeAtaque + personaje.ataque;
    return poderTotal;
}
int capacidadDeRecoleccion(){
    int cantidad;
    cantidad = personaje.capacidadDeRecoleccion + personaje.herramienta.capacidadDeRecoleccion;
    return cantidad;
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
string toStr(Items item) {
    switch (item) {
        case POCION_DE_DEFENSA:
            return "pocion de defensa";
        case POCION_DE_VIDA:
            return "pocion de vida";
        case MINERAL:
            return "mineral";
        case BABA:
            return "baba";
        case HUESO:
            return "hueso";
        case MADERA:
            return "madera";
        case PIEDRA:
            return "piedra";
        default:
            return "cualquier cosa";
    }
}
void agregarAInventario(Items item) {
    switch (item) {
        case POCION_DE_DEFENSA:
            personaje.consumibles[1].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        case POCION_DE_VIDA:
            personaje.consumibles[0].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        case MINERAL:
            personaje.objetos[0].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        case BABA:
            personaje.objetos[1].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        case HUESO:
            personaje.objetos[2].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        case MADERA:
            personaje.objetos[3].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        case PIEDRA:
            personaje.objetos[4].cantidad += 1;
            cout << toStr(item)<< " agregado correctamente." << endl;
            break;
        default:
            cout << "Nombre de item incorrecto" << endl;
            break;
    }
}
int consultarInventarioConsumible(){
    //mostrar que objetos CONSUMIBLES tengo
    int opcion,aux;
        for (int i = 0; i < 2; ++i) {
            cout<<i+1 <<".[" <<toStr(personaje.consumibles[i].item) <<" x" << personaje.consumibles[i].cantidad << "] ";
        }
        cout << endl;
        cout << "1.Consumir pocion de vida" << endl;
        cout << "2.Consumir pocion de defensa" << endl;
        cout << "3.Salir del inventario" << endl;
        do{
            cin >> opcion;
            switch (opcion) {
                case 1:
                    if (personaje.consumibles[0].cantidad <= 0){
                        cout << "No tienes ese objeto" << endl;
                        aux = 1;
                    }else{
                        personaje.consumibles[0].cantidad -= 1;
                        aux = 0;
                    }
                    break;
                case 2:
                    if (personaje.consumibles[1].cantidad <= 0){
                        cout << "No tienes ese objeto" << endl;
                        aux = 1;
                    }else{
                        personaje.consumibles[1].cantidad -= 1;
                        aux = 0;
                    }
                    break;
                case 3:
                    aux = 0;
                    break;
            }
        }while(aux == 1);
    //devuelve el numero de la opcion para hacer los cambios en la batalla, ademas si usa salir puede volver a entrar en el loop del switch de opciones
    return opcion;
}
bool batalla(Enemigo tipoDeEnemigo){
    int accionDeEnemigo;
    int accionDelPersonaje;
    float defensaDelPersonaje = defensaTotal();
    float defensaDelEnemigo = tipoDeEnemigo.defensa;
    float ataqueDelPersonaje = poderTotal();
    float ataqueDelEnemigo = tipoDeEnemigo.ataque;
    float vidaDelEnemigo = tipoDeEnemigo.vida;

    while(personaje.vida > 0 && vidaDelEnemigo > 0){
        //tiro un dado, si queda entre 1 o 2 el enemigo ataca, si saca 3 el enemigo se defiende
        accionDeEnemigo = numeroAleatorio(1, 3);
        if (accionDeEnemigo <= 2){
            cout << "El enemigo te atacara! que haras?" << endl;
            cout << tipoDeEnemigo.nombre << " [Vida: " << vidaDelEnemigo << "] " << "[Defensa: "<< defensaDelEnemigo<< "]"<< endl;
            cout << personaje.nombre << " [Vida: " << personaje.vida << "] " << "[Defensa: "<< defensaDelPersonaje << "]"<< endl;
            cout << "1.[Ataque pesado (40%)] 2.[Ataque ligero (90%)] 3.[Defenderse] 4.[Inventario] 5.[Pasar turno]"<< endl;
            cin >> accionDelPersonaje;
            switch (accionDelPersonaje) {
                case 1:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado fuerte con un poder de " << ataqueDelPersonaje * 3 << "!!"<< endl;

                        if ((ataqueDelPersonaje * 3) >= defensaDelEnemigo){
                            vidaDelEnemigo -= ((ataqueDelPersonaje * 3) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje * 3);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando ataca el enemigo
                    if (vidaDelEnemigo > 0){
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
                            vidaDelEnemigo -= ((ataqueDelPersonaje) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando ataca el enemigo
                    if (vidaDelEnemigo > 0){
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
                    cout << "Te vas a defender! (+" << (defensaTotal()) / 2 << ")" << endl;
                    defensaDelPersonaje = (defensaTotal() / 2);
                    //cuando ataca el enemigo
                    if (vidaDelEnemigo > 0){
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
                    switch (consultarInventarioConsumible()) {
                        case 1: //tomar pocion de vida
                            personaje.vida += 100;
                            cout << "(+100 de vida)" << endl;
                            //cuando ataca el enemigo
                            if (vidaDelEnemigo > 0){
                                cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                                if (ataqueDelEnemigo >= defensaDelPersonaje){
                                    personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                                    defensaDelPersonaje = 0;
                                }else{
                                    defensaDelPersonaje -= ataqueDelEnemigo;
                                }
                            }
                            break;
                        case 2: //tomar pocion de defensa
                            defensaDelPersonaje += 100;
                            cout << "(+100 de defensa)" << endl;
                            //cuando ataca el enemigo
                            if (vidaDelEnemigo > 0){
                                cout << "El enemigo te ha golpeado! (-"<<ataqueDelEnemigo<<")" << endl;
                                if (ataqueDelEnemigo >= defensaDelPersonaje){
                                    personaje.vida -= (ataqueDelEnemigo - defensaDelPersonaje);
                                    defensaDelPersonaje = 0;
                                }else{
                                    defensaDelPersonaje -= ataqueDelEnemigo;
                                }
                            }
                            break;
                        case 3: //salir
                            break;
                        default:
                            break;
                    }
                    break;
                case 5:
                    //cuando ataca el enemigo
                    if (vidaDelEnemigo > 0){
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
                    if (vidaDelEnemigo > 0){
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
            cout << tipoDeEnemigo.nombre << " [Vida: " << vidaDelEnemigo << "] " << "[Defensa: "<< defensaDelEnemigo<< "]"<< endl;
            cout << personaje.nombre << " [Vida: " << personaje.vida << "]" << "[Defensa: "<< defensaDelPersonaje << "]"<< endl;
            cout << "1.[Ataque pesado (40%)] 2.[Ataque ligero (90%)] 3.[Defenderse] 4.[Inventario] 5.[Pasar turno]"<< endl;
            cin >> accionDelPersonaje;
            switch (accionDelPersonaje) {
                case 1:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado fuerte con un poder de " << ataqueDelPersonaje * 3 << "!!"<< endl;

                        if ((ataqueDelPersonaje * 3) >= defensaDelEnemigo){
                            vidaDelEnemigo -= ((ataqueDelPersonaje * 3) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje * 3);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando se defiende el enemigo
                    if (vidaDelEnemigo > 0){
                        cout << "El enemigo se ha defendido! (+"<< 10<<")" << endl;
                        defensaDelEnemigo += 10;
                    }
                    break;
                case 2:
                    //lo que hace el personaje
                    if (golpeara(40)){
                        cout << "Has golpeado con un poder de " << ataqueDelPersonaje << "!!"<< endl;
                        if ((ataqueDelPersonaje) >= defensaDelEnemigo){
                            vidaDelEnemigo -= ((ataqueDelPersonaje) -defensaDelEnemigo);
                            defensaDelEnemigo = 0;
                        }else{
                            defensaDelEnemigo -= (ataqueDelPersonaje);
                        }
                    }else{
                        cout << "Has fallado el ataque!" << endl;
                    }
                    //cuando se defiende el enemigo
                    if (vidaDelEnemigo > 0){
                        cout << "El enemigo se ha defendido! (+"<< 10<<")" << endl;
                        defensaDelEnemigo += 10;
                    }
                    break;
                case 3:
                    cout << "Te vas a defender! (+" << (defensaTotal()) / 2 << ")" << endl;
                    defensaDelPersonaje += (defensaTotal() / 2);
                    //cuando se defiende el enemigo
                    if (vidaDelEnemigo > 0){
                        cout << "El enemigo se ha defendido! (+"<< 10<<")" << endl;
                        defensaDelEnemigo += 10;
                    }
                    break;
                case 4:
                    switch (consultarInventarioConsumible()) {
                        case 1: //tomar pocion de vida
                            personaje.vida += 100;
                            cout << "(+100 de vida)" << endl;
                            //cuando se defiende el enemigo
                            if (vidaDelEnemigo > 0){
                                cout << "El enemigo se ha defendido! (+"<< 10<<")" << endl;
                                defensaDelEnemigo += 10;
                            }
                            break;
                        case 2: //tomar pocion de defensa
                            defensaDelPersonaje += 100;
                            cout << "(+100 de defensa)" << endl;
                            //cuando se defiende el enemigo
                            if (vidaDelEnemigo > 0){
                                cout << "El enemigo se ha defendido! (+"<< 10<<")" << endl;
                                defensaDelEnemigo += 10;
                            }
                            break;
                        case 3: //salir
                            break;
                        default:
                            break;
                    }
                    break;
                case 5:
                    //cuando se defiende el enemigo
                    if (vidaDelEnemigo > 0){
                        cout << "El enemigo se ha defendido! (+"<< 10<<")" << endl;
                        defensaDelEnemigo += 10;
                    }
                    break;
                default:
                    //cuando ataca el enemigo
                    if (vidaDelEnemigo > 0){
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
        cout << "--------------------------------------------------------------------------------------" << endl;
        system("pause");
        system("cls");
    }
    bool ganaste;
    if (personaje.vida <= 0){
        cout << "Has perdido" << endl;
        ganaste = false;
    }
    if (vidaDelEnemigo <= 0){
        cout << "Lo has derrotado!" << endl;
        cout << "La batalla te ha agotado un poco... (-40 de energia)" << endl;
        personaje.energia -= 40;
        ganaste = true;
    }
    return ganaste;
}
void dropDeEnemigos(Enemigo tipoDeEnemigo){
    cout << "Te han dropeado unos objetos" << endl;
    if (tipoDeEnemigo.nombre == "Slime"){
        agregarAInventario(BABA);
    }
    if (tipoDeEnemigo.nombre == "Esqueleto"){
        agregarAInventario(HUESO);
    }
    if (tipoDeEnemigo.nombre == "Arbol"){
        agregarAInventario(MADERA);
    }
    if (tipoDeEnemigo.nombre == "Golem"){
        agregarAInventario(PIEDRA);
    }
}
void recolectar(){
    cout << "Has encontrado un par de objetos (-35 de energia)" << endl;
    personaje.energia -= 35;
    int cantidadARecolectar = capacidadDeRecoleccion(), numero;
    for (int i = 0; i < cantidadARecolectar; ++i) {
        numero = numeroAleatorio(1,3);
        switch (numero) {
            case 1:
                agregarAInventario(MADERA);
                break;
            case 2:
                agregarAInventario(MINERAL);
                break;
            case 3:
                agregarAInventario(PIEDRA);
                break;
        }
    }
}
bool cazarMonstruos(){
    Enemigo slime = creacionDeEnemigo("Slime");
    Enemigo esqueleto = creacionDeEnemigo("Esqueleto");
    Enemigo arbol = creacionDeEnemigo("Arbol");
    Enemigo golem = creacionDeEnemigo("Golem");

    int rival = numeroAleatorio(1,4);
    bool resultado;
        switch (rival) {
            case 1:
                resultado = batalla(slime);
                if (resultado){
                    dropDeEnemigos(slime);
                    agregarAInventario(POCION_DE_VIDA);
                }
                break;
            case 2:
                resultado = batalla(esqueleto);
                if (resultado){
                    dropDeEnemigos(esqueleto);
                    agregarAInventario(POCION_DE_DEFENSA);
                }
                break;
            case 3:
                resultado = batalla(arbol);
                if (resultado){
                    dropDeEnemigos(arbol);
                    agregarAInventario(POCION_DE_VIDA);
                }
                break;
            case 4:
                resultado = batalla(golem);
                if (resultado){
                    dropDeEnemigos(golem);
                    agregarAInventario(POCION_DE_DEFENSA);
                }
                break;
        }
    return resultado;
}
void forjaDeArmas(){
    Armamento tiendaDeArmas[3];
    tiendaDeArmas[0] = {"Espada de madera", 20, MADERA};
    tiendaDeArmas[1] = {"Mazo", 40, PIEDRA};
    tiendaDeArmas[2] = {"Espada de hueso", 60, HUESO};

    cout << "<-----------*--- ARMAS ---*----------->" << endl;
                //MOSTRAR armas
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 <<".[" << tiendaDeArmas[i].nombre << ", poder de ataque: "<< tiendaDeArmas[i].poderDeAtaque << ", requisito: " << toStr(tiendaDeArmas[i].requisito)<< " x5]" << endl;
    }
}
void forjaDeArmaduras(){
    Equipamiento tiendaDeArmaduras[3];
    tiendaDeArmaduras[0] = {"Armadura robusta", 20, MADERA};
    tiendaDeArmaduras[1] = {"Armadura dura", 40, MINERAL};
    tiendaDeArmaduras[2] = {"Armadura de muertos", 60, HUESO};

    cout << "<-----------*--- ARMADURAS ---*----------->" << endl;
    //MOSTRAR armaduras
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 <<".[" << tiendaDeArmaduras[i].nombre << ", defensa: "<< tiendaDeArmaduras[i].defensa << ", requisito: " << toStr(tiendaDeArmaduras[i].requisito) << " x5]" << endl;
    }
}
void forjaDeHerramientas(){
    Herramientas tiendaDeHerramientas[3];
    tiendaDeHerramientas[0] = {"Guantes pegajosos", 6, BABA};
    tiendaDeHerramientas[1] = {"Pala", 8, MADERA};
    tiendaDeHerramientas[2] = {"Pico", 10, HUESO};

    cout << "<-----------*--- HERRAMIENTAS ---*----------->" << endl;
    //MOSTRAR herramientas
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 <<".[" << tiendaDeHerramientas[i].nombre << ", capacidad de recoleccion: "<< tiendaDeHerramientas[i].capacidadDeRecoleccion << ", requisito: " << toStr(tiendaDeHerramientas[i].requisito) << " x5]" << endl;
    }
}
void crearArmas(){
    int crear;
    //mostrar lista de mejoras con sus requisitos

    forjaDeArmas();
    cout << "Cual deseas crear? [1,2,3] o ninguno [4]" << endl;
    cin >> crear;
    switch (crear) {
        case 1:
            if (personaje.objetos[3].cantidad >= 5){
                personaje.objetos[3].cantidad -= 5;
                personaje.arma = {"Espada de madera", 20};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
        break;
        case 2:
            if (personaje.objetos[4].cantidad >= 5){
                personaje.objetos[4].cantidad -= 5;
                personaje.arma = {"Mazo", 40};
                cout << "Ten y no mueras!" << endl;
            }else{
                 cout << "No tienes los items para crearlo" << endl;
            }
            break;
            case 3:
                 if (personaje.objetos[2].cantidad >= 5){
                     personaje.objetos[2].cantidad -= 5;
                     personaje.arma = {"Espada de hueso", 60};
                     cout << "Ten y no mueras!" << endl;
                 }else{
                    cout << "No tienes los items para crearlo" << endl;
                    }
                    break;
            default:
                cout << "Hasta pronto!" << endl;
            break;

    system("pause");
    system("cls");
    }
}
void crearArmaduras(){
    int crear;
    //mostrar lista de mejoras con sus requisitos

    forjaDeArmaduras();
    cout << "Cual deseas crear? [1,2,3] o ninguno [4]" << endl;
    cin >> crear;
    switch (crear) {
        case 1:
            if (personaje.objetos[3].cantidad >= 5){
                personaje.objetos[3].cantidad -= 5;
                personaje.armadura = {"Armadura robusta", 20};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
            break;
        case 2:
            if (personaje.objetos[0].cantidad >= 5){
                personaje.objetos[0].cantidad -= 5;
                personaje.armadura = {"Armadura dura", 40};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
            break;
        case 3:
            if (personaje.objetos[2].cantidad >= 5){
                personaje.objetos[2].cantidad -= 5;
                personaje.armadura = {"Armadura de muertos", 60};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
            break;
        default:
            cout << "Hasta pronto!" << endl;
            break;

            system("pause");
            system("cls");
    }
}
void crearHerramientas(){
    int crear;
    //mostrar lista de mejoras con sus requisitos

    forjaDeHerramientas();
    cout << "Cual deseas crear? [1,2,3] o ninguno [4]" << endl;
    cin >> crear;
    switch (crear) {
        case 1:
            if (personaje.objetos[1].cantidad >= 5){
                personaje.objetos[1].cantidad -= 5;
                personaje.herramienta = {"Guantes pegajosos", 6};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
            break;
        case 2:
            if (personaje.objetos[3].cantidad >= 5){
                personaje.objetos[3].cantidad -= 5;
                personaje.herramienta = {"Pala", 8};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
            break;
        case 3:
            if (personaje.objetos[2].cantidad >= 5){
                personaje.objetos[2].cantidad -= 5;
                personaje.herramienta = {"Pico", 10};
                cout << "Ten y no mueras!" << endl;
            }else{
                cout << "No tienes los items para crearlo" << endl;
            }
            break;
        default:
            cout << "Hasta pronto!" << endl;
            break;
    }
    system("pause");
    system("cls");
}
void chequearEstadisticas(){
    cout << "Nombre: " << personaje.nombre << endl;
    cout << "Vida: " << personaje.vida << endl;
    cout << "Energia: " << personaje.energia << endl;
    cout << "Capacidad de recoleccion: " << capacidadDeRecoleccion() << endl;
    cout << "Ataque total: " << poderTotal() << endl;
    cout << "Defensa total: " << defensaTotal() << endl;
    cout << "Arma equipada: " << personaje.arma.nombre << endl;
    cout << "Armadura equipada: " << personaje.armadura.nombre << endl;
    cout << "Herramienta equipada: " << personaje.herramienta.nombre << endl;
}
void descansar(){
    if(personaje.vida <= 100){
        personaje.vida = 100;
        cout << "Vida restaurada y energia!" << endl;
    }else{
        cout << "Has conservado la vida que has ganado!" << endl;
    }
    personaje.energia = 100;
}
void consultarInventarioObjeto(){
    for (int i = 0; i < 5; ++i) {
        cout << "[" << toStr(personaje.objetos[i].item) << " x" << personaje.objetos[i].cantidad<< "] ";
    }
}
void crearEquipo(){
    int opcion;
    consultarInventarioObjeto();
    cout << endl;
    cout << "EH! Has vuelto, crei que tu craneo ya era un florero.. Que quieres mirar?" << endl;
    cout << "1.Armas" << endl;
    cout << "2.Armaduras" << endl;
    cout << "3.Herramientas" << endl;
    cout << "4.Salir" << endl;
    cin >> opcion;
    switch (opcion) {
        case 1:
            crearArmas();
            break;
        case 2:
            crearArmaduras();
            break;
        case 3:
            crearHerramientas();
            break;
        default:
            cout << "Cuidate hijo" << endl;
    }
}
//todo Explicar como pelear(chances), recolectar, que pasa si moris, el funcionamiento de las pociones de vida/defensa
void bienvenida(){

}

int main() {
    srand(time(0));
    int monstruosDerrotados = 0, diasPasados = 0, opcion;
    bool gameOver = false, victoria = false;
    creacionDePersonaje();

    do {
    cout << "Estas en la aldea, que quieres hacer?" << endl;
    cout << "1. Recolectar" << endl;
    cout << "2. Cazar Monstruos" << endl;
    cout << "3. Crear/Equipar" << endl;
    cout << "4. Chequear Estadisticas" << endl;
    cout << "5. Descansar" << endl;
    cout << "6. Enfrentarte al Rey Demonio" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: //RECOLECCION
            system("pause");
            system("cls");
            if (personaje.energia >= 35){
                recolectar();
            }else{
                cout << "No tienes suficiente energia para eso" << endl;
            }
            break;
        case 2: //CAZAR MONSTRUOS
            system("pause");
            system("cls");
            if (personaje.energia >= 40){
                if (cazarMonstruos()){
                    monstruosDerrotados++;
                }else{
                    gameOver = true;
                }
            }else{
                cout << "No tienes suficiente energia para eso" << endl;
            }
            break;
        case 3: //CREAR / EQUIPAR
            system("pause");
            system("cls");
            crearEquipo();
            break;
        case 4: //CHEQUEAR ESTADISTICAS
            system("pause");
            system("cls");
            chequearEstadisticas();
            break;
        case 5://DESCANSAR
            system("pause");
            system("cls");
            descansar();
            diasPasados++;
            break;
        case 6://REY DEMONIO //todo Hacer la pela contra EL BOSS FINAL
            system("pause");
            system("cls");
            cout << "Area en construccion" << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
    }
    system("pause");
    system("cls");
    }while(!gameOver && !victoria);

    //todo Hacer si hubo victoria que aparezca "ganaste" y el puntaje, y si no, perdiste y le puntaje

    cout << "------------------- |Puntaje final| ------------------- " << endl;
    cout << "Monstruos derrotados: "<< monstruosDerrotados << endl;
    cout << "Dias transcurridos: "<< diasPasados << endl;



    return 0;
}
