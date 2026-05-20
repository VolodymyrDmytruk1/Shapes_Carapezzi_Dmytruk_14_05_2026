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
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    int select1 = -1;
    int select2 = -2;
    int select3 = -1;
    int val1,val2,val3,val4=0;
    string str="";

    while(true){
        cout << "1 Visualizza tutti i poligoni \n" << "2 Modifica le proprietà di un poligono\n" << "3 Sposta un poligono sulla griglia\n"
        << "4 Inserisci un nuovo poligono\n" << "5 Cancella un poligono\n" << "6 Cancella tutti i poligoni\n" << "0 Esci\n" << endl;

        cin >> select1;
        switch(select1)
        {
            case 1:
                if(nShapes==0)
                {
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
                    cout << "Select the poligon: \n-1 to exit" << endl;
                    cin >> select2;
                    if(select2==-1)
                    {
                    break;
                    }
                    if(select2>=nShapes || select2<-1)
                    {
                        cout<<"shape does not exist"<<endl;
                    }
                    else
                    {
                        shapes[select2]->Dump();
                    }
                }
                break;
            case 2:
                if(nShapes==0)
                {
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
                    if(select2==-1)
                    {
                    break;
                    }
                    if(select2>=nShapes || select2<-1)
                    {
                        cout<<"shape does not exist"<<endl;
                    }
                    else
                    {
                        cout<<"1 to change Hight\n2 to change Width\n3 to change text\n0 to exit"<<endl;
                        cin>>select3;
                        switch(select3)
                        {
                            case 1:
                                cout<<"set Hight at"<<endl;
                                cin>>val1;
                                if(shapes[select2]->GetX()+val1<=GRID_X&&val1>0)
                                {
                                    shapes[select2]->SetHeight(val1);
                                }
                                else
                                {
                                    cout<<"Value not inbound"<<endl;
                                }
                                break;
                            case 2:
                                cout<<"set Widht at"<<endl;
                                cin>>val1;
                                if(shapes[select2]->GetY()+val1<=GRID_Y&&val1>=0)
                                {
                                    shapes[select2]->SetWidth(val1);
                                }
                                else
                                {
                                    cout<<"Value not inbound"<<endl;
                                }
                                break;
                            case 3:
                                cout << "Set Text at: " << endl;
                                getline(cin >> ws, str);
                                shapes[select2]->SetText(str.c_str());
                                break;
                            default:
                                cout<<"Error in the selection"<<endl;
                                break;
                        }
                    }
                }
                break;
            case 3:
                if(nShapes==0)
                {
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
                    if(select2==-1)
                    {
                    break;
                    }
                    if(select2>=nShapes || select2<-1)
                    {
                        cout<<"shape does not exist"<<endl;
                    }
                    else
                    {
                        cout<<"1 to change X position\n2 to change Y position\n0 to exit"<<endl;
                        cin>>select3;
                        switch(select3)
                        {
                            case 0:
                                break;
                            case 1:
                                cout<<"set X at"<<endl;                                
                                cin>>val1;
                                if(shapes[select2]->GetHeight()+val1<=GRID_X&&val1>=0)
                                {
                                    shapes[select2]->SetX(val1);
                                }
                                else{
                                    cout<<"Value not inbound"<<endl;
                                }
                                break;
                            case 2:
                                cout<<"set Y at"<<endl;
                                cin>>val1;
                                if(shapes[select2]->GetWidth()+val1<=GRID_Y&&val1>=0)
                                {
                                    shapes[select2]->SetY(val1);
                                }
                                else{
                                    cout<<"Value not inbound"<<endl;
                                }
                                break;
                            default:
                                cout<<"Error in the selection"<<endl;
                                break;
                        }
                    }
                }
                break;
            case 4:
                cout<<"New poligon:\n1 Rectangle\n2 Rhombus\n3 RightTriangle\n0 Exit"<<endl;
                cin>>select2;
                switch(select2)
                {
                    case 1:
                        cout<<"Insert X position"<<endl;
                        cin>>val1;
                        cout<<"Insert Y position"<<endl;
                        cin>>val2;
                        cout<<"Insert Height"<<endl;
                        cin>>val3;
                        cout<<"Insert Width"<<endl;
                        cin>>val4;
                        if(val3+val1<=GRID_X&&val2+val4<=GRID_Y&&val1>=0&&val2>=0&&val3>0&&val4>0)
                        {
                            if(nShapes<MAX_SHAPES){
                                shapes[nShapes++] = new Rectangle(val1, val2, val3, val4);
                                cout<<"New Rectangle created"<<endl;
                            }
                            else{
                                cout<<"Too many shapes"<<endl;
                            }
                        }
                        else{
                            cout<<"Values not inbound"<<endl;
                        }
                        break;
                    case 2:
                        cout<<"Insert X position"<<endl;
                        cin>>val1;
                        cout<<"Insert Y position"<<endl;
                        cin>>val2;
                        cout<<"Insert Height"<<endl;
                        cin>>val3;
                        cout<<"Insert Width"<<endl;
                        cin>>val4;
                        if(val3+val1<=GRID_X&&val2+val4<=GRID_Y&&val1>=0&&val2>=0&&val3>0&&val4>0)
                        {
                            if(nShapes<MAX_SHAPES){
                                shapes[nShapes++] = new Rhombus(val1, val2, val3, val4);
                                cout<<"New Rhombus created"<<endl;
                            }
                            else{
                                cout<<"Too many shapes"<<endl;
                            }
                        }
                        else{
                            cout<<"Values not inbound"<<endl;
                        }
                        break;
                    case 3:
                        cout<<"Insert X position"<<endl;
                        cin>>val1;
                        cout<<"Insert Y position"<<endl;
                        cin>>val2;
                        cout<<"Insert Height"<<endl;
                        cin>>val3;
                        cout<<"Insert Width"<<endl;
                        cin>>val4;
                        if(val3+val1<=GRID_X&&val2+val4<=GRID_Y&&val1>=0&&val2>=0&&val3>0&&val4>0)
                        {
                            if(nShapes<MAX_SHAPES){
                                shapes[nShapes++] = new RightTriangle(val1, val2, val3, val4);
                                cout<<"New RightTriangle created"<<endl;
                            }
                            else{
                                cout<<"Too many shapes"<<endl;
                            }
                        }
                        else{
                            cout<<"Values not inbound"<<endl;
                        }
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"Error in the selection"<<endl;
                        break;
                }
                break;
            case 5:
                if(nShapes==0)
                {
                    cout<<"No figures"<<endl;
                    break;
                }
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
                if(select2==-1)
                {
                break;
                }
                if(select2>=nShapes || select2<-1)
                {
                    cout<<"shape does not exist"<<endl;                    }
                else
                {
                    delete shapes[select2];
                    shapes[select2] = nullptr;
                    for(int i = select2; i < nShapes - 1; i++)
                    {
                        shapes[i] = shapes[i + 1];
                    }
                    shapes[nShapes - 1] = nullptr;
                    nShapes--;
                }
                break;
            case 6:
                for(int i = 0; i < nShapes; i++)
                {
                    delete shapes[i];
                    shapes[i] = nullptr;
                }
                nShapes=0;
                break;
            case 0:
                for(int i = 0; i < nShapes; i++)
                {
                    delete shapes[i];
                    shapes[i] = nullptr;
                }
                return 0;
            default:
                cout<<"Error in the selection"<<endl;
                break;
        }
    }


    return 0;
}
