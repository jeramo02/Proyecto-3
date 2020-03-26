#pragma once
#include "OgreApp.h"
#include <ComponentFactory.h>
#include <list>
#include <stack>
#include <EntityC.h>

class Scene
{
private:
	std::list<EntityC*> entidades;
	std::list<EntityC*> _updates;
	//Por ahora lo har� el update
	//std::list<EntityC*> _handleEvents; 
	std::list<EntityC*> _render;
	RenderFactory* _rF;

public:
	Scene();
	void update();
	void render(OgreEasy::OgreApp * ogreApp);
	void push(EntityC* e);
};

