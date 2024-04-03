#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>

using namespace std;

void filebug(){
	cout<<"\n\n";
    cout<<"**********";
    cout<<"FILING A BUG";
    cout<<"***********\n";
    cout<<"\n";
 
    // Trenutacno vrijeme
    time_t CurrentTime;
    time(&CurrentTime);
    char name[20], btype[50],fname[50];
    char bdescription[1000];
    char bpriority[30];
    int bstatus;
    
    //Stvara unikantan id za svaki bug
	string s;
    int len=6;
    static const char brcifra[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        s += brcifra[rand() % (sizeof(brcifra) - 1)];
    }

    
    FILE* ptr;
    
    // Korisnicko ime
    cout<<"Enter your name:\n";
    scanf("%s", name);
    cout<<"\n";
    cout<<"Name the report:\n";
    scanf("%s", fname);
    cout<<"\n";
    char ex[] = ".txt";
    strcat(fname, ex);
    
    // Naziv datoteke
    cout<<"Filename :"<<fname<<"\n";
    ptr = fopen(fname, "w");
    cout<<"\n";
    
    // Slucaj kada se datoteka ne može kreirati
    if (ptr == NULL)
        cout<<"cannot create file!!!\n";
    fprintf(ptr, "DATE AND TIME : %s",ctime(&CurrentTime));
    
    // ID greške
    fprintf(ptr, "BUG ID    :%s\n", s.c_str());
    // Dodavanje novog reda u tekstualnu datoteku
    fprintf(ptr, "\n");
    
    // ID greške
    cout<<"BUG ID: "<<s.c_str()<<"\n";
    fprintf(ptr, "BUG FILED BY: %s\n", name);
    fprintf(ptr, "\n");
    cout<<"\n";
    cout<<"Enter bug type:\n";
    scanf(" %[^\n]", btype);
    
    // Vrsta greške
    fprintf(ptr, "TYPE OF BUG: %s", btype);
    fprintf(ptr, "\n");
    
    // Prioritet greške
    cout<<"Enter bug priority:\n";
    scanf(" %[^\n]s", bpriority);
    fprintf(ptr, "BUG PRIORITY: %s\n",bpriority);
    fprintf(ptr, "\n");
    
    // Opis greške
    cout<<"Enter the bug description:\n";
    scanf(" %[^\n]s", bdescription);
    fprintf(ptr, "BUG DESCRIPTION: %s\n",bdescription);
    fprintf(ptr, "\n");
    cout<<"Status of bug:\n";
    cout<<"1.NOT YET ASSIGNED\n";
    cout<<"2.IN PROCESS\n3.FIXED\n";
    cout<<"4.DELIVERED\n\nENTER YOUR CHOICE:";
 
    int j;
    scanf("%d", &j);
 
    // Datum i vrijeme izrade grešaka
    fprintf(ptr, "DATE AND TIME: %s",
            ctime(&CurrentTime));
 
    fprintf(ptr, "BUG STATUS:");
 
    // Prebacivanje za status greške
    switch (j) {
    case 1:
        fprintf(ptr, "NOT YET ASSIGNED\n");
        break;
    case 2:
        fprintf(ptr, "IN PROCESS\n");
        break;
    case 3:
        fprintf(ptr, "FIXED\n");
        break;
    case 4:
        fprintf(ptr, "DELIVERED\n");
        break;
    default:
        printf("invalid choice\n");
        break;
    }
 
    fclose(ptr);
}
void changestatus(){
	cout<<"\n";
	cout<<"*************";
    cout<<"Change status";
    cout<<"**************\n";
    cout<<"\n";
 
    //Cita trenutacno sistemsko vrijeme
    time_t CurrentTime;
    time(&CurrentTime);
 
    FILE* file;
    char fname[50];
 
    // Ime file-a
    cout<<"Enter file name:\n";
    scanf("%s", fname);
    char ex[] = ".txt";
    //spaja nizove ex i name
    strcat(fname, ex);
 
    // Otvaranje greške u append modu
    file = fopen(fname, "a");
 
    cout<<"\n 1.NOT YET ASSIGNED\n";
    cout<<" 2.IN PROCESS\n 3.FIXED\n";
    cout<<" 4.DELIVERED\n\nENTER YOUR CHOICE:";
 
    // promjena statusa
    int k;
    scanf("%d", &k);
   //Ispis vremena u dokument
    fprintf(file, "\n");
    fprintf(file, "DATE AND TIME : %s",
            ctime(&CurrentTime));
   // promjena statusa
    fprintf(file, "BUG STATUS:");
 
    // Promjena statusa na osnovu korisnickog unosa
    switch (k) {
    case 1:
        fprintf(file, "NOT YET ASSIGNED\n");
        break;
    case 2:
        fprintf(file, "IN PROCESS\n");
        break;
    case 3:
        fprintf(file, "FIXED\n");
        break;
    case 4:
        fprintf(file, "DELIVERED\n");
        break;
    default:
        cout<<"invalid choice\n";
        break;
    }
    fclose(file);
}
void report(){
	cout<<"\n";
	cout<<"**********";
    cout<<"REPORT";
    cout<<"**********\n";
    cout<<"\n";
 
    FILE* fp;
    char fname[50];
 
    // traženje naziva datoteke
    cout<<"Enter file name:\n";
    scanf("%s", fname);
    char ex[] = ".txt";
    //spaja nizove ex i name
    strcat(fname, ex);
   //otvara datoteku u read only modu
    fp = fopen(fname, "r");
 
    char ch;
    ch = getc(fp);
 
    while (ch != EOF) {
        cout<<ch;
        ch = getc(fp);
    }
 
    fclose(fp);
    getch();
}
int main()
{
    cout<<("***************");
    cout<<("BUG TRACKING SYSTEM");
    cout<<("***************\n");
  
    int br, i = 1;
    int id = 0;
    
    while (i != 0) {
        cout<<"\n1. FILE A NEW BUG\n";
        cout<<"2. CHANGE THE STATUS OF THE BUG\n";
        cout<<"3. GET BUG REPORT\n4. EXIT";
        cout<<"\n\nENTER YOUR CHOICE:";
        br=getch();
        switch (br) {
        case '1':
            id++;
            filebug();
            break;
            case '2':
            changestatus();
            break;
        case '3':
            report();
            break;
        case '4':
            i = 0;
            break;
        default:
            cout<<"\ninvalid entry";
            break;
                 }
    }
    return 0;
}
        
 
