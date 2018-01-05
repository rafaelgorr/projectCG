/*
 * Reader.h
 *
 *  Created on: 27 de set de 2017
 *      Author: rafael
 */

#ifndef READER_H_
#define READER_H_
#include "headers.h"



class Reader {

public:
	Reader();
	virtual ~Reader();
	void      readXML       (int argc, char** argv);
};

#endif /* READER_H_ */
