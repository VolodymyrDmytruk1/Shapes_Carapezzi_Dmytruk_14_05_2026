#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 100
#define GRID_X 100
#define GRID_Y 100



int main()
{
/*
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new RightTriangle(0, 0, 10, 20);


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo rettangolo");


    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    shapes[0]->Scale(2);
    shapes[1]->Scale(1);
    shapes[2]->Scale(0.5);

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }


    for (int i = 0; i < nShapes; i++) {
        delete shapes[i];
        shapes[i] = nullptr;
    }

    cout << endl << "===== FINE TEST =====" << endl;
    */
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    int select1 = -1;
    int select2 = -2;
    int select3 = -1;
    int val=0;
    string str="";
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);

    while(select1 != 0){
        cout << "1 Visualizza tutti i poligoni \n" << "2 Modifica le proprietà di un poligono\n" << "3 Sposta un poligono sulla griglia\n"
        << "4 Inserisci un nuovo poligono\n" << "5 Cancella un poligono\n" << "6 Cancella tutti i poligoni\n" << "0 Esci\n" << endl;

        cin >> select1;
        switch(select1)
        {
            case 1:
                if(nShapes==0){
                cout<<"No figures"<<endl;
                break;
                }
                while(select2!=-1)
                {
                    for (int i = 0; i < nShapes; i++)
                    {
                        cout << "Figura numero: " << i << "\nTipo: ";
                        switch (shapes[i]->GetType())
                        {
                            case 0: cout << "Rettangolo"; break;
                            case 1: cout << "Rombo"; break;
                            case 2: cout << "Triangolo Rettangolo"; break;
                            default: cout << "Unknown"; break;
                        }
                        cout << endl;
                        cout << "Position X: " << shapes[i]->GetX() << endl;
                        cout << "Position Y: " << shapes[i]->GetY() << endl;
                        cout << "Height: " << shapes[i]->GetHeight() << endl;
                        cout << "Width: " << shapes[i]->GetWidth() << endl;
                    }
                    cout << "Select the poligon: \n-1 to exit" << endl;
                    cin >> select2;
                    if(select2>=nShapes || select2<-1){
                        cout<<"shape does not exist"<<endl;
                    }
                    else
                    {
                        for (int i = 0; i < nShapes; i++)
                        {
                            if (select2==i)
                            {
                                shapes[i]->Dump();
                            }
                        }
                    }
                }
            break;
            case 2:
                if(nShapes==0){
                cout<<"No figures"<<endl;
                break;
                }
                while(true)
                {
                    for (int i = 0; i < nShapes; i++)
                    {
                        cout << "Figura numero: " << i << "\nTipo: ";
                        switch (shapes[i]->GetType())
                        {
                            case 0: cout << "Rettangolo"; break;
                            case 1: cout << "Rombo"; break;
                            case 2: cout << "Triangolo Rettangolo"; break;
                            default: cout << "Unknown"; break;
                        }
                        cout << endl;
                        cout << "Position X: " << shapes[i]->GetX() << endl;
                        cout << "Position Y: " << shapes[i]->GetY() << endl;
                        cout << "Height: " << shapes[i]->GetHeight() << endl;
                        cout << "Width: " << shapes[i]->GetWidth() << endl;
                    }
                    cout << "Select the poligon to modify: \n-1 to exit" << endl;
                    cin >> select2;
                    if(select2==-1){
                    break;}
                    if(select2>=nShapes || select2<-1){
                        cout<<"shape does not exist"<<endl;
                    }
                    else
                    {
                        for (int i = 0; i < nShapes; i++)
                        {
                            cout<<"1 to change Hight position\n2 to change Width position\n3 to change text\n0 to exit"<<endl;
                            cin>>select3;
                            switch(select3){
                                case 1:
                                    cout<<"set Hight at"<<endl;
                                    cin>>val;
                                    if(shapes[i]->GetX()+val<=GRID_X&&val>0){
                                        shapes[i]->SetHeight(val);
                                    }
                                    else{
                                    cout<<"Value not inbound"<<endl;
                                    }
                                break;
                                case 2:
                                    cout<<"set Widht at"<<endl;
                                    cin>>val;
                                    if(shapes[i]->GetY()+val<=GRID_Y&&val==0){
                                        shapes[i]->SetWidth(val);
                                    }
                                    else{
                                    cout<<"Value not inbound"<<endl;
                                    }
                                break;
                                case 3:
                                    cout << "Set Text at: " << endl;
                                    getline(cin >> ws, str);
                                    shapes[i]->SetText(str.c_str());
                                break;
                                default:
                                break;
                            }
                        }
                    }
                }
                break;
                case 3:
                if(nShapes==0){
                cout<<"No figures"<<endl;
                break;
                }
                while(true)
                {
                    for (int i = 0; i < nShapes; i++)
                    {
                        cout << "Figura numero: " << i << "\nTipo: ";
                        switch (shapes[i]->GetType())
                        {
                            case 0: cout << "Rettangolo"; break;
                            case 1: cout << "Rombo"; break;
                            case 2: cout << "Triangolo Rettangolo"; break;
                            default: cout << "Unknown"; break;
                        }
                        cout << endl;
                        cout << "Position X: " << shapes[i]->GetX() << endl;
                        cout << "Position Y: " << shapes[i]->GetY() << endl;
                        cout << "Height: " << shapes[i]->GetHeight() << endl;
                        cout << "Width: " << shapes[i]->GetWidth() << endl;
                    }
                    cout << "Select the poligon to modify: \n-1 to exit" << endl;
                    cin >> select2;
                    if(select2==-1){
                    break;}
                    if(select2>=nShapes || select2<-1){
                        cout<<"shape does not exist"<<endl;
                    }
                    else
                    {
                        for (int i = 0; i < nShapes; i++)
                        {
                            cout<<"1 to change X position\n2 to change Y position\n3 to change hight\n4 to change width\n0 to exit"<<endl;
                            cin>>select3;
                            switch(select3){
                                case 0:
                                break;
                                case 1:
                                cout<<"set X at"<<endl;
                                cin>>val;
                                if(shapes[i]->GetHeight()+val<=GRID_X&&val>=0){
                                    shapes[i]->SetX(val);
                                }
                                else{
                                cout<<"Value not inbound"<<endl;
                                }
                                break;
                                case 2:
                                cout<<"set Y at"<<endl;
                                cin>>val;
                                if(shapes[i]->GetWidth()+val<=GRID_Y&&val>=0){
                                    shapes[i]->SetY(val);
                                }
                                else{
                                cout<<"Value not inbound"<<endl;
                                }
                                break;
                                case 3:
                                cout<<"set Hight at"<<endl;
                                cin>>val;
                                if(shapes[i]->GetX()+val<=GRID_X&&val>0){
                                    shapes[i]->SetHeight(val);
                                }
                                else{
                                cout<<"Value not inbound"<<endl;
                                }
                                break;
                                case 4:
                                cout<<"set Widht at"<<endl;
                                cin>>val;
                                if(shapes[i]->GetY()+val<=GRID_Y&&val==0){
                                    shapes[i]->SetWidth(val);
                                }
                                else{
                                cout<<"Value not inbound"<<endl;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
        }
    }


    return 0;
}
