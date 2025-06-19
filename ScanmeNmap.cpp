#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
    int opcion;
    int instalar;
    string objetivo;

    cout << "Cargando";
    for(int i=0; i<5; i++){
        cout << ".";
        fflush(stdout);
        sleep(1);
    }
    system("clear");
    cout << endl;
   cout << "\033[1;32m";

    cout << R"(
 █████╗ ██╗   ██╗████████╗ ██████╗ ███████╗ ██████╗ █████╗ ███╗   ██╗
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔════╝██╔════╝██╔══██╗████╗  ██║
███████║██║   ██║   ██║   ██║   ██║███████╗██║     ███████║██╔██╗ ██║
██╔══██║██║   ██║   ██║   ██║   ██║╚════██║██║     ██╔══██║██║╚██╗██║
██║  ██║╚██████╔╝   ██║   ╚██████╔╝███████║╚██████╗██║  ██║██║ ╚████║
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═══╝
                  NMAP AUTO-SCANNER by: n4Zza.

    )" << endl;

    cout << "\033[0m";

    cout << "\033[1;36m[*] Comprobando permisos sudo... \033[0m" << endl;
    system("sudo -v");

    cout << "\033[1;31m[!] Advertencia: Este programa requiere privilegios de administrador.\033[0m" << endl;

    cout << "Desea instalar Nmap (por si no lo tiene instalado)?" << endl;
    cout << "[1] Si, instalar ahora." << endl;
    cout << "[2] No, ya lo tengo o no quiero instalarlo." << endl;
    cout << "Opcion: ";
    cin >> instalar;

    if(instalar == 1){
        cout << "\033[1;33m[+] El programa estará listo dentro de poco.\033[0m" << endl;
        system("sudo apt install nmap -y");
    }
    else if(instalar != 2){
        cout << "\033[1;31m[!] Opcion invalida. Continuando de todas formas...\033[0m" << endl;
    }

    system("clear");

    cout << "Ingrese la direccion IP o URL: ";
    cin >> objetivo;

    system("clear");

    cout << "Seleccione el tipo de escaneo" << endl;
    cout << "[1] SYN (-sS)" << endl;
    cout << "[2] TCP (-sT)" << endl;
    cout << "[3] UDP (-sU)" << endl;
    cout << "[4] S.O (-O)" << endl;
    cout << "[5] Scan agresivo (-A)" << endl;
    cout << "Opcion (1/5): ";
    cin >> opcion;

    string comando = "sudo nmap ";

    switch(opcion){
        case 1: comando += "-sS "; break;
        case 2: comando += "-sT "; break;
        case 3: comando += "-sU "; break;
        case 4: comando += "-O ";  break;
        case 5: comando += "-A ";  break;
        default:
            cout << "\033[1;31m[!] Opcion invalida\033[0m" << endl;
            return 0;
    }

    comando += objetivo;

    system("clear");

    cout << "\033[1;32m---------------------------------------------\033[0m" << endl;
    cout << "\033[1;36mEjecutando escaneo Nmap...\033[0m" << endl;
    cout << "\033[1;32m---------------------------------------------\033[0m" << endl;

    cout << "Ejecutando: " << comando << endl;
    system(comando.c_str());

    cout << "\033[1;32m[+] Escaneo finalizado. Analiza los resultados con cuidado...\033[0m" << endl;

    cout << "\033[0m";

    return 0;
}
