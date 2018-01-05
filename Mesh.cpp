/*
 * Mesh.cpp
 *
 *  Created on: 11 de dez de 2017
 *      Author: rafael
 */

#include "headers.h"




Mesh::Mesh() {
	// TODO Auto-generated constructor stub

}

GLuint Mesh::getMeshTex() const {
	return meshTex;
}

void Mesh::setMeshTex(GLuint meshTex) {
	this->meshTex = meshTex;
}

Mesh::~Mesh() {
	// TODO Auto-generated destructor stub
}

bool Mesh::loadMesh(string path){
	vector<int> vertIndex, uvIndex, normIndex;//indexadores para vertices, mapeamento de textura e normais
	vector<Vertec> tempVert;//vetor temporario de vertices
	vector<Vertec> tempTex;// vetor temporario de texturas
	vector<Vertec> tempNorm;

	FILE* file= fopen(path.data(), "r");
	if(file== NULL){
		cout<< "falha ao carregar o arquivo"<< endl;
		return false;
	}
	else{
		while(1){
			char lineHeader[128];
			int res= fscanf(file, "%s", lineHeader);
			if(res==EOF){
				break;
			}
			if(strcmp(lineHeader, "v") == 0){
				float x;
				float y;
				float z;
				fscanf(file, "%f %f %f\n", &x, &y, &z);
				Vertec t(x,y,z,0,0,0,0,0);
				tempVert.push_back(t);
			}
			else if(strcmp(lineHeader,"vt")==0){
				float u;
				float v;
				fscanf(file, "%f %f\n", &u, &v);
				Vertec t(0,0,0,u,v,0,0,0);
				tempTex.push_back(t);
			}
			else if(strcmp(lineHeader, "vn")==0){
				float xn;
				float yn;
				float zn;
				fscanf(file, "%f %f %f\n", &xn, &yn, &zn);
				Vertec t(0,0,0,0, 0, xn,yn,zn);
				tempNorm.push_back(t);
			}
			else if(strcmp(lineHeader, "f")==0){
				string v1, v2, v3;
				unsigned int vertInd[3], uvInd[3], normInd[3];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertInd[0], &uvInd[0], &normInd[0], &vertInd[1], &uvInd[1], &normInd[1], &vertInd[2], &uvInd[2], &normInd[2]);
				if(matches !=9){
					printf("QUantidade de valores lidos diferente doesperado. Falha ao ler uma linha de face");
					return false;
				}
				//Cria uma lista com os índices na ordem apropriada para o desenho das faces
				//Esta é a lista de índices de vértices
				vertIndex.push_back(vertInd[0]);
				vertIndex.push_back(vertInd[1]);
				vertIndex.push_back(vertInd[2]);
				//Esta é a lista de índices de mapeamento de textura
				uvIndex.push_back(uvInd[0]);
				uvIndex.push_back(uvInd[1]);
				uvIndex.push_back(uvInd[2]);
				// Esta é a lista de índices de normais
				normIndex.push_back(normInd[0]);
				normIndex.push_back(normInd[1]);
				normIndex.push_back(normInd[2]);
			}
		}
		for(unsigned int i=0; i<vertIndex.size(); i++){
			Vertec tempv(tempVert[vertIndex[i]-1].X,tempVert[vertIndex[i]-1].Y,tempVert[vertIndex[i]-1].Z,tempTex[uvIndex[i]-1].U,tempTex[uvIndex[i]-1].V, tempNorm[normIndex[i]-1].nX,tempNorm[normIndex[i]-1].nY,tempNorm[normIndex[i]-1].nZ);
			verts.push_back(tempv);
		}
	return true;
	}
}
void Mesh::draw(){



		for( unsigned int i=0; i<verts.size(); i=i+3){
			glBegin(GL_TRIANGLES);
				for(unsigned int j=i; j<i+3; j++){
					glNormal3f(verts[j].nX,verts[j].nY,verts[j].nZ);
					glTexCoord2f(verts[j].U ,verts[j].V);
					glVertex3f(verts[j].X,verts[j].Y,verts[j].Z);

				}
			glEnd();
		}

}
