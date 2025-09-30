#include <iostream>
#include <string>
#include "Arraylist/ArrayList.cpp"

using namespace std;
int main() {
    ArrayList<string> list;
    int opcion, index;
    string valor;

    do {
        cout << "Menu de opciones:\n";
        cout << "1. Agregar valor\n";
        cout << "2. Obtener valor por indice\n";
        cout << "3. Eliminar valor por indice\n";
        cout << "4. Mostrar tamano de la lista\n";
        cout << "5. Mostrar primer nodo\n";
        cout << "6. Ir al siguiente nodo\n";
        cout << "7. Mostrar el ultimo nodo\n";
        cout << "8. Ir al anterior nodo\n";
        cout << "9. Ver lista completa\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor para agregar: ";
                cin.ignore();
                getline(cin, valor);
                list.add(valor);
                break;
            case 2:
                cout << "Ingrese el indice del valor a obtener: ";
                cin >> index;
                try {
                    cout << "Valor en el indice " << index << ": " << list.get(index) << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                cout << "Ingrese el indice del valor a eliminar: ";
                cin >> index;
                try {
                    list.Delete(index);
                    cout << "Valor eliminado." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                cout << "Tamano de la lista: " << list.size() << endl;
                break;
            case 5:
                try {
                cout << "El primer elemento de la lista es: " << list.first() << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
            try {
                cout << "El siguiente nodo de la lista es: " << list.next() << endl;
            } catch (const out_of_range& e){
                cout << e.what() << endl;
            }
                break;
            case 7:
                try {
                    cout << "El ultimo elemento de la lista es: " << list.last() << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 8: 
                try {
                    cout << "El anterior elemento en la lista es: " << list.priore() << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 9:
                cout << "Lista completa: ";
                list.viewList();
                break;
            case 10:
                cout << "Saliendo..." << endl;
               break;
            default:
                cout << "Opcion invalida." << endl;
        }
        cout << endl;
    } while (opcion != 10);

    return 0;
}