/*
 * Mesh.h
 *
 *  Created on: 11 de dez de 2017
 *      Author: rafael
 */

#ifndef MESH_H_
#define MESH_H_


#include <vector>
#include "Vertec.h"
class Mesh {
	std::vector<Vertec> verts;//Lista ordenada de vertices para o desenho do modelo
	GLuint meshTex;//Index de textura carregada via imageLoader

	public:
		Mesh();
		bool loadMesh(std::string path);//Path é o caminho para o arquivo .obj e deve conter o nome do arquivo.obj
		void loadMeshTex(GLuint mtx){meshTex=mtx;};//mtx é o índice da textura carregada em OpenGL através do ImageLoader
		void draw();
		~Mesh();
	GLuint getMeshTex() const;
	void setMeshTex(GLuint meshTex);
};

#endif /* MESH_H_ */
