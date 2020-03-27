#include "Scene.h"
#include "RenderUtilities.h"
#include "InitOgre.h"


Scene::Scene()
{
	_rF = new RenderFactory();
}

Scene::Scene(std::string id) :_id(id)
{
	_rF = new RenderFactory();

}

void Scene::update()
{
	printf("UPDATE");
}

void Scene::render()
{
	/*for (auto i = entidades.begin(); i != entidades.end(); ++i) {
		RenderComponent* Rcomp = _rF->Create();
		Rcomp->Init((*i)->_id, ogreApp->addEntityToScene((*i)->_id));
		(*i)->setNode(Rcomp->getOgreNode());
		(*i)->AddComponent(Rcomp);
	}*/
}

void Scene::push(EntityC * e)
{
	entidades.push_back(e);
}

void Scene::setID(std::string id)
{
	_id = id;
}