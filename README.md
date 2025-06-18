```bash
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int opcion;
    int instalar;
    string objetivo;

    cout << "\033[1;32m";

    cout << R"(
  ___  _   _ _____ _____ _____ _____   ___   _   _
 / _ \| | | |_   _|  _  /  ___/  __ \ / _ \ | \ | |
/ /_\ \ | | | | | | | | \ --.| /  \// /_\ \|  \| |
|  _  | | | | | | | | | |--. \ |    |  _  || .  |
| | | | |_| | | | \ \_/ /\__/ / \__/\| | | || |\  |
\_| |_/\___/  \_/  \___/\____/ \____/\_| |_/\_| \_/
by: matteo nazzaro.
    )" << endl;

    cout << "\033[0m";

    cout << "Este programa requiere permisos de administrador." << endl;
    system("sudo -v");

    cout << "Desea instalar Nmap (por si no lo tiene instalado)?" << endl;
    cout << "[1] Si, instalar ahora." << endl;
    cout << "[2] No, ya lo tengo o no quiero instalarlo." << endl;
    cout << "Opcion: ";
    cin >> instalar;

    if(instalar == 1){
    cout<<"El programa estara listo dentro de poco."<<endl;
        system("sudo apt install nmap -y");
    }
    else if(instalar != 2){
        cout << "Opcion invalida. Continuando de todas formas..." << endl;
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
            cout << "Opcion invalida" << endl;
            return 0;
    }

    comando += objetivo;

    system("clear");

    cout << "Ejecutando: " << comando << endl;
    system(comando.c_str());

    return 0;
}
```
