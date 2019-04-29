#include "entity.h"

Entity::Entity() {
	this->entity_id = 0;
	this->entity_name = "entity";
	this->active = true;
}

Entity::Entity(u32 id, const str name, bool active) {
	this->entity_id = id;
	this->entity_name = name;
	this->active = active;
}

Entity::~Entity() {	
	delete[] this->entity_name;		//check this?
	this->entity_id = 0;
}

void Entity::update() {
	cout << "Updating..." << endl;
}

void Entity::render() {
	cout << "Rendering entity..." << endl;
}

void Entity::tick() {
	cout << "Ticking...but this is private" << endl;
}

