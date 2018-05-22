///Результат сортировки записывается в тот же (сортируемый) файл base.txt
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void simple(char *name){
  int a1, a2, k, i, j, kol, tmp;
  FILE *f, *f1, *f2;
  kol = 0;
  if ( (f = fopen(name,"r")) == NULL )
    printf("\nИсходный файл не может быть прочитан...");
  else {
    while ( !feof(f) ) {
      fscanf(f,"%d",&a1);
      kol++;
    }
    fclose(f);
  }
  k = 1;
  while ( k < kol ){
    f = fopen(name,"r");
    f1 = fopen("smsort_1","w");
    f2 = fopen("smsort_2","w");
    if ( !feof(f) ) fscanf(f,"%d",&a1);
    while ( !feof(f) ){
      for ( i = 0; i < k && !feof(f) ; i++ ){
        fprintf(f1,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
      for ( j = 0; j < k && !feof(f) ; j++ ){
        fprintf(f2,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
    }
    fclose(f2);
    fclose(f1);
    fclose(f);

    f = fopen(name,"w");
    f1 = fopen("smsort_1","r");
    f2 = fopen("smsort_2","r");
    if ( !feof(f1) ) fscanf(f1,"%d",&a1);
    if ( !feof(f2) ) fscanf(f2,"%d",&a2);
    while ( !feof(f1) && !feof(f2) ){
      i = 0;
      j = 0;
      while ( i < k && j < k && !feof(f1) && !feof(f2) ) {
        if ( a1 < a2 ) {
          fprintf(f,"%d ",a1);
          fscanf(f1,"%d",&a1);
          i++;
        }
        else {
          fprintf(f,"%d ",a2);
          fscanf(f2,"%d",&a2);
          j++;
        }
      }
      while ( i < k && !feof(f1) ) {
        fprintf(f,"%d ",a1);
        fscanf(f1,"%d",&a1);
        i++;
      }
      while ( j < k && !feof(f2) ) {
        fprintf(f,"%d ",a2);
        fscanf(f2,"%d",&a2);
        j++;
      }
    }
    while ( !feof(f1) ) {
      fprintf(f,"%d ",a1);
      fscanf(f1,"%d",&a1);
    }
    while ( !feof(f2) ) {
      fprintf(f,"%d ",a2);
      fscanf(f2,"%d",&a2);
    }
    fclose(f2);
    fclose(f1);
    fclose(f);
    k *= 2;
  }
  remove("smsort_1");
  remove("smsort_2");
  cout <<"\nСортировка выполнена успешно!\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sv(char *name){
	int a1, i, kol,min;
  kol = 0;
  ifstream f1;
  ofstream f2;
  ofstream f3;
  f1.open(name);
  while (!f1.eof()){
      f1 >> a1;
      kol++;
  }
	f1.close();
	f2.open("result.txt");
	while(kol-1>0){
		f1.open(name);//o
		min=999999;
		while(!f1.eof()){
			f1 >> a1;
			if(a1<min){min=a1;}
		}
		f2<<min<<" ";
		kol--;
		f1.close();//z
		f1.open(name);
		f3.open("vrem.txt");
		while(!f1.eof()){
			f1 >> a1;
			if(a1!=min){f3<<a1<<" ";}
		}
		f1.close();
		f3.close();
		ofstream f1;
		f1.open(name);
		ifstream f3;
		f3.open("vrem.txt");
		while(!f3.eof()){
			f3 >> a1;
			f1<<a1<<" ";
		}
		f1.close();
		f3.close();
	}
	f2.close();
    ifstream f4;
	ofstream f5;
	f4.open("result.txt");
	f5.open(name);
	while(1){
		f4>>a1;
		if(f4.eof()){break;}
		f5<<a1<<" ";
	}
	f4.close();
	f5.close();
	remove("vrem.txt");
	remove("result.txt");
	cout <<"\nСортировка выполнена успешно!\n";
}


int main(){
setlocale(LC_ALL,"rus");
int choice;
label0:
cout << "1. Прямое слияние\n2. Своя сортировка\n5. Выход\n";
cin>>choice;
/////////////////
if(choice==1){
	simple("base.txt");
}

////////////////////
else if(choice==2){
	sv("base.txt");
}
///////////////
else if(choice==5){
	system("pause");
return 0;
}
else {
cout<<"\nНекорректное число, повторите ввод\n";
goto label0;
}
system("pause");
return 0;
}