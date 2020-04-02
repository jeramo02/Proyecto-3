#pragma once
#include "Component.h"

// Componentes de entidades
#include "GmInputComponent.h"
#include "RenderComponent.h"
#include "InputComponent.h"
#include "TransformComponent.h"

#define CREATE_FACTORY(x) class x##Factory {public: x##Component* Create(){ return new x##Component();}}
#define GENERATE_COMPONENT(x)  new x##Factory()->Create(); 
#define DECLARE_COMPONENT(x) x##Component* Comp_ = GENERATE_COMPONENT(x);

CREATE_FACTORY(GmInput);
CREATE_FACTORY(Render);
CREATE_FACTORY(Input);
CREATE_FACTORY(Transform);
/////////////////////////Aclaraciones///////////////////////////////

/*

Al crear un nuevo tipo de componente es IMPORTANTE DEJAR LA CONSTRUCTORA VACIA para usar las factorias.
Lo que hasta ahora se encontraba en los PARAMETROS DEL CONTRUCTOR debe ir EN EL METODO VIRTUAL Init() que 
heredan de Component.h y deben implementar

Debajo de la linea 6, usar la funcion CREATE_FACTORY(##x) donde ##x es el prefijo del componente.

	Ejemplo:

		RenderComponent -> (Render)Component // ##x --> Render


1) Incluir el nuevo componente en ComponentFactory.h
2) Declarar la nueva factoria
3) Incluir ComponentFactory.h donde se requiera

Cuando est�Ehecho el paso de datos para crear entidades del todo, realizar una MACRO para llamar a x constructora recibiendo solo el prefijo ##x

*/