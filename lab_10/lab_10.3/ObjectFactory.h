#pragma once
#include <map>
#include "GameObject.h"
#include "Stone.h"
#include "Chest.h"
#include "Merchant.h"
#include "Civilian.h"
#include "Player.h"

class ObjectFactory {
	map<string, GameObject*> objects;

	void addObjectType(GameObject* obj);

public:
	ObjectFactory();
	~ObjectFactory();

	GameObject* create(const char* typeName);
};

ObjectFactory::ObjectFactory() {
	addObjectType(new Stone());
	addObjectType(new Chest());
	addObjectType(new Merchant());
	addObjectType(new Civilian());
	addObjectType(new Player());
}

ObjectFactory::~ObjectFactory() {
	for (map<string, GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it) {
		delete it->second;
	}
	objects.clear();
}

void ObjectFactory::addObjectType(GameObject* obj) {
	objects.try_emplace(obj->getType(), obj);
}

GameObject* ObjectFactory::create(const char* typeName) {
	map<string, GameObject*>::iterator it = objects.find(typeName);

	if (it == objects.end()) {
		return nullptr;
	}

	return it->second->clone();
}