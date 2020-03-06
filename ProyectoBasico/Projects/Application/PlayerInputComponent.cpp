#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent(EntityC* ent)
{
	_entity = ent;
}

PlayerInputComponent::~PlayerInputComponent()
{
}

bool PlayerInputComponent::keyPressed(const OIS::KeyEvent& ke)
{
	switch (ke.key) {
	case OIS::KC_W:
		break;
	case OIS::KC_A:
		break;
	case OIS::KC_S:
		break;
	case OIS::KC_D:
		break;
	}

	return false;
}

bool PlayerInputComponent::keyReleased(const OIS::KeyEvent& ke)
{
	return false;
}