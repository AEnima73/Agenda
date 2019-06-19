#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

class Contacto {

        string nombre;
        int telefono;
    public:

         //Contacto( ): nombre("juan"),telefono(2323) { cout<<" se construye el contacto"<<endl;}

         Contacto(){ cout<<" se construye el contacto"<<endl;}
        ~Contacto(){cout<<"se destruye el contacto"<<endl;}

        void setNombre(string nom)  {
            nombre = nom;
        }
        void setNumero (int tel){
            telefono = tel;
        }
        string getNombre() {
            return nombre;
        }
        int getTelefono() {
            return telefono;
        }
};

class Agenda {
        list <Contacto> contactos;
    public:
        Agenda() {cout<<"se construye la agenda"<<endl;}
        ~Agenda() {cout<<"se destruye la agenda"<<endl;}

        void addContacto(Contacto* nContacto);
        void listarContactos();
};

void Agenda::addContacto(Contacto* nContacto) {
        contactos.push_back(*nContacto);
}

void Agenda::listarContactos()  {
        cout<<"-------------------------"<<endl;
        cout<<"   Agenda de Contactos    "<<endl;
        cout<<"-------------------------"<<endl;

        list<Contacto>::iterator ite;
            for(ite=contactos.begin(); ite != contactos.end(); ite++)
            {
                cout << "Nombre:  " << ite->getNombre() << endl;
                cout << "Telefono:  " << ite->getTelefono() << endl;
            }

        cout<<"-------------------------"<<endl;
}

int main() {

        Contacto* contacto = new Contacto();
        contacto->setNombre("Celes");
        contacto->setNumero(4353467);
       //cout<<contacto->getNombre()<<endl;

        //Contacto* contacto2 = new Contacto();
        //contacto2->setContacto("Luis", 9399929);

        Agenda* agenda = new Agenda();

        agenda->addContacto(contacto);
       // agenda->addContacto(contacto2);

        agenda->listarContactos();

        delete contacto;
        delete agenda;
        //cout<<contacto->getNombre()<<endl;
        return 0;
}
