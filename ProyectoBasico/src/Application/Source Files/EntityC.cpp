#include "EntityC.h"

EntityC::EntityC(Ogre::String id) : _id(id) {
	_position = Ogre::Vector3(0, 0, 0);
}

EntityC::~EntityC() {}

void EntityC::setNode(Ogre::SceneNode* node) {
	_Node = node;
	_position = _Node->getPosition();
}

void EntityC::AddComponent(Component* c) {
	_components.push_back(c);
}

void EntityC::DelComponent(Component* c) {
	std::vector<Component*>::iterator pos =
		std::find(_components.begin(), _components.end(), c);
	if (pos != _components.end()) {
		_components.erase(pos); 
	}
}