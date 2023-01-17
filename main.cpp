#include <iostream>
#include <iomanip>

using namespace std;

void podpunkt_1(char **A, int n)
{
    cout<<"1)"<<endl;
  for( int i = 0; i < n; i++ )
  {
      int c=0;
      //zmienna pozwalajaca policzyc ilu sasiadowa ma wierzcholek
      cout<<"wierzcholek "<<i<<" "<<"sasiedzi to wierzcholki numer"<<":";
      for( int j = 0; j < n; j++ )
    //przeszukujemy i-ty wiersz jesli jest w nim 1 to znalezlismy sasiada
      {
          if(A[i][j]==1)
          {
             c++;
             cout<<j<<",";
          }
      }


      if(c==0)
            cout<<"brak";//jesli nie ma sasiadow
      cout<<endl;
  }
}
void podpunkt_2(char **A, int n,int m)
{
    int c=0;
    cout<<"2)"<<endl;
  for( int i = 0; i < n; i++ )
  {
      int b=0;
      for( int j = 0; j < n; j++ )
        //przeszukujemy wiersz i-ty
      {
          if(A[i][j]==1)
          //jesli komorka jest rowna 1 wierzcholek jest sasiadanem
          {
             b++;//zliczamy sasiadow
          }

      }
       if(b==m)
       {
           c++;
           cout<<"wierzcholek "<<i<<" jest sasiadem kazdego wierzcholka"<<endl;
           }
  }
  if(c==0)
cout<<"brak wierzcholkow,ktore sa sasiadami kazdego wierzcholka"<<endl;

}
void podpunkt_3(char **A, int n)
{
    cout<<"3)"<<endl;
  for(int i = 0; i < n; i++ )
  {
      int wychodzacy=0;
      cout<<"wierzcholek "<<i<<" "<<"stopien wychodzacy"<<":";

      for( int j = 0; j < n; j++ )//przeszukujemy wiersz
      {
          if(A[i][j]==1)
          {
             wychodzacy++;//zliczmy sasiadow
          }
      }
      cout<<wychodzacy<<endl;
  }
}
void podpunkt_4(char **A, int n)
{
    cout<<"4)"<<endl;
  for(int i = 0; i < n; i++ )
  {
      int wchodzacy=0;
      cout<<"wierzcholek "<<i<<" "<<"stopien wchodzacy"<<":";

      for(int j = 0; j < n; j++ )//przeszukujemy kolumne
      {
          if(A[j][i]==1)
          {
             wchodzacy++;
          }
      }
      cout<<wchodzacy<<endl;
  }
}
void podpunkt_5(char **A, int n)
{
    int c=0;
    cout<<"5)"<<endl;
  for(int i = 0; i < n; i++ )
  {
      int b=0;
      for(int j = 0; j < n; j++ )
      {
          if(A[j][i]==1 || A[i][j]==1)//przeszukujemy kolumne i wiersza to lub to musi byc rowne jeden
          {
             b++;
          }
      }
      if(b==0)
      {
          cout<<"wierzcholek "<<i<<" jest izolowany"<<endl;
          c++;
      }
  }
  if(c==0) cout<<"brak wierzcholkow izolowanych"<<endl;
}
void podpunkt_6(char **A, int n)
{
    cout<<"6)"<<endl;
  int c=0;
  for(int i = 0; i < n; i++ )//w cenu sprawdzenia wartosci i-tej kolumny i-tego wiersza
  {
      if(A[i][i]==1)
        {
            cout<<"wierzcholek "<<i<<" posiada petle"<<endl;
            c++;//zliczanie ilosci petli
        }
  }
  if(c==0) cout<<"brak petli"<<endl;//jesli nie ma petli
}
void podpunkt_7(char **A, int n)
{
    int a,c=0;
    cout<<"7)"<<endl;
  for(int i = 0; i < n; i++ )
  {
      int a;
      if(i==a) i++;//aby nie wypisywac dwa razy tego samego tylko w innej kolejnosci wierzcholkow
      for(int j = 0; j < n; j++ )
      {
          if(A[j][i]==1&&A[i][j]==1&&j!=i)
          {
             cout<<"wierzcholek "<<i<<" i "<<j<<" laczy krawedz dwukierunkowa"<<endl;
             a=j;
             c++;//zlicenie ilosci krawedzi dwukierunkowych
          }
      }
  }
  if(c==0) cout<<"nie ma wierzcholkow ktore maja krawedz dwukierunkowa"<<endl;
  //aby zaznaczyc ze ich nie ma
}

int main( )
{
  int n, m,a,b;
  char ** A;
  cout<<"Podaj ilosc wierzcholkow"<<endl;
  cin >> n;//Czytamy liczbe wierzcholkow
  cout<<"Podaj ilosc krawedzi"<<endl;
  cin >> m;//  wczytujemy krawędzi
  cout<<"podaj liste krawedzi"<<endl;
  A = new char *[n];  // Tworzymy tablice wskaznikow

  for(int i = 0; i < n; i++ )
    A [i] = new char [n]; // Tworzymy wiersze
  // Macierz wypelniamy zerami
  for(int i = 0; i < n; i++ )
    for(int j = 0; j < n; j++ ) A [ i ][ j ] = 0;
  // Odczytujemy kolejne definicje krawêdzi
  for(int i = 0; i < m; i++ )
  { //cout<<"podaj wierzcholek startowy numer:"<<i<<endl;
    cin >> a;// Wierzcholek startowy krawedzi
    //cout<<"podaj wierzcholek koncowy numer:"<<i<<endl;
    cin>> b;// Wierzcholek koncowy krawedzi
    A [a][b] = 1; // krawedz a,b
  }
  cout << endl;
  //wywolania funkcji
  podpunkt_1(A,n);
  podpunkt_2(A,n,m);
  podpunkt_3(A,n);
  podpunkt_4(A,n);
  podpunkt_5(A,n);
  podpunkt_6(A,n);
  podpunkt_7(A,n);
  return 0;
}
