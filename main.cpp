#include <SFML/Graphics.hpp>
#include<iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct snakes{
int coloana;
int linie;
int directie;
int folosit;
sf::RectangleShape corp;
int textura;};

struct mancare{
int coloana;
int linia;
int exista;
sf::RectangleShape corp;};

void updateSnake(snakes snake[100],int numarCelule)
{
 for(int i=numarCelule-1;i>0;i--)
 {snake[i].directie=snake[i-1].directie;
  snake[i].folosit=1;
 }}

 void adaugareCelula(snakes snake[100],int numarCelule)
{snake[numarCelule-1].linie=snake[numarCelule-2].linie;
snake[numarCelule-1].coloana=snake[numarCelule-2].coloana;

}
 void miscareSnake(snakes snake[100],int &numarCelule,int nrColLin,int terenSnakes[15][15],mancare &food,int &mort)
 {for(int i=0;i<numarCelule;i++)
 {if(snake[i].directie!=0)
  {if(snake[i].directie==1)
  snake[i].linie=(snake[i].linie+1)%nrColLin;
  if(snake[i].directie==-1)
  snake[i].linie=(snake[i].linie-1)%nrColLin;
  if(snake[i].directie==2)
  snake[i].coloana=(snake[i].coloana+1)%nrColLin;
  if(snake[i].directie==-2)
  snake[i].coloana=(snake[i].coloana-1)%nrColLin;
  if(snake[i].coloana<0)
    snake[i].coloana=14;
  if(snake[i].linie<0)
    snake[i].linie=14;
  if(i==0)
  {if(terenSnakes[snake[i].linie][snake[i].coloana]==2)
  {numarCelule++;
  adaugareCelula(snake,numarCelule);
   food.exista=0;}
   if(terenSnakes[snake[i].linie][snake[i].coloana]==1)
    mort=1;
  }}

 }}
 void plasareTextura(sf::RectangleShape &celula,sf::Texture &texturi)
 {celula.setTexture(&texturi);
  celula.setTextureRect(sf::IntRect(0, 0, 250, 250));}
 void initSnake(snakes snake[100],int nrColLin,int nrCelule,sf::Texture texturi[16])
 {snake[0].folosit=1;
 snake[0].directie=1;
 snake[0].linie=nrColLin/2;
 snake[0].coloana=nrColLin/2;
 for(int i=1;i<nrCelule;i++)
 {snake[i].directie=0;
 snake[i].linie=snake[0].linie;
 snake[i].coloana=snake[0].coloana;
 plasareTextura(snake[i].corp,texturi[15]);}
 for(int i=1;i<100;i++)
 snake[i].directie=0;
 }
 void texturiSnake(snakes snake[100],mancare &food,sf::Texture texturi[16],int nrCelule)
 {plasareTextura(food.corp,texturi[10]);
 if(snake[0].directie==1)
plasareTextura(snake[0].corp,texturi[2]);
if(snake[0].directie==-1)
plasareTextura(snake[0].corp,texturi[0]);
if(snake[0].directie==2)
plasareTextura(snake[0].corp,texturi[1]);
if(snake[0].directie==-2)
plasareTextura(snake[0].corp,texturi[3]);
int dubla1=0,dubla2=0;
 for(int i=nrCelule-1;i>0;i--)
 {
     if(i==nrCelule-1)
{if(snake[i-1].directie==1)
plasareTextura(snake[i].corp,texturi[11]);
if(snake[i-1].directie==-1)
plasareTextura(snake[i].corp,texturi[13]);
if(snake[i-1].directie==2)
plasareTextura(snake[i].corp,texturi[14]);
if(snake[i-1].directie==-2)
plasareTextura(snake[i].corp,texturi[12]);
}
 else if(snake[i+1].coloana>snake[i].coloana)
 {if(snake[i-1].linie==snake[i].linie)
  plasareTextura(snake[i].corp,texturi[5]);
  if(snake[i-1].linie>snake[i].linie)
  plasareTextura(snake[i].corp,texturi[7]);
  if(snake[i-1].linie<snake[i].linie)
  plasareTextura(snake[i].corp,texturi[8]);
 }
  else if(snake[i+1].coloana<snake[i].coloana)
 {if(snake[i-1].linie==snake[i].linie)
  plasareTextura(snake[i].corp,texturi[5]);
  if(snake[i-1].linie>snake[i].linie)
  plasareTextura(snake[i].corp,texturi[6]);
  if(snake[i-1].linie<snake[i].linie)
  plasareTextura(snake[i].corp,texturi[9]);
 }
  else if(snake[i+1].linie>snake[i].linie)
 {if(snake[i-1].coloana==snake[i].coloana)
  plasareTextura(snake[i].corp,texturi[4]);
  if(snake[i-1].coloana>snake[i].coloana)
  plasareTextura(snake[i].corp,texturi[7]);
  if(snake[i-1].coloana<snake[i].coloana)
  plasareTextura(snake[i].corp,texturi[6]);
 }
 else if(snake[i+1].linie<snake[i].linie)
 {if(snake[i-1].coloana==snake[i].coloana)
  plasareTextura(snake[i].corp,texturi[4]);
  if(snake[i-1].coloana>snake[i].coloana)
  plasareTextura(snake[i].corp,texturi[8]);
  if(snake[i-1].coloana<snake[i].coloana)
  plasareTextura(snake[i].corp,texturi[9]);
 }}}

