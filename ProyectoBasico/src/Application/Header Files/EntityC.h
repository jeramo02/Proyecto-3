﻿#pragma once

#include <OgreString.h>
#include <OgreSceneNode.h>
#include <vector>
#include "Component.h"

class EntityC {
public:
	EntityC(Ogre::String id);
	~EntityC();

	// A�adir/quitar un componente
	void AddComponent(Component* c);
	void DelComponent(Component* c);

	// Metodo para coger el nodo
	void setNode(Ogre::SceneNode* node);
	void setActive(bool sw);
	bool isActive();
	// ID de la entidad
	Ogre::String _id;

private:
	// Vector de componentes
	std::vector<Component*> _components;

	// Vector3 para gestionar la posicion
	Ogre::Vector3 _position;


	// Puntero al nodo de la escena
	Ogre::SceneNode* _Node = nullptr;

	bool _active;
};