#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anoPublicacion;
public:
    Libro(string t, string a, int ano) {
        titulo = t;
        autor = a;
        anoPublicacion = ano;
    }
    void mostrarInformacion() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Ano de Publicacion: " << anoPublicacion << endl;
    }
};

class Estudiante {
private:
    string nombre;
    string apellido;
    int edad;
    string curso;
public:
    Estudiante(string n, string a, int e, string c) {
        nombre = n;
        apellido = a;
        edad = e;
        curso = c;
    }
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Edad: " << edad << endl;
        cout << "Curso: " << curso << endl;
    }
};

class Calculadora {
private:
    double num1, num2;
public:
    Calculadora(double n1, double n2) {
        num1 = n1;
        num2 = n2;
    }
    double suma() {
        return num1 + num2;
    }
    double resta() {
        return num1 - num2;
    }
    double multiplicacion() {
        return num1 * num2;
    }
    double division() {
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Error: Division por cero." << endl;
            return 0;
        }
    }
};

class CuentaBancaria {
private:
    string nombreTitular;
    string numeroCuenta;
    double saldo;
public:
    CuentaBancaria(string nombre, string numero) {
        nombreTitular = nombre;
        numeroCuenta = numero;
        saldo = 0.0;
    }
    void depositar(double cantidad) {
        saldo += cantidad;
    }
    void retirar(double cantidad) {
        if (saldo >= cantidad)
            saldo -= cantidad;
        else
            cout << "Error: Saldo insuficiente." << endl;
    }
    double consultarSaldo() {
        return saldo;
    }
};

class Pelicula {
private:
    string titulo;
    string director;
    int anoLanzamiento;
public:
    Pelicula(string t, string d, int ano) {
        titulo = t;
        director = d;
        anoLanzamiento = ano;
    }
    void mostrarInformacion() {
        cout << "Titulo: " << titulo << endl;
        cout << "Director: " << director << endl;
        cout << "Ano de Lanzamiento: " << anoLanzamiento << endl;
    }
};

int main() {
    int opcion;
    do {
        cout << "Menu de Opciones:" << endl;
        cout << "1. Gestion de libros en una biblioteca" << endl;
        cout << "2. Registro de estudiantes" << endl;
        cout << "3. Calculadora simple" << endl;
        cout << "4. Gestion de cuentas bancarias" << endl;
        cout << "5. Registro de peliculas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string titulo, autor;
                int ano;
                cout << "Ingrese titulo del libro: ";
                cin >> titulo;
                cout << "Ingrese autor del libro: ";
                cin >> autor;
                cout << "Ingrese ano de publicacion del libro: ";
                cin >> ano;
                Libro libro(titulo, autor, ano);
                libro.mostrarInformacion();
                break;
            }
            case 2: {
                string nombre, apellido, curso;
                int edad;
                cout << "Ingrese nombre del estudiante: ";
                cin >> nombre;
                cout << "Ingrese apellido del estudiante: ";
                cin >> apellido;
                cout << "Ingrese edad del estudiante: ";
                cin >> edad;
                cout << "Ingrese curso del estudiante: ";
                cin >> curso;
                Estudiante estudiante(nombre, apellido, edad, curso);
                estudiante.mostrarInformacion();
                break;
            }
            case 3: {
                double num1, num2;
                cout << "Ingrese primer numero: ";
                cin >> num1;
                cout << "Ingrese segundo numero: ";
                cin >> num2;
                Calculadora calc(num1, num2);
                cout << "Suma: " << calc.suma() << endl;
                cout << "Resta: " << calc.resta() << endl;
                cout << "Multiplicacion: " << calc.multiplicacion() << endl;
                cout << "Division: " << calc.division() << endl;
                break;
            }
            case 4: {
                string nombre, numero;
                double saldo;
                cout << "Ingrese nombre del titular de la cuenta: ";
                cin >> nombre;
                cout << "Ingrese numero de cuenta: ";
                cin >> numero;
                cout << "Ingrese saldo inicial: ";
                cin >> saldo;
                CuentaBancaria cuenta(nombre, numero);
                cuenta.depositar(saldo);
                int opcionCuenta;
                do {
                    cout << "Menu de Cuenta Bancaria:" << endl;
                    cout << "1. Depositar" << endl;
                    cout << "2. Retirar" << endl;
                    cout << "3. Consultar saldo" << endl;
                    cout << "0. Volver al menu principal" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcionCuenta;
                    switch (opcionCuenta) {
                        case 1: {
                            double cantidad;
                            cout << "Ingrese cantidad a depositar: ";
                            cin >> cantidad;
                            cuenta.depositar(cantidad);
                            cout << "Deposito realizado." << endl;
                            break;
                        }
                        case 2: {
                            double cantidad;
                            cout << "Ingrese cantidad a retirar: ";
                            cin >> cantidad;
                            cuenta.retirar(cantidad);
                            cout << "Retiro realizado." << endl;
                            break;
                        }
                        case 3:
                            cout << "Saldo actual: " << cuenta.consultarSaldo() << endl;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                    }
                } while (opcionCuenta != 0);
                break;
            }
            case 5: {
                string titulo, director;
                int ano;
                cout << "Ingrese titulo de la pelicula: ";
                cin >> titulo;
                cout << "Ingrese director de la pelicula: ";
                cin >> director;
                cout << "Ingrese ano de lanzamiento de la pelicula: ";
                cin >> ano;
                Pelicula pelicula(titulo, director, ano);
                                    pelicula.mostrarInformacion();
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Opcion invalida." << endl;
            }
        } while (opcion != 0);
        return 0;
    }