void initTeren(int terenSnakes[15][15],int nrColLin)
{for(int i=0;i<nrColLin;i++)
for(int j=0;j<nrColLin;j++)
terenSnakes[i][j]=0;
}
int interactiuneCuJucatorulTastatura(sf::Event eveniment,int &tastaApasata)
{int directie=0;
     if (eveniment.type == sf::Event::KeyPressed)
       {if (eveniment.key.code == sf::Keyboard::Left)
          {directie=-2;
          tastaApasata=1;}
        if (eveniment.key.code == sf::Keyboard::Up)
          {directie=-1;
          tastaApasata=1;}
        if (eveniment.key.code == sf::Keyboard::Down)
          {directie=1;
          tastaApasata=1;}
        if (eveniment.key.code == sf::Keyboard::Right)
          {directie=2;
          tastaApasata=1;}
        }
   return directie;}

   void stergereMatrice(int terenSnakes[15][15],int nrColLin)
   {for(int i=0;i<nrColLin;i++)
for(int j=0;j<nrColLin;j++)
    if(terenSnakes[i][j]==1)
    terenSnakes[i][j]=0;}

    void recreereMatrice(int terenSnakes[15][15],snakes snake[100],int nrCelule)
{
    for(int i=0;i<nrCelule;i++)
if(snake[i].directie!=0)
terenSnakes[snake[i].linie][snake[i].coloana]=1;

}

void initCorpSarpe(snakes snake[100],mancare &food)
{for(int i=0;i<100;i++)
{snake[i].corp.setSize(sf::Vector2f(40, 40));
 snake[i].corp.setPosition(-200,-200);}
 food.corp.setSize(sf::Vector2f(40, 40));
 food.corp.setPosition(-200,-200);}

void adaugareMancare(int terenSnakes[15][15],int nrColLin,mancare &food)
{int ok=0,x,y;
    while(ok==0)
{x=rand()%nrColLin;
y=rand()%nrColLin;
if(terenSnakes[x][y]==0)
    {terenSnakes[x][y]=2;
     food.linia=x;
     food.coloana=y;
     food.corp.setPosition(40*y,40*x);
    ok=1;}}}
void updatePosSnake(snakes snake[100],int nrCelule)
{for(int i=0;i<nrCelule;i++)
snake[i].corp.setPosition(snake[i].coloana*40,snake[i].linie*40);}

void jocSnake(snakes snake[100],int nrColLin,sf::Texture texturi[16])
{sf::RenderWindow win(sf::VideoMode(nrColLin*40, nrColLin*40), "Snake");
win.setFramerateLimit(60);
int numarCelule=5,frama=0,terenSnakes[15][15],tastaApasata=0,directieNoua,mort=0;
mancare food;
food.exista=0;
initTeren(terenSnakes,nrColLin);
initSnake(snake,nrColLin,numarCelule,texturi);
initCorpSarpe(snake,food);
    while (win.isOpen())
     {if(frama%8==0 && mort==0)
     {
         miscareSnake(snake,numarCelule,nrColLin,terenSnakes,food,mort);
         texturiSnake(snake,food,texturi,numarCelule);
     updateSnake(snake,numarCelule);

     if(food.exista==0)
     {adaugareMancare(terenSnakes,nrColLin,food);
     food.exista=1;}
     stergereMatrice(terenSnakes,nrColLin);
     recreereMatrice(terenSnakes,snake,numarCelule);
     updatePosSnake(snake,numarCelule);}
     frama++;
         win.clear();
if(food.exista==1)
    win.draw(food.corp);
    for(int i=0;i<numarCelule;i++)
        if(snake[i].directie!=0)
        win.draw(snake[i].corp);

        win.display();
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed )
            win.close();
            directieNoua=interactiuneCuJucatorulTastatura(event,tastaApasata);
        }
      if(tastaApasata)
{tastaApasata=0;
if(directieNoua!=0)
 snake[0].directie=directieNoua;
}}}

void incarcareTexturi(sf::Texture texturi[16])
{
    texturi[0].loadFromFile("Texturi\\cap1.jpg");
    texturi[1].loadFromFile("Texturi\\cap2.jpg");
    texturi[2].loadFromFile("Texturi\\cap3.jpg");
    texturi[3].loadFromFile("Texturi\\cap4.jpg");
    texturi[4].loadFromFile("Texturi\\verticala.jpg");
    texturi[5].loadFromFile("Texturi\\orizontala.jpg");
    texturi[6].loadFromFile("Texturi\\1.jpg");
    texturi[7].loadFromFile("Texturi\\2.jpg");
    texturi[8].loadFromFile("Texturi\\3.jpg");
    texturi[9].loadFromFile("Texturi\\4.jpg");
    texturi[10].loadFromFile("Texturi\\sobolan.jpg");
    texturi[11].loadFromFile("Texturi\\coada1.jpg");
    texturi[12].loadFromFile("Texturi\\coada2.jpg");
    texturi[13].loadFromFile("Texturi\\coada3.jpg");
    texturi[14].loadFromFile("Texturi\\coada4.jpg");
    texturi[15].loadFromFile("Texturi\\negru.jpg");

}


int main()
{srand(time(NULL));
sf::Texture texturi[16];
incarcareTexturi(texturi);
    snakes snake[100];
jocSnake(snake,15,texturi);
    return 0;
}
