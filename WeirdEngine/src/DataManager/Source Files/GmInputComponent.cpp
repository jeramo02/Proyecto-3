#include "GmInputComponent.h"

GmInputComponent::GmInputComponent() {}

GmInputComponent::~GmInputComponent() {}

void GmInputComponent::Init(GameManager* gm) {
	_gm = gm;
	listener = new GmInputListener(this);
}

void GmInputComponent::Q_Key()
{
	if (_playing) {
		//_gm->popScene();
		_playing = false;
	}
	else {
		_playing = true;
		//_gm->pushScene(_gm->getGamePlay());
	}
}

void GmInputComponent::Esc_Key()
{
	_state = true;
}

void GmInputComponent::Left_Mouse(float x, float y)
{

	_gm->send(this, )
	//llamar a la funcion onClick de los botones
}


