/*
 * Reader.cpp
 *
 *  Created on: 27 de set de 2017
 *      Author: rafael
 */

#include "Reader.h"
#include "globals.h"

Reader::Reader() {
	// TODO Auto-generated constructor stub

}

Reader::~Reader() {
	// TODO Auto-generated destructor stub
}

void Reader::readXML (int argc, char** argv)
{
  string path(argv[1]);
  string pathXML = path + "config.xml";

  TiXmlDocument doc(pathXML.data());

  bool loadOkay = doc.LoadFile();
  if(!loadOkay)
  {
    cerr << "ERRO: Arquivo 'config.xml' nao encontrado." << endl;
    exit(1);
  }

  string pathArena, nameArena, typeArqArena;

  TiXmlHandle docHandle( &doc );
  TiXmlElement* fileArena = docHandle.FirstChild( "aplicacao" ).FirstChild( "arquivoDaArena" ).ToElement();
  TiXmlElement* playerInf = docHandle.FirstChild( "aplicacao" ).FirstChild( "jogador" ).ToElement();
  TiXmlElement* enemyInf = docHandle.FirstChild( "aplicacao" ).FirstChild( "inimigo" ).ToElement();
  TiXmlElement* obstacle = docHandle.FirstChild( "aplicacao" ).FirstChild( "obstaculo" ).ToElement();


  nameArena = fileArena->Attribute("nome");
  typeArqArena = fileArena->Attribute("tipo");
  pathArena = fileArena->Attribute("caminho");

  player = new Player(atof(playerInf->Attribute("velTiro")),atof(playerInf->Attribute("vel")));

  GLfloat enemySpeed, enemyBS, enemyFreq;

  enemySpeed = atof(enemyInf->Attribute("vel"));
  enemyBS = atof(enemyInf->Attribute("velTiro"));
  enemyFreq = atof(enemyInf->Attribute("freqTiro"));


  obstacleHeight = atof(obstacle->Attribute("altura"));

  settings.title = nameArena;


  TiXmlDocument svgDoc(( pathArena + nameArena + '.' + typeArqArena).data());

  loadOkay = svgDoc.LoadFile();
  if(!loadOkay)
  {
	cerr << "ERRO: Arquivo "<< nameArena <<'.' <<typeArqArena<< "' nao encontrado." << endl;
	exit(1);
  }
  TiXmlHandle docHandleSVG(&svgDoc);
  TiXmlElement* listCircles = docHandleSVG.FirstChild( "svg" ).FirstChild("circle").ToElement();


  string fill;
  Body *newCircle;
  for(;listCircles != NULL;listCircles = listCircles->NextSiblingElement())
  {
	  newCircle = new Body(atof(listCircles->Attribute("r")));
	  newCircle->setX(atof(listCircles->Attribute("cx")));
	  newCircle->setY(atof(listCircles->Attribute("cy")));
	  newCircle->setRadius(atof(listCircles->Attribute("r")));
	  newCircle->setId(atoi(listCircles->Attribute("id")));

	  fill = listCircles->Attribute("fill");


	  if(!fill.compare("red"))
	  {
		newCircle->setColorR(1);
		newCircle->setColor("red");
		newCircle->setRadius( atof(listCircles->Attribute("r")) );
		Enemy *enemy = new Enemy(enemyBS, enemySpeed);
		enemy->setBody(newCircle);
		enemy->setFreqShot(enemyFreq);
		enemy->setCollisionCircle(atof(listCircles->Attribute("r")));
		enemy->setHeight(atof(listCircles->Attribute("r")));

		speedShotEnem = enemyBS;
		enemies.insert(enemy);
		continue;
	  }

	  if(!fill.compare("black"))
		  obstacles.insert(newCircle);


	  if(!fill.compare("green"))
	  {
		newCircle->setColorG(1);
		newCircle->setColor("green");
		newCircle->setRadius( atof(listCircles->Attribute("r")) );
		player->setBody(newCircle);
		player->setCollisionCircle(atof(listCircles->Attribute("r")));
		player->setHeight(atof(listCircles->Attribute("r")));

		continue;
	  }

	  if(!fill.compare("blue"))
	  {
		newCircle->setColorR(1);
		newCircle->setColorG(1);
		newCircle->setColorB(1);
		newCircle->setColor("blue");

		biggerCircle = newCircle;
		continue;

	  }

	  if(!fill.compare("white"))
	  {
		newCircle->setColorR(1);
		newCircle->setColorG(1);
		newCircle->setColorB(1);
		newCircle->setColor("white");
		centerCircle = newCircle;
		continue;
	  }


  }
  numberEnemies = enemies.size();

}

